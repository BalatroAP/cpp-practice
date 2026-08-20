#include "Handler.h"

Handler::Handler() {
  this->currPath = fs::current_path();
  this->fileName = "/tasks.json";
  this->rFile = this->createFile();
}

fs::path Handler::getPath() { return this->currPath; }
fs::path Handler::getFileName() { return this->fileName; }
fs::path Handler::getFullFilePath() {
  return this->getPath() += this->getFileName();
}

ofstream Handler::createFile() {
  ofstream file;

  file.open(this->getFullFilePath(), fstream::trunc);

  if (!file.is_open()) {
    cout << "ERROR OPENING FILE!\n";
    exit(1);
  }

  return file;
}

bool Handler::isFileExist() {
  return fs::exists(this->getPath() += this->getFileName());
}

void Handler::closeFile() { this->wFile.close(); }
