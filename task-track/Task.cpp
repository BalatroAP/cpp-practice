#include "Task.h"

Task::Task(string taskStr, int id) {
  this->id = id;
  this->task = taskStr;
  this->progress = INACTIVE;
  this->createdTime = time(NULL);
  this->lastUpdatedTime = this->createdTime;
}

string Task::getTask() { return this->task; }
int Task::getProgress() { return this->progress; }
time_t Task::getCreatedTime() { return this->createdTime; }
time_t Task::getLastUpdatedTime() { return this->lastUpdatedTime; }
int Task::getID() { return this->id; }
json Task::getTaskObject() {
  return json{
      {"lastupdatedtime", this->lastUpdatedTime},
      {"createdtime", this->createdTime},
      {"progress", this->progress},
      {"task", this->task},
  };
}

void Task::setTask(string task) { this->task = task; }
void Task::setProgress(Progress progress) { this->progress = progress; }
