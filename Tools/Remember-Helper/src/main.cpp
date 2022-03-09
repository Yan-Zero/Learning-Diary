#include <iostream>
#include "context.hpp"
#include "yaml-cpp/yaml.h"
#include <fstream>
#include <MP3.hpp>
#include <string>

std::string join_path(std::string &path1, std::string &path2)
{
  if (path1[path1.length() - 1] == '/')
    return path1 + path2;
  else
    return path1 + "/" + path2;
};

int main()
{
  using namespace std;
  YAML::Node config = YAML::LoadFile("Remember-Helper.yaml");
  if(config.Type() != YAML::NodeType::Map)
    config = YAML::Load("{}");

  // Get the config
  string root_dir = "../";
  string data_dir = "data";
  string chinese_dir = "remember/english";
  string english_dir = "remember/english";
  string resources_dir = "Resources";
  if(config["root"])
    root_dir = config["root"].as<string>();
  if(config["remember"])
    data_dir = config["data"].as<string>();
  if(config["chinese"])
    chinese_dir = config["chinese"].as<string>();
  if(config["english"])
    english_dir = config["english"].as<string>();
  if(config["resources"])
    resources_dir = config["resources"].as<string>();

  data_dir = join_path(root_dir, data_dir);
  resources_dir = join_path(root_dir, resources_dir);
  chinese_dir = join_path(resources_dir, chinese_dir);
  english_dir = join_path(resources_dir, english_dir);

  return 0;
}

