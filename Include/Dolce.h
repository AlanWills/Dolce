#pragma once

#include "DolceWindow.h"
#include "Memory/ObserverPtr.h"

#include <vector>
#include <memory>

struct GLFWwindow;


namespace Dolce
{
  class Dolce
  {
    public:
      Dolce(GLFWwindow* window);
      Dolce(const Dolce&) = delete;
      Dolce(Dolce&&) = delete;
      ~Dolce();

      Dolce& operator=(const Dolce&) = delete;
      Dolce& operator=(Dolce&&) = delete;
     
      bool isEnabled() const;
      void setEnabled(bool isEnabled);

      bool hasKeyboardFocus() const;
      bool hasMouseFocus() const;

      DolceWindow& registerWindow(std::unique_ptr<DolceWindow>&& window);
      observer_ptr<DolceWindow> findWindow(const std::string& windowName) const;

      std::vector<std::string> getOpenWindows() const;

      void render();

    private:
      using Windows = std::vector<std::unique_ptr<DolceWindow>>;

      bool m_enabled;
      Windows m_windows;
  };
}