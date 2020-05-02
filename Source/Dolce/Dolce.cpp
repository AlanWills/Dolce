#include "Dolce/Dolce.h"
#include "Platform/Platform.h"
#include "GLFW/glfw3.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include <algorithm>


namespace Dolce
{
  //------------------------------------------------------------------------------------------------
  Dolce::Dolce(GLFWwindow* window) :
    m_enabled(false),
    m_windows()
  {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Set up ImGui configuration
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
  }

  //------------------------------------------------------------------------------------------------
  Dolce::~Dolce()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }

  //------------------------------------------------------------------------------------------------
  bool Dolce::isEnabled() const
  {
    return m_enabled;
  }

  //------------------------------------------------------------------------------------------------
  void Dolce::setEnabled(bool isEnabled)
  {
    m_enabled = isEnabled;
  }

  //------------------------------------------------------------------------------------------------
  bool Dolce::hasKeyboardFocus() const
  {
    return ImGui::GetIO().WantCaptureKeyboard;
  }

  //------------------------------------------------------------------------------------------------
  bool Dolce::hasMouseFocus() const
  {
    return ImGui::GetIO().WantCaptureMouse;
  }

  //------------------------------------------------------------------------------------------------
  DolceWindow& Dolce::registerWindow(std::unique_ptr<DolceWindow>&& window)
  {
    m_windows.emplace_back(std::move(window));
    return *m_windows.back();
  }

  //------------------------------------------------------------------------------------------------
  observer_ptr<DolceWindow> Dolce::findWindow(const std::string& windowName) const
  {
    auto foundWindowIt = std::find_if(m_windows.begin(), m_windows.end(),
      [&windowName](const std::unique_ptr<DolceWindow>& window)
      {
        return window->getName() == windowName;
      });

    return foundWindowIt != m_windows.end() ? (*foundWindowIt).get() : nullptr;
  }

  //------------------------------------------------------------------------------------------------
  std::vector<std::string> Dolce::getOpenWindows() const
  {
    std::vector<std::string> openWindows;

    for (const auto& window : m_windows)
    {
      if (window->isOpen())
      {
        openWindows.push_back(window->getName());
      }
    }

    return openWindows;
  }

  //------------------------------------------------------------------------------------------------
  void Dolce::render()
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (ImGui::IsKeyPressed(GLFW_KEY_RIGHT_CONTROL, false))
    {
      setEnabled(!isEnabled());
    }

    if (m_enabled)
    {
      if (ImGui::Begin("Dolce", nullptr, ImGuiWindowFlags_MenuBar))
      {
        ImGui::DockSpace(ImGui::GetID("DolceDockSpace"));

        if (ImGui::BeginMenuBar())
        {
          if (ImGui::BeginMenu("Windows"))
          {
            for (const auto& window : m_windows)
            {
              bool windowOpen = window->isOpen();
              if (ImGui::MenuItem(window->getName().c_str(), nullptr, windowOpen, window->canOpen()))
              {
                if (windowOpen)
                {
                  window->close();
                }
                else
                {
                  window->open();
                }
              }
            }

            ImGui::EndMenu();
          }

          ImGui::EndMenuBar();
        }

        for (const auto& window : m_windows)
        {
          bool isWindowOpen = window->isOpen();
          if (isWindowOpen)
          {
            if (ImGui::Begin(window->getName().c_str(), &isWindowOpen, window->getWindowFlags()))
            {
              window->render();
            }

            if (!isWindowOpen)
            {
              // We have closed the window with the built in X button in ImGui
              // So we need to sync this with the window itself
              window->close();
            }

            ImGui::End();
          }
        }
      }

      ImGui::End();
    }

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }
}