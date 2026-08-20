#include "Task.h"

int Task::ID = 0;

Task::Task(string taskStr) {
  this->task = taskStr;
  this->progress = INACTIVE;
  this->ID = ID++;
}

void Task::setTask(string task, int id) {}

void Task::setProgress(Progress progress, int id) {}
