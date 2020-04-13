#include "TestUtils.h"
#include "Assert/Assert.h"
#include "Assert/NullAsserter.h"


namespace TestDolce
{
  //------------------------------------------------------------------------------------------------
  TEST_MODULE_INITIALIZE(TestDolce_Initialize)
  {
    // Issues with unique_ptrs over dll boundaries so have to do this in the test project
    Celeste::Assertion::setAsserter(std::make_unique<Celeste::NullAsserter>());
  }
}