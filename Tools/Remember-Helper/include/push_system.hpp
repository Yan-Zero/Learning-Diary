#ifndef PUSH_SYSTEM_H_
#define PUSH_SYSTEM_H_

#include "context.hpp"
#include <list>

class PushSystem
{
public:
  enum class PSType
  {
    // 随机复习 - Like 百词斩 //
    RandomReview,
    // 根据推送的个数复习 //
    ReviewByTimes,
    // 根据推送的时间复习 //
    ReviewByTime,
  };

  inline PushSystem(std::vector<RememberData*> &array) :
    PushSystem() { Load(array); };
  inline PushSystem(std::vector<RememberData> &array) :
    PushSystem() { Load(array); };
  PushSystem();
  ~PushSystem();

  void Load(std::vector<RememberData*> &array);
  void Load(std::vector<RememberData> &array);

  void Push(RememberData &context);
  void Next();

  void Show(size_t index);
  void Show(RememberData *context);

  PSType type = PSType::RandomReview;
private:
  std::vector<RememberData*> *m_depository = nullptr;
  std::list<RememberData*> *m_review = nullptr;
  std::list<RememberData*> *m_error = nullptr;
  size_t m_index = 0;
  size_t m_rest = 10;
  size_t cap = 10;
  bool review = false;
};

#endif