#pragma once

#include "Dolce/DolceWindow.h"
#include "sol/sol.hpp"


namespace Dolce
{
  class LuaDolceWindow : public DolceWindow
  {
    public:
      LuaDolceWindow(const std::string& windowName, sol::table windowTable);

      void render() override;

    private:
      sol::table m_windowTable;
      sol::protected_function m_renderFunction;
  };
}