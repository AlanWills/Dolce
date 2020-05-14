#pragma once

#include "Dolce/IDolce.h"
#include "Dolce/DolceWindow.h"

struct GLFWwindow;


namespace Dolce
{
  class Dolce : public IDolce
  {
    public:
      Dolce(GLFWwindow* window);
      Dolce(const Dolce&) = delete;
      Dolce(Dolce&&) = delete;
      ~Dolce() override;

      Dolce& operator=(const Dolce&) = delete;
      Dolce& operator=(Dolce&&) = delete;
     
      bool isEnabled() const override;
      void setEnabled(bool isEnabled) override;

      bool hasKeyboardFocus() const override;
      bool hasMouseFocus() const override;

      template <typename T>
      observer_ptr<T> addWindow(std::unique_ptr<T>&& window);
      observer_ptr<DolceWindow> addWindow(std::unique_ptr<DolceWindow>&& window) override;
      void removeWindow(const std::string& windowName) override;

      observer_ptr<DolceWindow> findWindow(const std::string& windowName) const override;
      std::vector<std::string> getOpenWindows() const override;

      void update(float /*elapsedGameTime*/) override {}
      void render() override;

    private:
      using Windows = std::vector<std::unique_ptr<DolceWindow>>;

      bool m_enabled;
      Windows m_windows;
  };

  //------------------------------------------------------------------------------------------------
  template <typename T>
  observer_ptr<T> Dolce::addWindow(std::unique_ptr<T>&& window)
  {
    return static_cast<observer_ptr<T>>(addWindow(std::move(std::unique_ptr<DolceWindow>(window.release()))));
  }
}