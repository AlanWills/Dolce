#pragma once

#include "Dolce/IDolce.h"


namespace Dolce
{
  class DolceWindow;

  class DolceDummy : public IDolce
  {
    public:
      DolceDummy() = default;
      DolceDummy(const DolceDummy&) = delete;
      DolceDummy(DolceDummy&&) = delete;
      ~DolceDummy() override = default;

      DolceDummy& operator=(const DolceDummy&) = delete;
      DolceDummy& operator=(DolceDummy&&) = delete;

      bool isEnabled() const override { return false; }
      void setEnabled(bool /*isEnabled*/) override {}

      bool hasKeyboardFocus() const override { return false; }
      bool hasMouseFocus() const override { return false; }

      observer_ptr<DolceWindow> addWindow(std::unique_ptr<DolceWindow>&& /*window*/) override { return nullptr; }
      void removeWindow(const std::string& /*windowName*/) override { }

      observer_ptr<DolceWindow> findWindow(const std::string& /*windowName*/) const override { return nullptr; }
      std::vector<std::string> getOpenWindows() const override { return {}; }

      void update(float /*elapsedGameTime*/) override {}
      void render() override {}
  };
}