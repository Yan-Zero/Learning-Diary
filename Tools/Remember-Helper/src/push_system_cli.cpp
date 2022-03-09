#include "push_system.hpp"
#include "push_system_toast.cpp"

PushSystem::PushSystem()
{
  this->m_depository = new std::vector<RememberData*>();
  this->m_review = new std::list<RememberData*>();
  this->m_error = new std::list<RememberData*>();
}
PushSystem::~PushSystem()
{
  // for(auto &item : *this->m_depository)
  //   delete item;
  delete this->m_depository;
  // for(auto &item : *this->m_review)
  //   delete item;
  delete this->m_review;
  delete this->m_error;
}
void PushSystem::Load(std::vector<RememberData*> &array)
{
  this->m_depository->clear();
  this->m_depository->reserve(array.size());
  for (auto &data : array)
    this->m_depository->push_back(data);
  this->m_index = 0;
  this->m_rest = this->cap;
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
  if (this->m_rest == 0)
  {
    this->review = !this->review;
    this->m_rest = this->review ? rand() % this->cap + 1 : this->cap;
  }
  
  if(this->review)
  {

    return;
  }

  this->m_rest--;
  this->m_index++;
  if (this->m_index >= this->m_depository->size())
    this->m_index = 0;
  
  this->Show(this->m_index);
  this->m_review->push_back(this->m_depository->at(this->m_index));
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