#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "container.h"
#include <ring.h>


using std::cout;
using std::endl;
using ::can::common::datastructure::TestContainer;
using ::can::common::datastructure::Ring;

int main(int argc, char* argv[])
{
  // test assigment operation
  //Ring<int> val1;
  //Ring<int> val2;
  //val1 = val2;

  srand(time(NULL));

  TestContainer test;

  cout << "Now begin testing..." << endl;

  uint32_t user_id = 0;
  for ( int i = 0; i < 15; ++i )
  {
    user_id = rand() % 20;
    test.PushData(user_id);
    user_id = rand() % 20;
    test.RemoveData(user_id);
    user_id = rand() % 20;
    test.UpdateTime(user_id);
    sleep(1);
  }

  cout<< "-------------------------------------" << endl;
  cout<< " result: " << endl;
  test.PrintData();

  return 0;
}

