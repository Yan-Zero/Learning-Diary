#include <iostream>
#include "Context.h"
#include "yaml-cpp/yaml.h"
#include <fstream>

// join the path
std::string joinPath(std::string &path1, std::string &path2) {
    if (path1.back() == '/') {
        return path1 + path2;
    } else {
        return path1 + "/" + path2;
    }
}

int main()
{
  using namespace std;
  YAML::Node config = YAML::LoadFile("Remember-Helper.yaml");
  if(config.Type() != YAML::NodeType::Map)
    config = YAML::Load("{}");

  // Get the config
  string root_dir = "../";
  string remember_dir = "remember";
  string chinese_dir = "chinese";
  string english_dir = "english";
  if(config["root"])
    root_dir = config["root"].as<string>();
  if(config["remember"])
    remember_dir = config["remember"].as<string>();
  if(config["chinese"])
    chinese_dir = config["chinese"].as<string>();
  if(config["english"])
    english_dir = config["english"].as<string>();

  remember_dir = joinPath(root_dir, remember_dir);
  chinese_dir = joinPath(remember_dir, chinese_dir);
  english_dir = joinPath(remember_dir, english_dir);


  return 0;
}