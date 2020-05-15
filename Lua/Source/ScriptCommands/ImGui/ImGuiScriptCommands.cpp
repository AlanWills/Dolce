#include "ScriptCommands/ImGui/ImGuiScriptCommands.h"
#include "sol/sol.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"
#include "imgui/DefaultInput.h"


namespace Dolce::Lua::ImGui::ScriptCommands
{
  namespace Internals
  {
    //------------------------------------------------------------------------------------------------
    template <typename T>
    std::tuple<T, bool> input(const std::string& label, T value)
    {
      bool result = Dolce::input(label, value);
      return std::make_tuple(value, result);
    }

    //------------------------------------------------------------------------------------------------
    bool button(const std::string& label)
    {
      return ::ImGui::Button(label.c_str());
    }

    //------------------------------------------------------------------------------------------------
    bool treeNode(const std::string& label)
    {
      return ::ImGui::TreeNode(label.c_str());
    }

    //------------------------------------------------------------------------------------------------
    bool beginCombo(const std::string& label, const std::string& preview)
    {
      return ::ImGui::BeginCombo(label.c_str(), preview.c_str());
    }

    //------------------------------------------------------------------------------------------------
    std::tuple<bool, bool> selectable(const std::string& label, bool isSelected)
    {
      bool result = ::ImGui::Selectable(label.c_str(), &isSelected);
      return std::make_tuple(isSelected, result);
    }
  }

  //------------------------------------------------------------------------------------------------
  void initialize(sol::state& state)
  {
    state.create_named_table(
      "ImGui",
      "text", &::ImGui::Text,
      "inputInt", &Internals::input<int>,
      "inputUInt", &Internals::input<unsigned int>,
      "inputFloat", &Internals::input<float>,
      "checkbox", &Internals::input<bool>,
      "button", &Internals::button,
      "treeNode", &Internals::treeNode,
      "treePop", &::ImGui::TreePop,
      "beginCombo", &Internals::beginCombo,
      "endCombo", &::ImGui::EndCombo,
      "selectable", &Internals::selectable);
  }
}