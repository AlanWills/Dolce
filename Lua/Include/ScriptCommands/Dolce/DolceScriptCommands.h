#pragma once


namespace sol
{
  class state;
}

namespace Dolce
{
  class IDolce;
}

namespace Dolce::Lua::ScriptCommands
{
  void initialize(sol::state& state, IDolce& dolce);
}