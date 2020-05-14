#include "ScriptCommands/ImGui/ImGuiScriptCommands.h"
#include "sol/sol.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"


namespace Dolce::Lua::ImGui::ScriptCommands
{
  namespace Internals
  {
    //------------------------------------------------------------------------------------------------
    std::tuple<bool, int> inputInt(const std::string& label, int value)
    {
      bool result = ::ImGui::InputInt(label.c_str(), &value);
      return std::make_tuple(result, value);
    }

    //------------------------------------------------------------------------------------------------
    std::tuple<bool, unsigned int> inputUInt(const std::string& label, unsigned int value)
    {
      int iValue = std::max(0, static_cast<int>(value));
      bool result = ::ImGui::InputInt(label.c_str(), &iValue);
      return std::make_tuple(result, static_cast<unsigned int>(std::max(0, iValue)));
    }

    //------------------------------------------------------------------------------------------------
    std::tuple<bool, float> inputFloat(const std::string& label, float value)
    {
      bool result = ::ImGui::InputFloat(label.c_str(), &value);
      return std::make_tuple(result, value);
    }

    //------------------------------------------------------------------------------------------------
    std::tuple<bool, bool> checkbox(const std::string& label, bool value)
    {
      bool result = ::ImGui::Checkbox(label.c_str(), &value);
      return std::make_tuple(result, value);
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
  }

  //------------------------------------------------------------------------------------------------
  void initialize(sol::state& state)
  {
    state.create_named_table(
      "ImGui",
      "text", &::ImGui::Text,
      "inputInt", &Internals::inputInt,
      "inputUInt", &Internals::inputUInt,
      "inputFloat", &Internals::inputFloat,
      "checkbox", &Internals::checkbox,
      "button", &Internals::button,
      "treeNode", &Internals::treeNode,
      "treePop", &::ImGui::TreePop);
  }
}