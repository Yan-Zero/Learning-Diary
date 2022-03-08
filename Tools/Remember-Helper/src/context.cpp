#include "../include/Context.h"

using s = std::string;
using vs = std::vector<s>;

RememberData::RememberData(s &ID) :
  ID(ID)
{
  auto temp = time(nullptr);
  this->Time = {
    .Year = localtime(&temp)->tm_year + 1900,
    .Month = static_cast<char>(localtime(&temp)->tm_mon + 1),
    .Day = static_cast<char>(localtime(&temp)->tm_mday),
    .Hour = static_cast<char>(localtime(&temp)->tm_hour)
  };
};