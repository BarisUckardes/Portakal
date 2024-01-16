#pragma once
#include <Runtime/Input/KeyboardKeys.h>
#include <Runtime/Input/MouseButtons.h>
#include <Runtime/Reflection/Reflection.h>
#include <imgui.h>

namespace Portakal
{
	class EDITOR_API ImGuiUtils
	{
	public:
		static ImGuiKey GetKeyboardKey(const KeyboardKeys key);
		static ImGuiMouseButton GetMouseButton(const MouseButtons button);

		template<typename T>
		static T EnumBox(const String& name,const T& value)
		{
			const Type* pType = typeof(T);
			const String previewText = pType->GetEnumName((Int64)value);
			const Array<EnumValue> enumValues = pType->GetEnums();
			EnumValue selectedValue;
			selectedValue.Value = (Int64)value;
			if (ImGui::BeginCombo(*name,*previewText))
			{
				for (const EnumValue& enumValue : enumValues)
				{
					if (ImGui::Selectable(*enumValue.Name))
					{
						selectedValue = enumValue;
						break;
					}
				}

				ImGui::EndCombo();
			}

			return (T)selectedValue.Value;
		}

	public:
		ImGuiUtils() = delete;
		~ImGuiUtils() = delete;
	};
}
