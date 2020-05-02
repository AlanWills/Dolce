#pragma once

#include "imgui/imgui.h"

#include <string>


namespace Dolce
{
  class DolceWindow
  {
    public:
      DolceWindow(const std::string& name);
      DolceWindow(const DolceWindow&) = delete;
      DolceWindow(DolceWindow&&) = default;
      virtual ~DolceWindow() = default;

      DolceWindow& operator=(const DolceWindow&) = delete;
      DolceWindow& operator=(DolceWindow&&) = default;

      const std::string& getName() const { return m_name; }

      virtual bool canOpen() const { return true; }
      bool isOpen() const { return m_open; }
      void open() { m_open = true; }
      void close() { m_open = false; }

      ImGuiWindowFlags getWindowFlags() const { return m_windowFlags; }
      void setWindowFlags(ImGuiWindowFlags windowFlags) { m_windowFlags = windowFlags; }
      void addWindowFlag(ImGuiWindowFlags_ windowFlag) { m_windowFlags |= windowFlag; }
      void removeWindowFlag(ImGuiWindowFlags_ windowFlag) { m_windowFlags &= ~windowFlag; }

      virtual void render() = 0;

    private:
      std::string m_name;
      bool m_open;
      ImGuiWindowFlags m_windowFlags;
  };
}