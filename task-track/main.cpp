#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>

class Task {
  std::string task;
  bool isCompleted;

public:
  Task(std::string task, bool isCompleted) {
    this->task = task;
    this->isCompleted = isCompleted;
    std::cout << "New Task Created\n";
  }

  std::string getTask() { return task; }
  bool getIsCompleted() { return isCompleted; }
  void setTask(std::string task) { this->task = task; }
  void setIsCompleted() { this->isCompleted = !isCompleted; }
};

void displayTitle();
std::string getUserInput();
void newTask(std::vector<Task> *tasks, bool isNewTask, int index = 0);
void editTask(std::vector<Task> *tasks);
void completeTask(std::vector<Task> *tasks);
void displayAllTask(std::vector<Task> tasks, bool isDisplayOnly);
int getUserInputForEdit(int length, bool isComplete);
void waitForUserToPressEnter(std::string str);
void clearScreen();

int main(void) {
  std::string userInputStr;
  std::vector<Task> tasks;

  do {
    displayTitle();
    userInputStr = getUserInput();
    if (userInputStr == "1") {
      newTask(&tasks, true);
    } else if (userInputStr == "2") {
      editTask(&tasks);
    } else if (userInputStr == "3") {
      displayAllTask(tasks, true);
    } else if (userInputStr == "4") {
      completeTask(&tasks);
    }

  } while (userInputStr != "0");

  return 0;
}

void displayTitle() { std::cout << "Task Tracker!\n"; }

std::string getUserInput() {
  std::string userInputStr;
  clearScreen();
  std::cout << "Enter an option:\n1. Create Task\n2. Edit Task\n3. Display "
               "Task(s)\n4. Complete Task\n0. Exit\n>>> ";
  std::getline(std::cin, userInputStr);
  clearScreen();

  return userInputStr;
}

void newTask(std::vector<Task> *tasks, bool isNewTask, int index) {
  clearScreen();
  std::string userTask;

  std::cout << "Enter a task: ";
  if (isNewTask) {
    std::getline(std::cin, userTask);
    tasks->push_back(Task(userTask, false));
  } else {
    std::getline(std::cin, userTask);
    tasks->at(index).setTask(userTask);
  }
  clearScreen();
}

void editTask(std::vector<Task> *tasks) {
  int selectedTask;

  if (tasks->size() == 0) {
    waitForUserToPressEnter("There are no tasks to display!\n");
    return;
  }

  clearScreen();
  displayAllTask(*tasks, false);
  selectedTask = getUserInputForEdit(tasks->size(), false) - 1;
  newTask(tasks, false, selectedTask);
}

void completeTask(std::vector<Task> *tasks) {
  int selectedTask;

  if (tasks->size() == 0) {
    waitForUserToPressEnter("There are no tasks to display!\n");
    return;
  }

  clearScreen();
  displayAllTask(*tasks, false);
  selectedTask = getUserInputForEdit(tasks->size(), true) - 1;
  tasks->at(selectedTask).setIsCompleted();
}

void displayAllTask(std::vector<Task> tasks, bool isDisplayOnly) {
  std::string userInput;
  clearScreen();

  if (tasks.size() == 0) {
    waitForUserToPressEnter("There are no tasks to display!\n");
    return;
  }

  for (int i = 0; i < tasks.size(); i++) {
    std::string taskCompleted = tasks[i].getIsCompleted() ? "Yes" : "No";
    std::cout << "Task " << i + 1 << ":\n";
    std::cout << '\t' << tasks[i].getTask() << '\n';
    std::cout << '\t' << "Task Complete: " << taskCompleted << '\n';
  }

  if (isDisplayOnly) {
    waitForUserToPressEnter("\nPress 'Enter' to exit display!\n");
  }
}

int getUserInputForEdit(int length, bool isComplete) {
  std::string userInput;
  int castedInput;

  if (isComplete) {
    std::cout << "Enter which task you want to complete: ";
    std::getline(std::cin, userInput);

    castedInput = std::stoi(userInput);

    while (castedInput > length || castedInput <= 0) {
      std::cout << "Invalid entry!\nEnter which task you want to complete: ";
      std::getline(std::cin, userInput);
    }
  } else {
    std::cout << "Enter which task you want to edit: ";
    std::getline(std::cin, userInput);

    castedInput = std::stoi(userInput);

    while (castedInput > length) {
      std::cout << "Invalid entry!\nEnter which task you want to edit: ";
      std::getline(std::cin, userInput);
    }
  }

  return castedInput;
}

void waitForUserToPressEnter(std::string str) {
  std::string userInput = "";
  std::cout << str;
  std::getline(std::cin, userInput);
  if (userInput != "\n") {
    userInput = "";
    std::getline(std::cin, userInput);
  }
}

void clearScreen() { system("clear || cls"); }
