#include "Handler.h"
#include <fstream>

Handler::Handler() {
  this->currPath = fs::current_path();
  this->fileName = "/tasks.json";
  this->fileData = this->setFileData();
  this->fileUID = *this->fileData.find("UID");
}

fs::path Handler::getPath() { return this->currPath; }
fs::path Handler::getFileName() { return this->fileName; }
fs::path Handler::getFullFilePath() {
  return this->getPath() += this->getFileName();
}
json Handler::getFileData() { return this->fileData; }
int Handler::getFileUID() { return this->fileUID; }

json Handler::setFileData() {
  if (!this->isFileExist()) {
    this->createFile();
  }

  json j;
  ifstream file;

  file.open(this->getFullFilePath());

  if (!file.is_open()) {
    cout << "ERROR OPENING FILE!\n";
    exit(1);
  }
  file >> j;

  return j;
}

void Handler::updateFileData(json j) {
  if (!this->isFileExist()) {
    this->createFile();
  }

  ofstream file(this->getFullFilePath(), ios::trunc);

  if (!file.is_open()) {
    cout << "ERROR OPENING FILE!\n";
    exit(1);
  }

  file << j;
  file.close();
}

void Handler::appendTask(Task task, string key) {
  auto keyLocation = this->fileData.find(key);
  int id = task.getID();
  json object = {"UID", ++id};

  this->fileData.push_back(
      json::object_t::value_type(to_string(id), task.getTaskObject()));
}

void Handler::createFile() {
  ofstream file;

  file.open(this->getFullFilePath());
  if (!file.is_open()) {
    cout << "ERROR OPENING FILE!\n";
    exit(1);
  }
  file << "{}";

  file.close();
}

bool Handler::isFileExist() {
  return fs::exists(this->getPath() += this->getFileName());
}
