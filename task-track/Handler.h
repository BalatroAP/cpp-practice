#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <ctime>

#include "Task.h"

using namespace std;
using json = nlohmann::json;
namespace fs = filesystem;

class Handler {
public:
  Handler();

  fs::path getPath();
  fs::path getFileName();
  fs::path getFullFilePath();
  int getFileUID();

  json getFileData();
  json setFileData();

  void appendTask(Task task, string pos);

  bool isFileExist();
  void createFile();
  void updateFileData(json j);
  void closeFile();

private:
  fs::path currPath;
  fs::path fileName;
  json fileData;
  int fileUID;
};
