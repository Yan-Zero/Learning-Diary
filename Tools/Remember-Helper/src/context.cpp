#include "Context.hpp"

using s = std::string;
using vs = std::vector<s>;

RememberData::~RememberData()
{
  for(auto &i : *this->Context)
    delete i;
  delete this->Context;
}

RememberData::RememberData(s &ID)
{
  this->ID = ID;
  auto temp = time(nullptr);
  tm _tm;
  localtime_s(&_tm, &temp);
  this->Time = {
    _tm.tm_year + 1900,
    static_cast<char>(_tm.tm_mon + 1),
    static_cast<char>(_tm.tm_mday),
    static_cast<char>(_tm.tm_hour)
  };
};

RememberData::RememberData(s &ID, vs &content) :
  RememberData(ID)
{
  for (auto &i : content)
    this->Context->push_back(new s(i));
};

RememberData::RememberData(s &ID, vs &content, int count) :
  RememberData(ID, content)
{
  this->Count = count;
};

RememberData::RememberData(s &ID, vs &content, int count, bool remembered) :
  RememberData(ID, content, count)
{
  this->remembered = remembered;
};

RememberData::RememberData(s &ID, vs &content, int count, bool remembered, RTime Time) :
  RememberData(ID, content, count, remembered)
{
  this->Time = Time;
};

ChinesePoem::~ChinesePoem()
{
  delete this->DName;
}

ChinesePoem::ChinesePoem(s &ID, vs &content, int count, bool remembered, RTime Time, s &author) :
  RememberData(ID, content, count, remembered, Time)
{
  this->Author = author;
};

ChinesePoem::ChinesePoem(s &ID, vs &content, int count, bool remembered, RTime Time, s &author, s &title) :
  ChinesePoem(ID, content, count, remembered, Time, author)
{
  this->DName = new s(title);
};