#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>

class Task {
private:
  std::string task;
  bool isCompleted;

public:
  Task(std::string newTask, bool completed) {
    task = newTask;
    isCompleted = completed;
    std::cout << "New Task Created\n";
  }

  std::string getTask() { return task; }
  bool getIsCompleted() { return isCompleted; }
  void setTask(std::string newTask) { task = newTask; }
  void setIsCompleted(bool completed) { isCompleted = completed; }
};

std::string getUserInput();

void displayTitle();
void addNewTask(std::vector<Task> *tasks);
void displayAllTask(std::vector<Task> tasks);
void waitForUserToPressEnter();
void clearScreen();

int main(void) {
  std::string userInputStr;
  std::vector<Task> tasks;

  do {
    displayTitle();
    userInputStr = getUserInput();
    if (userInputStr == "1") {
      addNewTask(&tasks);
    } else if (userInputStr == "3") {
      displayAllTask(tasks);
    }

  } while (userInputStr != "4");

  return 0;
}

void displayTitle() { std::cout << "Task Tracker!\n"; }

std::string getUserInput() {
  std::string userInputStr;
  clearScreen();
  std::cout << "Enter an option:\n1. Create Task\n2. Edit Task\n3. Display "
               "Task(s)\n4. Exit\n>>> ";
  std::getline(std::cin, userInputStr);
  clearScreen();

  return userInputStr;
}

void addNewTask(std::vector<Task> *tasks) {
  clearScreen();
  std::string userTask;
  std::cout << "Enter a task: ";
  std::getline(std::cin, userTask);
  tasks->push_back(Task(userTask, false));
  clearScreen();
}

void displayAllTask(std::vector<Task> tasks) {
  clearScreen();
  for (int i = 0; i < tasks.size(); i++) {
    std::cout << "Task " << i + 1 << ": " << tasks[i].getTask() << '\n';
  }
  waitForUserToPressEnter();
}

void waitForUserToPressEnter() {
  std::string userInput = "";
  std::cout << "Press 'Enter' to exit display...\n";
  std::getline(std::cin, userInput);
  if (userInput != "\n") {
    userInput = "";
    std::getline(std::cin, userInput);
  }
}

void clearScreen() { system("clear || cls"); }
