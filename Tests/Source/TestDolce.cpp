#include "TestUtils/TestUtils.h"
#include "Dolce/Dolce.h"
#include "GLFW/glfw3.h"

#include "Mocks/MockDolceWindow.h"


namespace TestDolce
{
  TEST_UTILS_TEST_CLASS(TestDolce)

  GLFWwindow* window;

  //------------------------------------------------------------------------------------------------
  void testInitialize()
  {
    glfwInit();
    window = glfwCreateWindow(1, 1, "", nullptr, nullptr);
  }

  //------------------------------------------------------------------------------------------------
  void testCleanup()
  {
    glfwTerminate();
    if (window != nullptr)
    {
      glfwDestroyWindow(window);
    }
  }

#pragma region Find Window Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(FindWindow_InputtingNonExistentWindowName_ReturnsNullptr)
  {
    Dolce::Dolce dolce(window);

    Assert::IsNull(dolce.findWindow("Test"));
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(FindWindow_InputtingExistentWindowName_ReturnsWindowPtr)
  {
    Dolce::Dolce dolce(window);
    dolce.registerWindow(std::make_unique<MockDolceWindow>("Test"));

    Assert::IsNotNull(dolce.findWindow("Test"));
  }

#pragma endregion

#pragma region Get Open Windows Tests

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(GetOpenWindows_NoWindowsRegistered_ReturnsEmptyList)
  {
    Dolce::Dolce dolce(window);

    Assert::IsTrue(dolce.getOpenWindows().empty());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(GetOpenWindows_NoOpenWindows_ReturnsEmptyList)
  {
    Dolce::Dolce dolce(window);
    dolce.registerWindow(std::make_unique<MockDolceWindow>("Test"));

    Assert::IsTrue(dolce.getOpenWindows().empty());
  }

  //------------------------------------------------------------------------------------------------
  TEST_METHOD(GetOpenWindows_OpenWindows_ReturnsListOfOpenWindowNames)
  {
    Dolce::Dolce dolce(window);
    dolce.registerWindow(std::make_unique<MockDolceWindow>("Test")).open();
    dolce.registerWindow(std::make_unique<MockDolceWindow>("Test2"));
    dolce.registerWindow(std::make_unique<MockDolceWindow>("Test3")).open();

    auto openWindows = dolce.getOpenWindows();

    Assert::AreEqual(static_cast<size_t>(2), openWindows.size());
    Assert::AreEqual("Test", openWindows[0].c_str());
    Assert::AreEqual("Test3", openWindows[1].c_str());
  }

#pragma endregion

  };
}