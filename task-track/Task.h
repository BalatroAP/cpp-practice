#pragma once

#include <nlohmann/json.hpp>
#include <string>

using namespace std;

enum Progress { INACTIVE, ACTIVE, COMPLETE };

class Task {
public:
  // Constructor
  Task(string taskStr);

  // Setter
  void setTask(string task, int id);
  void setProgress(Progress progress, int id);

  // Getter
  string getTask();
  Progress getProgress();
  int getID();

private:
  static int ID;
  string task;
  Progress progress;
};
