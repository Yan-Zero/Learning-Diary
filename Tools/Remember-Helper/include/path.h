#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <vector>

void getFiles(const std::string &path, std::vector<std::string>& files);
std::string joinPath(const std::string &path1, const std::string &path2);

#endif PATH_H_