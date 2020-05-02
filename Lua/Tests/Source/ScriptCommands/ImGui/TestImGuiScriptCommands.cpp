#include "TestUtils/TestUtils.h"
#include "TestUtils/Assert/LuaAssert.h"
#include "Lua/LuaState.h"
#include "ScriptCommands/ImGui/ImGuiScriptCommands.h"
#include "Dolce/Dolce.h"

using LuaState = Celeste::Lua::LuaState;


namespace TestDolceLua
{
  TEST_UTILS_TEST_CLASS(TestImGuiScriptCommands)

  //------------------------------------------------------------------------------------------------
  void testInitialize()
  {
    LuaState::instance()["ImGui"] = sol::nil;
    LuaState::instance().collect_garbage();
  }

  //------------------------------------------------------------------------------------------------
  void testCleanup()
  {
    LuaState::instance()["ImGui"] = sol::nil;
    LuaState::instance().collect_garbage();
  }

#pragma region Initialize Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(ImGuiScriptCommands_Initialize_AddsImGuiTable_ToGlobalTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    LuaAssert::IsTable(state["ImGui"]);
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_Text_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["Text"].valid());
  }

#pragma endregion

  };
}