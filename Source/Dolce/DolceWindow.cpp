#include "Dolce/DolceWindow.h"


namespace Dolce
{
  //------------------------------------------------------------------------------------------------
  DolceWindow::DolceWindow(const std::string& name) :
    m_name(name),
    m_open(false),
    m_windowFlags(ImGuiWindowFlags_None)
  {
  }
}