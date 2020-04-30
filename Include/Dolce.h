#pragma once

#include "DolceWindow.h"
#include "Memory/ObserverPtr.h"
#include "System/ISystem.h"

#include <vector>
#include <memory>

struct GLFWwindow;


namespace Dolce
{
  class Dolce : public Celeste::System::ISystem
  {
    public:
      Dolce(GLFWwindow* window);
      Dolce(const Dolce&) = delete;
      Dolce(Dolce&&) = delete;
      ~Dolce() override;

      Dolce& operator=(const Dolce&) = delete;
      Dolce& operator=(Dolce&&) = delete;
     
      bool isEnabled() const;
      void setEnabled(bool isEnabled);

      bool hasKeyboardFocus() const;
      bool hasMouseFocus() const;

      template <typename T>
      T& registerWindow(std::unique_ptr<T>&& window);
      DolceWindow& registerWindow(std::unique_ptr<DolceWindow>&& window);

      observer_ptr<DolceWindow> findWindow(const std::string& windowName) const;

      std::vector<std::string> getOpenWindows() const;

      void handleInput() override {}
      void update(float /*elapsedGameTime*/) override {}
      void render();

    private:
      using Windows = std::vector<std::unique_ptr<DolceWindow>>;

      bool m_enabled;
      Windows m_windows;
  };

  //------------------------------------------------------------------------------------------------
  template <typename T>
  T& Dolce::registerWindow(std::unique_ptr<T>&& window)
  {
    return static_cast<T&>(registerWindow(std::move(std::unique_ptr<DolceWindow>(window.release()))));
  }
}