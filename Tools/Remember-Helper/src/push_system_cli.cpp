#include "push_system.hpp"
#include "push_system_toast.cpp"

PushSystem::PushSystem()
{
}
PushSystem::~PushSystem()
{
  // for(auto &item : *this->m_depository)
  //   delete item;
  delete this->m_depository;
  // for(auto &item : *this->m_review)
  //   delete item;
  delete this->m_review;
}
void PushSystem::Load(std::vector<RememberData*> &array)
{
  m_depository->clear();
  m_depository->reserve(array.size());
  for (auto &data : array)
    m_depository->push_back(data);
  m_index = 0;
  m_rest = cap;
}
void PushSystem::Load(std::vector<RememberData> &array)
{
  this->m_depository->clear();
  this->m_depository->reserve(array.size());
  for (auto &data : array)
    this->m_depository->push_back(&data);
  this->m_index = 0;
  this->m_rest = this->cap;
}
void PushSystem::Next()
{
  // if the rest is 0, then we need to review or continue to learn //
  if (m_rest == 0)
  {
    review = !review;
    if(type == PSType::RandomReview)
      m_rest = review ? this->Random(static_cast<size_t>(1), cap) : cap;
    else
      m_rest = cap;
  }

  m_rest--;
  // get the data from review or error list //
  if(review)
  {
    size_t total_count = m_review->size();
    if(total_count == 0)
      return;
    auto index = this->Random(static_cast<size_t>(0), total_count - 1);
    auto it = m_review->begin();
    std::advance(it, index);

    return;
  }

  if (m_index >= m_depository->size())
  {
    m_index = m_depository->size();
    do
    {
      --m_index;
      std::swap(m_depository[m_index], m_depository[Random(static_cast<size_t>(0), m_index)]);
    } while (m_index);
  }
  this->Show(this->m_index);
  m_index++;
}

#ifndef _USE_TOAST
#include <iostream>

void EW_Show(EnglishWord &data, PushSystem &PS)
{
}

void CP_Show(ChinesePoem &data, PushSystem &PS)
{

}

void NONE_Show(RememberData &data, PushSystem &PS)
{

}

void ERROR_Show(std::string &message, PushSystem &PS)
{

}

#endif

void PushSystem::Show(size_t index)
{
  Show(this->m_depository->at(index));
}

void PushSystem::Show(RememberData *data)
{
  switch (data->Type)
  {
  case RememberData::CType::EnglishWord:
    EW_Show(*(EnglishWord*)data, *this);
    break;
  case RememberData::CType::ChinesePoem:
    CP_Show(*(ChinesePoem*)data, *this);
    break;
  case RememberData::CType::None:
    NONE_Show(*data, *this);
    break;
  default:
    ERROR_Show(std::string("Unknown data type"), *this);
    break;
  }
}