#include "TestUtils/TestUtils.h"
#include "TestUtils/Assert/LuaAssert.h"
#include "Lua/LuaState.h"
#include "ScriptCommands/Dolce/DolceScriptCommands.h"
#include "Dolce/Dolce.h"
#include "GLFW/glfw3.h"

using LuaState = Celeste::Lua::LuaState;


namespace TestDolceLua
{
  void render() {}

  TEST_UTILS_TEST_CLASS(TestDolceScriptCommands)

  GLFWwindow* window;

  //------------------------------------------------------------------------------------------------
  void testInitialize()
  {
    glfwInit();
    window = glfwCreateWindow(1, 1, "", nullptr, nullptr);

    LuaState::instance()["Dolce"] = sol::nil;
    LuaState::instance()["ImGui"] = sol::nil;
    LuaState::instance()["package"]["loaded"]["Debug.DolceWindows"] = sol::nil;
    LuaState::instance().collect_garbage();
  }

  //------------------------------------------------------------------------------------------------
  void testCleanup()
  {
    glfwTerminate();
    if (window != nullptr)
    {
      glfwDestroyWindow(window);
    }

    LuaState::instance()["Dolce"] = sol::nil;
    LuaState::instance()["ImGui"] = sol::nil;
    LuaState::instance()["package"]["loaded"]["Debug.DolceWindows"] = sol::nil;
    LuaState::instance().collect_garbage();
  }

#pragma region Initialize Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_AddsDolceTable_ToGlobalTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    LuaAssert::IsTable(state["Dolce"]);
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_instance_ToDolceTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    Dolce::Lua::ScriptCommands::initialize(state, dolce);
    
    Assert::IsTrue(state["Dolce"]["instance"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Adds_addWindow_ToDolceTable)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    Assert::IsTrue(state["Dolce"]["addWindow"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_Loads_DebugDolceWindows_Module)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    Assert::IsTrue(state["package"].valid());
    Assert::IsTrue(state["package"]["loaded"].valid());
    Assert::IsTrue(state["package"]["loaded"]["Debug.DolceWindows"].valid());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_RegistersPerformanceDolceWindow)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    
    Assert::IsNull(dolce.findWindow("Performance"));

    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    Assert::IsNotNull(dolce.findWindow("Performance"));
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_RegistersInputDolceWindow)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);

    Assert::IsNull(dolce.findWindow("Input"));

    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    Assert::IsNotNull(dolce.findWindow("Input"));
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_RegistersWindowInfoWindow)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);

    Assert::IsNull(dolce.findWindow("Window Info"));

    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    Assert::IsNotNull(dolce.findWindow("Window Info"));
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_Initialize_InitializesImGuiScriptCommands)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    LuaAssert::IsTable(state["ImGui"]);
  }

#pragma endregion

#pragma region Instance Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_instance_ReturnsDolceInstance_InputtingIntoInitialize)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    Dolce::Dolce* result = state["Dolce"]["instance"].get<Dolce::Dolce*>();

    Assert::IsTrue(&dolce == result);
  }

#pragma endregion

#pragma region Register Window Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceScriptCommands_addWindow_AddsWindowToDolceInstance)
  {
    sol::state& state = LuaState::instance();
    Dolce::Dolce dolce(window);
    Dolce::IDolce& iDolce = dolce;
    Dolce::Lua::ScriptCommands::initialize(state, dolce);

    sol::table windowTable = state.create_table();
    windowTable["render"] = &render;

    auto result = state["Dolce"]["addWindow"].get<sol::protected_function>().call(iDolce, "Test Window", windowTable);

    LuaAssert::IsValid(result);
    Assert::IsNotNull(dolce.findWindow("Test Window"));
  }

#pragma endregion

  };
}