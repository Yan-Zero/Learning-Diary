#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <string>
#include <vector>
#include <ctime>

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
  enum class CType {
    None,
    ChinesePoem,
    EnglishWord,
  };

  s ID;
  int Count = 0;
  bool remembered = false;
  CType Type = CType::None;
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
    RememberData(ID, content, count, remembered, Time) {
    this->Type = CType::ChinesePoem;
  };;
  ChinesePoem(s &ID, vs &content, int count, bool remembered) :
    RememberData(ID, content, count, remembered) {
    this->Type = CType::ChinesePoem;
  };;
  ChinesePoem(s &ID, vs &content, int count) :
    RememberData(ID, content, count) {
    this->Type = CType::ChinesePoem;
  };;
  ChinesePoem(s &ID, vs &content) :
    RememberData(ID, content) {
    this->Type = CType::ChinesePoem;
  };
  ChinesePoem(s &ID) :
    RememberData(ID) {
    this->Type = CType::ChinesePoem;
  };
  
  virtual ~ChinesePoem();
};

class EnglishWord : public RememberData
{
  using s = std::string;
  using vs = std::vector<s>;
public:
  EnglishWord(s &ID, vs &content, int count, bool remembered, RTime Time) :
    RememberData(ID, content, count, remembered, Time) {
    this->Type = CType::EnglishWord;
  };;
  EnglishWord(s &ID, vs &content, int count, bool remembered) :
    RememberData(ID, content, count, remembered) {
    this->Type = CType::EnglishWord;
  };;
  EnglishWord(s &ID, vs &content, int count) :
    RememberData(ID, content, count) {
    this->Type = CType::EnglishWord;
  };;
  EnglishWord(s &ID, vs &content) :
    RememberData(ID, content) {
    this->Type = CType::EnglishWord;
  };
  EnglishWord(s &ID) :
    RememberData(ID) {
    this->Type = CType::EnglishWord;
  };

  virtual ~EnglishWord() {};
}

#endif