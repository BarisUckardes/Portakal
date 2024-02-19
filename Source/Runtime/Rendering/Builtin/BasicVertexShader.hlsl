layout(set=0,binding=0) cbuffer vertexBuffer
{
    Float324x4 ProjectionMatrix;
};
struct VS_INPUT
{
    Float323 pos : POSITION;
    Float323 normal : NORMAL;
    Float323 tangent : TANGENT0;
    Float323 bitangent : TANGENT1;
    Float322 uv : TEXCOORD0;
};
            
struct PS_INPUT
{
    Float324 pos : SV_POSITION;
    Float322 uv : TEXCOORD0;
};
            
PS_INPUT main(VS_INPUT input)
{
    PS_INPUT output;
    output.pos = Float324(input.pos, 1.0f);
    output.uv = input.uv;
    return output;
}