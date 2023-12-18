#include "VulkanPipeline.h"
#include <Runtime/Vulkan/Pipeline/VulkanPipelineUtils.h>
#include <Runtime/Vulkan/Device/VulkanDevice.h>
#include <Runtime/Vulkan/Shader/VulkanShader.h>
#include <Runtime/Vulkan/VulkanUtils.h>
#include <Runtime/Vulkan/Resource/VulkanResourceTableLayout.h>
#include <Runtime/Vulkan/Texture/VulkanTextureUtils.h>
#include <Runtime/Vulkan/Shader/VulkanShaderUtils.h>
#include <Runtime/Graphics/Texture/TextureUtils.h>
#include <Runtime/Vulkan/RenderPass/VulkanRenderPass.h>

namespace Portakal
{

    VulkanPipeline::VulkanPipeline(const GraphicsPipelineDesc& desc, VulkanDevice* pDevice) : Pipeline(desc), mLayout(VK_NULL_HANDLE), mPipeline(VK_NULL_HANDLE), mLogicalDevice(VK_NULL_HANDLE)
    {
        /**
        * Create shader stages
        */
        Array<VkPipelineShaderStageCreateInfo> shaderStageCreateInformation;
        for (uint32 shaderIndex = 0; shaderIndex < desc.GraphicsShaders.GetSize(); shaderIndex++)
        {
            const VulkanShader* pShader = (const VulkanShader*)desc.GraphicsShaders[shaderIndex].GetHeap();

            VkPipelineShaderStageCreateInfo createInfo = {};
            createInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            createInfo.pNext = nullptr;
            createInfo.module = pShader->GetVkShader();
            createInfo.pSpecializationInfo = nullptr;
            createInfo.stage = (VkShaderStageFlagBits)VulkanPipelineUtils::GetShaderStage(pShader->GetStage());

            shaderStageCreateInformation.Add(createInfo);
        }

        /**
        * Create input layout
        */
        Array<VkVertexInputBindingDescription> inputBindingDescriptions;
        Array<VkVertexInputAttributeDescription> inputAttributeDescriptions;
        for (uint32 bindingIndex = 0; bindingIndex < desc.InputLayout.Bindings.GetSize(); bindingIndex++)
        {
            const InputBinding& binding = desc.InputLayout.Bindings[bindingIndex];

            VkVertexInputBindingDescription vkBindingDescription = {};
            vkBindingDescription.inputRate = VulkanPipelineUtils::GetInputRate(binding.StepRate);
            vkBindingDescription.binding = bindingIndex;


            uint32 inputOffset = 0;
            for (uint32 attributeIndex = 0; attributeIndex < binding.Elements.GetSize(); attributeIndex++)
            {
                const InputElement& inputElement = binding.Elements[attributeIndex];

                VkVertexInputAttributeDescription vkAttributeDescription = {};
                vkAttributeDescription.binding = bindingIndex;
                vkAttributeDescription.format = VulkanTextureUtils::GetTextureFormat(inputElement.Format);
                vkAttributeDescription.location = attributeIndex;
                vkAttributeDescription.offset = inputOffset;

                inputAttributeDescriptions.Add(vkAttributeDescription);

                inputOffset += TextureUtils::GetFormatSize(inputElement.Format);
            }

            /**
            * Set stride
            */
            vkBindingDescription.stride = inputOffset;

            /**
            * Add binding desc
            */
            inputBindingDescriptions.Add(vkBindingDescription);
        }
        VkPipelineVertexInputStateCreateInfo inputStateCreateInfo = {};
        inputStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        inputStateCreateInfo.pNext = nullptr;
        inputStateCreateInfo.pVertexBindingDescriptions = inputBindingDescriptions.GetData();
        inputStateCreateInfo.vertexBindingDescriptionCount = inputBindingDescriptions.GetSize();
        inputStateCreateInfo.pVertexAttributeDescriptions = inputAttributeDescriptions.GetData();
        inputStateCreateInfo.vertexAttributeDescriptionCount = inputAttributeDescriptions.GetSize();

        /**
        * Create input assembly
        */
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyCreateInfo = {};
        inputAssemblyCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
        inputAssemblyCreateInfo.pNext = nullptr;
        inputAssemblyCreateInfo.primitiveRestartEnable = false;
        inputAssemblyCreateInfo.topology = VulkanPipelineUtils::GetTopology(desc.InputLayout.Topology);

        /**
        * Create viewport and scissors
        */
        VkViewport viewport = {};
        viewport.x = 0;
        viewport.y = 0;
        viewport.width = 0;
        viewport.height = 0;
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;

        VkRect2D scissor = {};
        scissor.offset = { 0,0 };
        scissor.extent = { 0,0 };

        VkPipelineViewportStateCreateInfo viewportStateCreateInfo = {};
        viewportStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
        viewportStateCreateInfo.pNext = nullptr;
        viewportStateCreateInfo.viewportCount = 1;
        viewportStateCreateInfo.scissorCount = 1;
        viewportStateCreateInfo.pViewports = &viewport;
        viewportStateCreateInfo.pScissors = &scissor;

        /**
        * Create rasterizer
        */
        VkPipelineRasterizationStateCreateInfo rasterizerStateCreateInfo = {};
        rasterizerStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
        rasterizerStateCreateInfo.pNext = nullptr;
        rasterizerStateCreateInfo.rasterizerDiscardEnable = false;
        rasterizerStateCreateInfo.polygonMode = VulkanPipelineUtils::GetPolygonMode(desc.RasterizerState.FillMode);
        rasterizerStateCreateInfo.lineWidth = 1.0f;
        rasterizerStateCreateInfo.cullMode = VulkanPipelineUtils::GetCullModes(desc.RasterizerState.CullFlags);
        rasterizerStateCreateInfo.frontFace = desc.RasterizerState.IsFrontCounterClockwise ? VK_FRONT_FACE_COUNTER_CLOCKWISE : VK_FRONT_FACE_CLOCKWISE;
        rasterizerStateCreateInfo.depthBiasEnable = desc.RasterizerState.DepthBiasEnabled;
        rasterizerStateCreateInfo.depthBiasConstantFactor = desc.RasterizerState.DepthBiasFactor;
        rasterizerStateCreateInfo.depthBiasClamp = desc.RasterizerState.DepthBiasClamp;
        rasterizerStateCreateInfo.depthBiasSlopeFactor = desc.RasterizerState.DepthBiasSlope;

        /**
        * Create multisample state
        */
        VkPipelineMultisampleStateCreateInfo multiSampleStateCreateInfo = {};
        multiSampleStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
        multiSampleStateCreateInfo.pNext = nullptr;
        multiSampleStateCreateInfo.sampleShadingEnable = desc.Multisample.bSampleShadingEnabled;
        multiSampleStateCreateInfo.rasterizationSamples = (VkSampleCountFlagBits)VulkanPipelineUtils::GetSampleFlags(desc.Multisample.Samples);
        multiSampleStateCreateInfo.minSampleShading = 1.0f;
        multiSampleStateCreateInfo.pSampleMask = nullptr;
        multiSampleStateCreateInfo.alphaToCoverageEnable = 0;
        multiSampleStateCreateInfo.alphaToOneEnable = 0;

        /**
        * Create depth stencil state
        */
        VkPipelineDepthStencilStateCreateInfo depthStencilStateCreateInfo = {};
        depthStencilStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
        depthStencilStateCreateInfo.pNext = nullptr;
        depthStencilStateCreateInfo.depthBoundsTestEnable = false;
        depthStencilStateCreateInfo.depthTestEnable = desc.DepthStencilState.bDepthTestEnabled;
        depthStencilStateCreateInfo.depthWriteEnable = desc.DepthStencilState.bDepthWriteEnabled;
        depthStencilStateCreateInfo.stencilTestEnable = desc.DepthStencilState.bStencilTestEnabled;
        depthStencilStateCreateInfo.front = VulkanPipelineUtils::GetStencilFaceState(desc.DepthStencilState.StencilFrontFace);
        depthStencilStateCreateInfo.back = VulkanPipelineUtils::GetStencilFaceState(desc.DepthStencilState.StencilBackFace);

        /**
        * Create blending state
        */
        VkPipelineColorBlendStateCreateInfo blendingStateCreateInfo = {};
        blendingStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
        blendingStateCreateInfo.logicOpEnable = desc.BlendState.bLogicOperationEnabled;
        blendingStateCreateInfo.logicOp = VulkanUtils::GetLogicOperation(desc.BlendState.LogicOperation);
        blendingStateCreateInfo.flags = VkPipelineColorBlendStateCreateFlags();
        blendingStateCreateInfo.blendConstants[0] = 1;
        blendingStateCreateInfo.blendConstants[1] = 1;
        blendingStateCreateInfo.blendConstants[2] = 1;
        blendingStateCreateInfo.blendConstants[3] = 1;

        Array<VkPipelineColorBlendAttachmentState> blendingAttachments;
        for (byte attachmentIndex = 0; attachmentIndex < desc.BlendState.Attachments.GetSize(); attachmentIndex++)
        {
            const BlendStateAttachment& attachment = desc.BlendState.Attachments[attachmentIndex];

            blendingAttachments.Add(VulkanPipelineUtils::GetBlendAttachmentState(attachment));
        }
        blendingStateCreateInfo.pAttachments = blendingAttachments.GetData();
        blendingStateCreateInfo.attachmentCount = blendingAttachments.GetSize();


        blendingStateCreateInfo.pNext = nullptr;

        /**
        * Create pipeline resource layout
        */
        Array<VkDescriptorSetLayout> descriptorSetLayouts;
        for (uint32 layoutIndex = 0; layoutIndex < desc.ResourceLayout.ResourceLayouts.GetSize(); layoutIndex++)
        {
            const VulkanResourceTableLayout* pLayout = (const VulkanResourceTableLayout*)desc.ResourceLayout.ResourceLayouts[layoutIndex];
            descriptorSetLayouts.Add(pLayout->GetVkSetLayout());
        }

        VkPipelineLayoutCreateInfo layoutCreateInfo = {};
        layoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        layoutCreateInfo.setLayoutCount = descriptorSetLayouts.GetSize();
        layoutCreateInfo.pSetLayouts = descriptorSetLayouts.GetData();
        layoutCreateInfo.pPushConstantRanges = nullptr;
        layoutCreateInfo.pushConstantRangeCount = 0;
        layoutCreateInfo.pNext = nullptr;

        DEV_ASSERT(vkCreatePipelineLayout(pDevice->GetVkLogicalDevice(), &layoutCreateInfo, nullptr, &mLayout) == VK_SUCCESS, "VulkanPipeline", "Failed to create pipeline layout!");


        /**
        * Get shader stage info
        */
        VkPipelineShaderStageCreateInfo vkShaderStageInfos[8];
        for (byte shaderIndex = 0; shaderIndex < desc.GraphicsShaders.GetSize(); shaderIndex++)
        {
            const VulkanShader* pShader = (const VulkanShader*)desc.GraphicsShaders[shaderIndex].GetHeap();

            VkPipelineShaderStageCreateInfo info = {};
            info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            info.module = pShader->GetVkShader();
            info.pSpecializationInfo = nullptr;
            info.pName = pShader->GetEntryPoint().GetSource();
            info.stage = (VkShaderStageFlagBits)VulkanShaderUtils::GetShaderFlags(pShader->GetStage());
            info.pNext = nullptr;

            vkShaderStageInfos[shaderIndex] = info;
        }

        //Create output state
        VkFormat colorAttachmentFormats[8];
        for (byte colorAttachmentIndex = 0; colorAttachmentIndex < desc.OutputMerger.ColorFormats.GetSize(); colorAttachmentIndex++)
        {
            colorAttachmentFormats[colorAttachmentIndex] = VulkanTextureUtils::GetTextureFormat(desc.OutputMerger.ColorFormats[colorAttachmentIndex]);
        }

        //Get render pass
        const VulkanRenderPass* pPass = (const VulkanRenderPass*)desc.pRenderPass.GetHeap();

        VkPipelineRenderingCreateInfoKHR renderingInfo = {};
        renderingInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO_KHR;
        renderingInfo.pNext = nullptr;
        renderingInfo.colorAttachmentCount = desc.OutputMerger.ColorFormats.GetSize();
        renderingInfo.pColorAttachmentFormats = colorAttachmentFormats;
        renderingInfo.depthAttachmentFormat = desc.OutputMerger.DepthStencilFormat != TextureFormat::None ? VulkanTextureUtils::GetTextureFormat(desc.OutputMerger.DepthStencilFormat) : VK_FORMAT_UNDEFINED;

        VkGraphicsPipelineCreateInfo pipelineCreateInfo = {};
        pipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
        pipelineCreateInfo.pNext = &renderingInfo;
        pipelineCreateInfo.stageCount = desc.GraphicsShaders.GetSize();
        pipelineCreateInfo.pStages = vkShaderStageInfos;
        pipelineCreateInfo.pVertexInputState = &inputStateCreateInfo;
        pipelineCreateInfo.pInputAssemblyState = &inputAssemblyCreateInfo;
        pipelineCreateInfo.pViewportState = &viewportStateCreateInfo;
        pipelineCreateInfo.pRasterizationState = &rasterizerStateCreateInfo;
        pipelineCreateInfo.pMultisampleState = &multiSampleStateCreateInfo;
        pipelineCreateInfo.pDepthStencilState = &depthStencilStateCreateInfo;
        pipelineCreateInfo.pColorBlendState = &blendingStateCreateInfo;
        pipelineCreateInfo.pDynamicState = nullptr;
        pipelineCreateInfo.layout = mLayout;
        pipelineCreateInfo.renderPass = pPass->GetVkRenderPass();
        pipelineCreateInfo.subpass = desc.SubpassIndex;
        pipelineCreateInfo.basePipelineHandle = VK_NULL_HANDLE;
        pipelineCreateInfo.basePipelineIndex = -1;

        DEV_ASSERT(vkCreateGraphicsPipelines(pDevice->GetVkLogicalDevice(), VK_NULL_HANDLE, 1, &pipelineCreateInfo, nullptr, &mPipeline) == VK_SUCCESS, "VulkanPipeline", "Failed to create graphics pipeline");

        mBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        mLogicalDevice = pDevice->GetVkLogicalDevice();
    }
    VulkanPipeline::VulkanPipeline(const ComputePipelineDesc& desc, VulkanDevice* pDevice) : Pipeline(desc),mBindPoint(VK_PIPELINE_BIND_POINT_GRAPHICS)
    {
        /**
        * Create shader info
        */
        VkPipelineShaderStageCreateInfo shaderStageInfo = {};
        shaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        shaderStageInfo.pNext = nullptr;
        shaderStageInfo.module = ((const VulkanShader*)desc.ComputeShader.GetHeap())->GetVkShader();
        shaderStageInfo.pName = "";
        shaderStageInfo.pSpecializationInfo = nullptr;
        shaderStageInfo.stage = VK_SHADER_STAGE_COMPUTE_BIT;

        /**
        * Create pipeline layout
        */
        VkDescriptorSetLayout vkSetLayouts[32];
        for (byte layoutIndex = 0; layoutIndex < desc.ResourceLayouts.GetSize(); layoutIndex++)
        {
            vkSetLayouts[layoutIndex] = ((const VulkanResourceTableLayout*)desc.ResourceLayouts[layoutIndex])->GetVkSetLayout();
        }
        VkPipelineLayoutCreateInfo layoutCreateInfo = {};
        layoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        layoutCreateInfo.setLayoutCount = desc.ResourceLayouts.GetSize();
        layoutCreateInfo.pSetLayouts = vkSetLayouts;
        layoutCreateInfo.pPushConstantRanges = nullptr;
        layoutCreateInfo.pushConstantRangeCount = 0;
        layoutCreateInfo.pNext = nullptr;

        DEV_ASSERT(vkCreatePipelineLayout(pDevice->GetVkLogicalDevice(), &layoutCreateInfo, nullptr, &mLayout) == VK_SUCCESS, "VulkanPipeline", "Failed to create pipeline layout!");

        /**
        * Create compute pipeline
        */
        VkComputePipelineCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
        createInfo.basePipelineHandle = VK_NULL_HANDLE;
        createInfo.basePipelineIndex = -1;
        createInfo.flags = VkPipelineCreateFlags();
        createInfo.layout = mLayout;
        createInfo.stage = shaderStageInfo;

        DEV_ASSERT(vkCreateComputePipelines(mLogicalDevice, VK_NULL_HANDLE, 1, &createInfo, nullptr, &mPipeline) == VK_SUCCESS, "VulkanPipeline", "Failed to create compute pipeline");
    }

    void VulkanPipeline::OnShutdown()
    {
        vkDestroyPipelineLayout(mLogicalDevice, mLayout, nullptr);
        vkDestroyPipeline(mLogicalDevice, mPipeline, nullptr);

        mLayout = VK_NULL_HANDLE;
        mPipeline = VK_NULL_HANDLE;
        mLogicalDevice = VK_NULL_HANDLE;
    }

}