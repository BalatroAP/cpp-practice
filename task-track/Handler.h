#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
namespace fs = filesystem;

class Handler {
public:
  ifstream rFile;

  Handler();

  fs::path getPath();
  fs::path getFileName();
  ofstream createFile();
  bool isFileExist();
  fs::path getFullFilePath();
  void closeFile();

private:
  fs::path currPath;
  fs::path fileName;
};
