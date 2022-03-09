#include <HTTP.h>
#include <fstream>
#include <MP3.hpp>
#include <string>
#include <iostream>

std::string Trim(std::string &str)
{
  size_t a = 0;
  while (str[a] == ' ')
    a++;
  size_t b = str.length() - 1;
  while (str[b] == ' ')
    b--;
  return str.substr(a, b + 1);
};
void GetCurrPath(std::string &Name)
{
  if(Name.length() < 1)
  {
    Name = "";
    return;
  }
  Name = Trim(Name).substr(0, Name.length());
}

#ifdef _WIN32

#include <windows.h>
#include <cstring>
#pragma comment(lib, "Winmm.lib")

bool HttpDownload(std::string &url, std::string &file_path, bool use_cache)
{
  if (use_cache && std::ifstream(file_path).good())
    return true;
  
  std::string command = "curl -o \"" + file_path + "\" \"" + url + "\"";
  system(command.c_str());
  return true;
}

MP3Player::MP3Player(const char *file_path)
{
  this->file_path = file_path;
  this->iLong = GetShortPathName(file_path, this->cache, sizeof(this->cache));
  this->name = this->cache;
  GetCurrPath(this->name);

  this->name = "open " + this->name + " alias media type mpegvideo";
  this->iLong  = mciSendString("close all", NULL, 0, NULL);
  this->iLong  = mciSendString(this->name.c_str(), NULL, 0, NULL);
  // this->iLong  = mciSendString("set media time format milliseconds", NULL, 0, NULL);
}

MP3Player::~MP3Player()
{
  this->Stop();
}

void MP3Player::Play()
{
  if (this->state == MP3PlayerState::mPlaying)
    return;
  // use mciSendString play the mp3 file
  mciSendString("play media wait", NULL, 0, NULL);
  this->state = MP3PlayerState::mPlaying;
}

void MP3Player::Stop()
{
  if (this->state == MP3PlayerState::mStopped)
    return;
  // use mciSendString stop the mp3 file
  mciSendString("stop media", this->cache, sizeof(this->cache), 0);
  mciSendString("close all", this->cache, sizeof(this->cache), 0);
  this->state = MP3PlayerState::mStopped;
}

void MP3Player::Pause()
{
  if (this->state == MP3PlayerState::mPaused)
    return;
  // use mciSendString pause the mp3 file
  mciSendString("pause media", this->cache, sizeof(this->cache), 0);
  this->state = MP3PlayerState::mPaused;
}

void MP3Player::Resume()
{
  if (this->state == MP3PlayerState::mPlaying)
    return;
  // use mciSendString resume the mp3 file
  mciSendString("resume media", this->cache, sizeof(this->cache), 0);
  this->state = MP3PlayerState::mPlaying;
}

int MP3Player::GetCurrentPosition()
{
  // use mciSendString to get the current position of the mp3 file
  mciSendString("status media position", this->cache, sizeof(this->cache), 0);
  return (int)(atoi(this->cache) / 1000);
}

// int MP3Player::GetDuration()
// {
//   // use mciSendString to get the duration of the mp3 file
//   mciSendString("status media length", this->cache, sizeof(this->cache), 0);
//   return (int)(atoi(this->cache) / 1000);
// }

#endif
