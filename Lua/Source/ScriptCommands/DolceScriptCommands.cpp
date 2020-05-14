#include "ScriptCommands/Dolce/DolceScriptCommands.h"
#include "ScriptCommands/ImGui/ImGuiScriptCommands.h"
#include "Lua/LuaState.h"
#include "Dolce/Windows/LuaDolceWindow.h"
#include "Dolce/IDolce.h"

namespace Dolce::Lua::ScriptCommands
{
  namespace Internals
  {
    void addWindow(IDolce& dolce, const std::string& windowName, sol::table windowTable)
    {
      dolce.addWindow(std::make_unique<::Dolce::LuaDolceWindow>(windowName, windowTable));
    }
  }

  //------------------------------------------------------------------------------------------------
  void initialize(sol::state& state, IDolce& dolce)
  {
    ImGui::ScriptCommands::initialize(state);

    auto dolceUserType = state.new_usertype<IDolce>(
      "Dolce",
      "instance", sol::make_object(state.lua_state(), &dolce),
      "addWindow", &Internals::addWindow,
      "removeWindow", &IDolce::removeWindow);

    Celeste::Lua::LuaState::requireModule("Debug.DolceWindows");
  }
}