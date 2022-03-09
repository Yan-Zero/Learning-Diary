#ifndef HTTP_H_
#define HTTP_H_

#include <string>

bool HttpDownload(std::string &url, std::string &name, bool use_cache = false);
void PlayYoudaoMP3(std::string Speech[2]);

#endif