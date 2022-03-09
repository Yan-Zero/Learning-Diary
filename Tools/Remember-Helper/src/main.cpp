#include <iostream>
#include "Context.hpp"
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
  string remember_dir = "remember";
  string chinese_dir = "chinese";
  string english_dir = "english";
  string resources_dir = "Resources";
  if(config["root"])
    root_dir = config["root"].as<string>();
  if(config["remember"])
    remember_dir = config["remember"].as<string>();
  if(config["chinese"])
    chinese_dir = config["chinese"].as<string>();
  if(config["english"])
    english_dir = config["english"].as<string>();
  if(config["resources"])
    resources_dir = config["resources"].as<string>();

  remember_dir = join_path(root_dir, remember_dir);
  chinese_dir = join_path(remember_dir, chinese_dir);
  english_dir = join_path(remember_dir, english_dir);
  resources_dir = join_path(root_dir, resources_dir);

  // print the config
  cout << "root_dir: " << root_dir << endl;
  cout << "remember_dir: " << remember_dir << endl;
  cout << "chinese_dir: " << chinese_dir << endl;
  cout << "english_dir: " << english_dir << endl;
  cout << "resources_dir: " << resources_dir << endl;

  // test the MP3Player, the file is resources + '/test.mp3'
  string test_file = join_path(resources_dir, string("cache/test.mp3"));
  cout << "test_file: " << test_file << endl;
  MP3Player player(test_file.c_str());
  player.Play();
  // _sleep(5000);
  // player.Stop();

  return 0;
}

