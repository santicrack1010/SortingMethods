#ifndef __CREATE_FILES_H__
#define __CREATE_FILES_H__

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

void create_file(const std::string path, const std::vector<int>& array) {
  std::ofstream file(path);
  if (file.is_open()) {
    for (const int& value : array) {
      file << value << "\n";
    }
    file.close();
  }
}

void create_directory(const std::string& path) {
  std::filesystem::create_directories(path);
}

#endif  // __CREATE_FILES_H__