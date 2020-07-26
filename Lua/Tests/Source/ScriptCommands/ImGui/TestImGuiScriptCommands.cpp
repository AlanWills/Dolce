#include "TestUtils/TestUtils.h"
#include "TestUtils/Assert/LuaAssert.h"
#include "Lua/LuaState.h"
#include "ScriptCommands/ImGui/ImGuiScriptCommands.h"
#include "Dolce/Dolce.h"

using LuaState = Celeste::Lua::LuaState;


namespace TestDolceLua
{
  BASE_TEST_CLASS(TestImGuiScriptCommands)

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
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_text_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["text"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_inputInt_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["inputInt"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_inputUInt_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["inputUInt"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_inputFloat_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["inputFloat"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_inputText_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["inputText"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_checkbox_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["checkbox"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_button_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["button"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_treeNode_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["treeNode"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_treePop_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["treePop"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_beginCombo_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["beginCombo"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_endCombo_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["endCombo"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_selectable_ToImGuiTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Lua::ImGui::ScriptCommands::initialize(state);

    Assert::IsTrue(state["ImGui"]["selectable"].valid());
  }

#pragma endregion

  };
}