#ifndef YAN_MP3_H_
#define YAN_MP3_H_

#include <string>

enum class MP3PlayerState
{
  mPlaying = 1,
  mPaused = 2,
  mStopped = 3,
};

class MP3Player
{
public:
  MP3Player(const char* file_path);

  void Play();
  void Stop();
  void Pause();
  void Resume();
  // void SetVolume(int volume);
  // void SetPosition(int position);
  // void SetSpeed(int speed);
  int GetCurrentPosition();
  // 总时长
  int GetDuration();
  ~MP3Player();

  int iLong = 0;

private:
  std::string file_path;
  MP3PlayerState state = MP3PlayerState::mStopped;
  // int volume = 100;
  // int speed = 100;

  char cache[512] = {0};
  std::string name = "";
};

#endif
