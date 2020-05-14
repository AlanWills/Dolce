#pragma once

#include "CelesteStl/Memory/ObserverPtr.h"
#include "System/ISystem.h"

#include <vector>
#include <string>
#include <memory>


namespace Dolce
{
  class DolceWindow;

  class IDolce : public Celeste::System::ISystem
  {
    public:
      IDolce() = default;
      IDolce(const IDolce&) = delete;
      IDolce(IDolce&&) = delete;
      ~IDolce() override = default;

      IDolce& operator=(const IDolce&) = delete;
      IDolce& operator=(IDolce&&) = delete;

      virtual bool isEnabled() const = 0;
      virtual void setEnabled(bool isEnabled) = 0;

      virtual bool hasKeyboardFocus() const = 0;
      virtual bool hasMouseFocus() const = 0;

      virtual observer_ptr<DolceWindow> addWindow(std::unique_ptr<DolceWindow>&& window) = 0;
      virtual void removeWindow(const std::string& windowName) = 0;

      virtual observer_ptr<DolceWindow> findWindow(const std::string& windowName) const = 0;
      virtual std::vector<std::string> getOpenWindows() const = 0;

      virtual void render() = 0;
  };
}