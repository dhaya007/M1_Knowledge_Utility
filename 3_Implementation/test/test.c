#include "unity.h"
#include "reserve.h"

void setUp()
{

}
void tearDown()
{
  
}
void test_cancelticket(void)
{
    int cancel=1;
    TEST_ASSERT_EQUAL(1,cancel_ticket(cancel));
    
}

int main(void)
{
  UNITY_BEGIN();
  
  RUN_TEST(test_cancelticket);
  return UNITY_END();
}