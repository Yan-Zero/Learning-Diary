#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <string>
#include <vector>
#include <ctime>

enum class ContextType {
  None,
  ChinesePoem,
  EnglishWord,
};

struct RTime {
  int Year = 0;
  char Month = 0;
  char Day = 0;
  char Hour = 0;
};

class RememberData
{
  using s = std::string;
  using vs = std::vector<s>;
public:
  s ID;
  int Count = 0;
  bool remembered = false;
  ContextType Type = ContextType::None;
  std::vector<s*> *Context = new std::vector<s*>();
  RTime Time;

  RememberData(s &ID, vs &content, int count, bool remembered, RTime Time);
  RememberData(s &ID, vs &content, int count, bool remembered);
  RememberData(s &ID, vs &content, int count);
  RememberData(s &ID, vs &content);
  RememberData(s &ID);

  void AddContent(s &content);
  void AddContent(char *content);

  virtual ~RememberData();
};

class ChinesePoem : public RememberData
{
  using s = std::string;
  using vs = std::vector<s>;
public:
  s Author = "佚名";
  s *DName = nullptr;

  ChinesePoem(s &ID, vs &content, int count, bool remembered, RTime Time, s &author, s &title);
  ChinesePoem(s &ID, vs &content, int count, bool remembered, RTime Time, s &author);

  ChinesePoem(s &ID, vs &content, int count, bool remembered, RTime Time) :
    RememberData(ID, content, count, remembered, Time) {};
  ChinesePoem(s &ID, vs &content, int count, bool remembered) :
    RememberData(ID, content, count, remembered) {};
  ChinesePoem(s &ID, vs &content, int count) :
    RememberData(ID, content, count) {};
  ChinesePoem(s &ID, vs &content) :
    RememberData(ID, content) {};
  ChinesePoem(s &ID) :
    RememberData(ID) {};
  
  virtual ~ChinesePoem();
};


#endif