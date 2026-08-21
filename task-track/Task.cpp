#include "Task.h"

int Task::ID = 0;

Task::Task(string taskStr) {
  this->task = taskStr;
  this->progress = INACTIVE;
  this->ID = ID++;
}

string Task::getTask() { return this->task; }
int Task::getProgress() { return this->progress; }

void Task::setTask(string task) { this->task = task; }
void Task::setProgress(Progress progress) { this->progress = progress; }
