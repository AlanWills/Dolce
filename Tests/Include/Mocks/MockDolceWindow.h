#pragma once

#include "Dolce/DolceWindow.h"


namespace TestDolce
{
  class MockDolceWindow : public Dolce::DolceWindow
  {
    public:
      MockDolceWindow(const std::string& name) : Dolce::DolceWindow(name) {}
      MockDolceWindow(const MockDolceWindow&) = delete;
      MockDolceWindow(MockDolceWindow&&) = default;
      ~MockDolceWindow() override = default;

      MockDolceWindow& operator=(const MockDolceWindow&) = delete;
      MockDolceWindow& operator=(MockDolceWindow&&) = default;

      void render() override {}
  };
}