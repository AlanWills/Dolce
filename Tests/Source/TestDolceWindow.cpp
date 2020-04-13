#include "TestUtils.h"

#include "Mocks/MockDolceWindow.h"


namespace TestDolce
{
  TEST_UTILS_TEST_CLASS(TestDolceWindow)

#pragma region Constructor Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_Constructor_SetsNameToInputtedName)
  {
    MockDolceWindow dolceWindow("Test");

    Assert::AreEqual("Test", dolceWindow.getName().c_str());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_Constructor_SetsWindowToClosed)
  {
    MockDolceWindow dolceWindow("Test");

    Assert::IsFalse(dolceWindow.isOpen());
  }

#pragma endregion

#pragma region Open Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_Open_NotOpen_SetsIsOpenToTrue)
  {
    MockDolceWindow dolceWindow("Test");
    
    Assert::IsFalse(dolceWindow.isOpen());

    dolceWindow.open();

    Assert::IsTrue(dolceWindow.isOpen());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_Open_AlreadyOpen_SetsIsOpenToTrue)
  {
    MockDolceWindow dolceWindow("Test");
    dolceWindow.open();

    Assert::IsTrue(dolceWindow.isOpen());

    dolceWindow.open();

    Assert::IsTrue(dolceWindow.isOpen());
  }

#pragma endregion

#pragma region Close Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_Close_NotClosed_SetsIsOpenToFalse)
  {
    MockDolceWindow dolceWindow("Test");
    dolceWindow.open();

    Assert::IsTrue(dolceWindow.isOpen());

    dolceWindow.close();

    Assert::IsFalse(dolceWindow.isOpen());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_Close_AlreadyClosed_SetsIsOpenToFalse)
  {
    MockDolceWindow dolceWindow("Test");

    Assert::IsFalse(dolceWindow.isOpen());

    dolceWindow.close();

    Assert::IsFalse(dolceWindow.isOpen());
  }

#pragma endregion

#pragma region Set Window Flags Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_SetWindowFlags_SetsWindowFlags_ToInputtedValue)
  {
    MockDolceWindow dolceWindow("Test");

    Assert::IsTrue(ImGuiWindowFlags_None == dolceWindow.getWindowFlags());

    dolceWindow.setWindowFlags(ImGuiWindowFlags_AlwaysAutoResize);

    Assert::IsTrue(ImGuiWindowFlags_AlwaysAutoResize == dolceWindow.getWindowFlags());
  }

#pragma endregion

#pragma region Add Window Flag Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_AddWindowFlag_WindowFlagNotSet_AddsWindowFlag)
  {
    MockDolceWindow dolceWindow("Test");

    Assert::IsTrue(ImGuiWindowFlags_None == dolceWindow.getWindowFlags());

    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysAutoResize);

    Assert::IsTrue(ImGuiWindowFlags_AlwaysAutoResize == dolceWindow.getWindowFlags());

    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    Assert::IsTrue((ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_AlwaysHorizontalScrollbar )
      == dolceWindow.getWindowFlags());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_AddWindowFlag_WindowFlagAlreadySet_AddsWindowFlag)
  {
    MockDolceWindow dolceWindow("Test");

    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysAutoResize);
    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    Assert::IsTrue((ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_AlwaysHorizontalScrollbar)
      == dolceWindow.getWindowFlags());

    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysAutoResize);
    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    Assert::IsTrue((ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_AlwaysHorizontalScrollbar)
      == dolceWindow.getWindowFlags());
  }

#pragma endregion

#pragma region Remove Window Flag Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_RemoveWindowFlag_WindowFlagNotSet_RemovesWindowFlag)
  {
    MockDolceWindow dolceWindow("Test");

    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysAutoResize);
    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    Assert::IsTrue((ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_AlwaysHorizontalScrollbar)
      == dolceWindow.getWindowFlags());

    dolceWindow.removeWindowFlag(ImGuiWindowFlags_HorizontalScrollbar);

    Assert::IsTrue((ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_AlwaysHorizontalScrollbar)
      == dolceWindow.getWindowFlags());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(DolceWindow_RemoveWindowFlag_WindowFlagSet_RemovesWindowFlag)
  {
    MockDolceWindow dolceWindow("Test");

    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysAutoResize);
    dolceWindow.addWindowFlag(ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    Assert::IsTrue((ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_AlwaysHorizontalScrollbar)
      == dolceWindow.getWindowFlags());

    dolceWindow.removeWindowFlag(ImGuiWindowFlags_AlwaysAutoResize);

    Assert::IsTrue(ImGuiWindowFlags_AlwaysHorizontalScrollbar == dolceWindow.getWindowFlags());

    dolceWindow.removeWindowFlag(ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    Assert::IsTrue(ImGuiWindowFlags_None == dolceWindow.getWindowFlags());
  }

#pragma endregion

  };
}