#ifndef TING_COMMON_TEST_CONTAINER_H_
#define TING_COMMON_TEST_CONTAINER_H_
#include <map>
#include <time.h>
#include <inttypes.h>
#include <iostream>
#include <ring.h>

using std::cout;
using std::endl;

namespace can { namespace common { namespace datastructure {

class TestData : public Ring<TestData>
{
public:
  uint32_t user_id;
  time_t   time_stamp;
};


class TestContainer
{
public:

  TestContainer() { }
  ~TestContainer();

  void PushData(uint32_t user);

  void RemoveData(uint32_t user);

  void UpdateTime(uint32_t user);

  void PrintData();

private:

  TestData head;
  std::map<uint32_t, TestData*> user2data;

};

}}} // can::common::datastructure

#endif // TING_COMMON_TEST_CONTAINER_H_

