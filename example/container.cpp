#include "container.h"

namespace can { namespace common { namespace datastructure {

TestContainer::~TestContainer()
{
  TestData* td = head.previous();
  while (td != &head)
  {
    td->Remove();
    delete td;
    td = head.previous();
  }
  user2data.clear();
}

void TestContainer::PushData(uint32_t user)
{
  std::map<uint32_t, TestData*>::iterator it = user2data.find(user);
  if (it != user2data.end())
  {
    TestData* td = it->second;
    td->Remove();
    td->time_stamp = time(NULL); // update time
    head.Append(td);
    cout << "Update user: " << td->user_id << " time stamp: " << td->time_stamp << endl;
  }
  else
  {
    TestData* td   = new TestData;
    td->user_id    = user;
    td->time_stamp = time(NULL);
    head.Append(td);
    user2data.insert(std::make_pair(user, td));
    cout << "push a new data, user: " << user << " time stamp: "<< td->time_stamp <<endl;
  }
}

void TestContainer::RemoveData(uint32_t user)
{
  std::map<uint32_t, TestData*>::iterator it = user2data.find(user);
  if (it != user2data.end())
  {
    cout << "Remove user: " << it->first << " time stamp: " << it->second->time_stamp << endl;
    TestData* td = it->second;
    user2data.erase(it);
    td->Remove();
    delete td;
  }
  else
  {
    cout<< "Not find user: " << user << " to remove" <<endl;
  }
}

void TestContainer::UpdateTime(uint32_t user)
{
  std::map<uint32_t, TestData*>::iterator it = user2data.find(user);
  if (it != user2data.end())
  {
    TestData* td = it->second;
    td->Remove();
    td->time_stamp = time(NULL); // update time
    head.Append(td);
    cout << "Update user: " << td->user_id << " time stamp: " << td->time_stamp << endl;
  }
  else
  {
    cout<< "Not find user: " << user << " to update" <<endl;
  }
}

void TestContainer::PrintData()
{
  TestData* td = head.previous();
  while (td != &head)
  {
    cout << "user: " << td->user_id << " time stamp: " << td->time_stamp << endl;
    td = td->previous();
  }
}

}}} // can::common::datastructure

