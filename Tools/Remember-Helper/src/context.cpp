#include "context.hpp"

using s = std::string;
using vs = std::vector<s>;

RememberData::~RememberData()
{
  for (auto &i : *this->Context)
    delete i;
  delete this->Context;
}

RememberData::RememberData(s &ID)
{
  this->ID = ID;
  auto temp = time(nullptr);
  tm _tm;
  localtime_s(&_tm, &temp);
  this->User = {
      0,
      false,
      {_tm.tm_year + 1900,
       static_cast<char>(_tm.tm_mon + 1),
       static_cast<char>(_tm.tm_mday),
       static_cast<char>(_tm.tm_hour)}};
};

RememberData::RememberData(s &ID, vs &context) : 
  RememberData(ID)
{
  for (auto &i : context)
    this->Context->push_back(new s(i));
};

RememberData::RememberData(s &ID, vs &context, int count) : 
  RememberData(ID, context)
{
  this->User.Count = count;
};

RememberData::RememberData(s &ID, vs &context, int count, bool remembered) : 
  RememberData(ID, context, count)
{
  this->User.Remembered = remembered;
};

RememberData::RememberData(s &ID, vs &context, int count, bool remembered, RTime Time) : 
  RememberData(ID, context, count, remembered)
{
  this->User.Time = Time;
};

ChinesePoem::~ChinesePoem()
{
  delete this->DName;
}

ChinesePoem::ChinesePoem(s &ID, vs &context, int count, bool remembered, RTime Time, s &author) : 
  RememberData(ID, context, count, remembered, Time)
{
  this->Author = author;
};

ChinesePoem::ChinesePoem(s &ID, vs &context, int count, bool remembered, RTime Time, s &author, s &title) : 
  ChinesePoem(ID, context, count, remembered, Time, author)
{
  this->DName = new s(title);
};

EnglishWord::EnglishWord(s &ID, vs &context) : 
  EnglishWord(ID)
{
  this->Type = CType::EnglishWord;
  while (context.size() % 4)
    context.push_back("NONE");
  for (auto &i : context)
    this->Context->push_back(new s(i));
};