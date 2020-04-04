#pragma once

#include <string>


namespace Dolce
{
  class DolceWindow
  {
    public:
      DolceWindow(const std::string& name);
      DolceWindow(const DolceWindow&) = delete;
      DolceWindow(DolceWindow&&) = default;
      virtual ~DolceWindow() = default;

      DolceWindow& operator=(const DolceWindow&) = delete;
      DolceWindow& operator=(DolceWindow&&) = default;

      const std::string& getName() const { return m_name; }

      bool isOpen() const { return m_open; }
      void open() { m_open = true; }
      void close() { m_open = false; }

      virtual void render() = 0;

    private:
      std::string m_name;
      bool m_open;
  };
}