#include <iostream>
#include <fstream>
#include "context.hpp"
#include "yaml-cpp/yaml.h"
#include "MP3.hpp"
#include "path.h"

void loadEnglishDatabase(const std::string &path_data, 
                         std::map<std::string, RememberData::UserData> &user_data, 
                         std::vector<EnglishWord*> &array)
{
  YAML::Node data_yaml = YAML::Load(path_data);
  RememberData::CType type = RememberData::CType::EnglishWord;

  for (auto &item : data_yaml)
  {
    if(item["Type"])
    {
      if(item["Type"].as<std::string>() == "Chinese-Poem")
        type = RememberData::CType::ChinesePoem;
      else if(item["Type"].as<std::string>() == "English-Word")
        type = RememberData::CType::EnglishWord;
      else
        type = RememberData::CType::EnglishWord;
    }
    if(type != RememberData::CType::EnglishWord)
      continue;
    auto t = user_data.find(item["ID"].as<std::string>());

    EnglishWord *word = new EnglishWord(
      item["ID"].as<std::string>(),
      item["context"].as<std::vector<std::string>>(),
      t == user_data.end() ? 0 : t->second.Count,
      t == user_data.end() ? false : t->second.Remembered,
      t == user_data.end() ? RTime() : t->second.Time
    );
    array.push_back(word);
  }
};

int main()
{
  using namespace std;
  YAML::Node config = YAML::LoadFile("Remember-Helper.yaml");
  if(config.Type() != YAML::NodeType::Map)
    config = YAML::Load("{}");

  // Get the config
  string root_dir = "../";
  string user_dir = "user";
  string chinese_dir = "remember/english";
  string english_dir = "remember/english";
  string resources_dir = "Resources";
  // string database_dir = "database";

  if(config["root"])
    root_dir = config["root"].as<string>();
  if(config["remember"])
    user_dir = config["user"].as<string>();
  if(config["chinese"])
    chinese_dir = config["chinese"].as<string>();
  if(config["english"])
    english_dir = config["english"].as<string>();
  if(config["resources"])
    resources_dir = config["resources"].as<string>();

  user_dir = joinPath(root_dir, user_dir);
  resources_dir = joinPath(root_dir, resources_dir);
  chinese_dir = joinPath(resources_dir, chinese_dir);
  english_dir = joinPath(resources_dir, english_dir);
  // database_dir = join_path(resources_dir, database_dir);

  map<string, RememberData::UserData> temp_user;
  vector<string> file_list;
  getFiles(user_dir, file_list);
  for(auto &file : file_list)
  {
    if(file.find(".yaml") == string::npos)
      continue;
    YAML::Node data_yaml = YAML::LoadFile(file);
    if(data_yaml.Type() != YAML::NodeType::Sequence)
      continue;
    for(auto &item : data_yaml)
    {
      if(!item["ID"])
        continue;
      temp_user[item["ID"].as<string>()] = RememberData::UserData{
        item["Count"].as<int>(0),
        item["Remembered"].as<bool>(false),
        item["Time"].as<RTime>(RTime()), 
      };
    }
  }

  vector<EnglishWord*> english_words;
  vector<ChinesePoem*> chinese_poems;

  getFiles(english_dir, file_list);
  for(auto &file : file_list)
  {
    if(file.find(".yaml") == string::npos)
      continue;
    loadEnglishDatabase(file, temp_user, english_words);
  }

  return 0;
}

