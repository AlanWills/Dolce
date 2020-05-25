#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"
#include "glm/glm.hpp"

#include <string>


namespace Dolce
{
  //------------------------------------------------------------------------------------------------
  bool input(const std::string& key, bool& value)
  {
    return ImGui::Checkbox(key.c_str(), &value);
  }

  //------------------------------------------------------------------------------------------------
  bool input(const std::string& key, int& value)
  {
    return ImGui::InputInt(key.c_str(), &value);
  }

  //------------------------------------------------------------------------------------------------
  bool input(const std::string& key, unsigned int& value)
  {
    int iValue = static_cast<int>(value);
    if (input(key, iValue))
    {
      value = static_cast<unsigned int>(iValue);
      return true;
    }

    return false;
  }

  //------------------------------------------------------------------------------------------------
  bool input(const std::string& key, float& value)
  {
    return ImGui::InputFloat(key.c_str(), &value);
  }

  //------------------------------------------------------------------------------------------------
  bool input(const std::string& key, std::string& value)
  {
    return ImGui::InputText(key.c_str(), &value);
  }

  //------------------------------------------------------------------------------------------------
  bool input(const std::string& key, glm::vec3& value)
  {
    ImGui::Text(key.c_str());

    if (input("x", value.x))
    {
      return true;
    }
    else if (input("y", value.y))
    {
      return true;
    }
    else if (input("z", value.z))
    {
      return true;
    }

    return false;
  }
}