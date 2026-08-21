#include "Handler.h"

Handler::Handler() {
  this->currPath = fs::current_path();
  this->fileName = "/tasks.json";
  this->fileData = this->setFileData();
}

fs::path Handler::getPath() { return this->currPath; }
fs::path Handler::getFileName() { return this->fileName; }
fs::path Handler::getFullFilePath() {
  return this->getPath() += this->getFileName();
}
json Handler::getFileData() { return this->fileData; }

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

void Handler::appendTask(Task task, string pos) {
  string taskStr = task.getTask();
  int progress = task.getProgress();
  json object = {{"progress", progress}, {"task", taskStr}};
  this->fileData.push_back(json::object_t::value_type(pos, object));
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
