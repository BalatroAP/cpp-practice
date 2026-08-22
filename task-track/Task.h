#pragma once

#include <ctime>
#include <nlohmann/json.hpp>
#include <string>

using namespace std;
using json = nlohmann::json;

enum Progress { INACTIVE, ACTIVE, COMPLETE };

class Task {
public:
  // Constructor
  Task(string taskStr, int id);

  // Setter
  void setTask(string task);
  void setProgress(Progress progress);

  // Getter
  string getTask();
  int getProgress();
  int getID();
  time_t getCreatedTime();
  time_t getLastUpdatedTime();
  json getTaskObject();

private:
  int id;
  string task;
  Progress progress;
  time_t createdTime;
  time_t lastUpdatedTime;
};
