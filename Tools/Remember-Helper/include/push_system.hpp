#ifndef PUSH_SYSTEM_H_
#define PUSH_SYSTEM_H_

#include "context.hpp"
#include <random>
#include <utility>

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
  struct ReviewData
  {
    RememberData *data; 
    int shown_time = 0;
    int error_times = 0;
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
  
  template<typename T = int>
  T Random(T min, T max)
  {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(this->m_engine);
  };

  PSType type = PSType::RandomReview;
private:
  std::vector<RememberData*> *m_depository = new std::vector<RememberData*>();
  std::vector<ReviewData> *m_review = new std::vector<ReviewData>();
  size_t m_index = 0;
  size_t m_rest = 10;
  size_t cap = 10;
  bool review = false;

  std::default_random_engine m_rd = std::default_random_engine();
};

#endif