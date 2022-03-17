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

  struct UserData
  {
    int Count = 0;
    bool Remembered = false;
    RTime Time;
  };

  s ID;
  CType Type = CType::None;
  std::vector<s*> *Context = new std::vector<s*>();
  UserData User;

  RememberData(s &ID, vs &context, int count, bool remembered, RTime Time);
  RememberData(s &ID, vs &context, int count, bool remembered);
  RememberData(s &ID, vs &context, int count);
  RememberData(s &ID, vs &context);
  RememberData(s &ID);

  void AddContext(s &context);
  void AddContext(char *context);

  virtual ~RememberData();
};

class ChinesePoem : public RememberData
{
  using s = std::string;
  using vs = std::vector<s>;
public:
  s Author = "佚名";
  s *DName = nullptr;

  ChinesePoem(s &ID, vs &context, int count, bool remembered, RTime Time, s &author, s &title);
  ChinesePoem(s &ID, vs &context, int count, bool remembered, RTime Time, s &author);

  ChinesePoem(s &ID, vs &context, int count, bool remembered, RTime Time) :
    RememberData(ID, context, count, remembered, Time) {
    this->Type = CType::ChinesePoem;
  };;
  ChinesePoem(s &ID, vs &context, int count, bool remembered) :
    RememberData(ID, context, count, remembered) {
    this->Type = CType::ChinesePoem;
  };;
  ChinesePoem(s &ID, vs &context, int count) :
    RememberData(ID, context, count) {
    this->Type = CType::ChinesePoem;
  };;
  ChinesePoem(s &ID, vs &context) :
    RememberData(ID, context) {
    this->Type = CType::ChinesePoem;
  };
  ChinesePoem(s &ID) :
    RememberData(ID) {
    this->Type = CType::ChinesePoem;
  };
  
  virtual ~ChinesePoem();
};

// Context:
//   - 发音   //
//   - 词性   //
//   - 意思   //
//   - 例句   //
//   重复以上 //
class EnglishWord : public RememberData
{
  using s = std::string;
  using vs = std::vector<s>;
public:
  EnglishWord(s &ID, vs &context, int count, bool remembered, RTime Time) :
    EnglishWord(ID, context, count, remembered) {
    this->User.Time = Time;
  };
  EnglishWord(s &ID, vs &context, int count, bool remembered) :
    EnglishWord(ID, context, count) {
    this->User.Remembered = remembered;
  };
  EnglishWord(s &ID, vs &context, int count) :
    EnglishWord(ID, context) {
    this->User.Count = count;
  };;
  EnglishWord(s &ID, vs &context);
  EnglishWord(s &ID) :
    RememberData(ID) {
    this->Type = CType::EnglishWord;
  };

  inline size_t GetCount() {
    return Context->size() / 4;
  }
  inline const s &GetPronunciation(size_t index) {
    if(index >= GetCount())
      throw std::out_of_range("Index out of range (" + ID + "): " + std::to_string(index));
    return *Context->at(index * 4 + 0);
  }
  inline const s &GetPartOfSpeech(size_t index) {
    if(index >= GetCount())
      throw std::out_of_range("Index out of range (" + ID + "): " + std::to_string(index));
    return *Context->at(index * 4 + 1);
  }
  inline const s &GetMeaning(size_t index) {
    if(index >= GetCount())
      throw std::out_of_range("Index out of range (" + ID + "): " + std::to_string(index));
    return *Context->at(index * 4 + 2);
  }
  inline const s &GetExample(size_t index) {
    if(index >= GetCount())
      throw std::out_of_range("Index out of range (" + ID + "): " + std::to_string(index));
    return *Context->at(index * 4 + 3);
  }

  virtual ~EnglishWord() {};

};

#endif