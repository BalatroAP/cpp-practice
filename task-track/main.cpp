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

std::string getUserInput();
<<<<<<< HEAD

void displayTitle();
void addNewTask(std::vector<Task> *tasks);
void displayAllTask(std::vector<Task> tasks);
void waitForUserToPressEnter();
=======
void newTask(std::vector<Task> *tasks, bool isNewTask, int index = 0);
int helperTaskFunc(std::vector<Task> *tasks, std::string str);
void editTask(std::vector<Task> *tasks);
void completeTask(std::vector<Task> *tasks);
void deleteTask(std::vector<Task> *tasks);
void displayAllTask(std::vector<Task> tasks, bool isDisplayOnly);
int getUserInputForSelection(std::string str, int length);
void waitForUserToPressEnter(std::string str);
>>>>>>> refs/remotes/origin/main
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
    } else if (userInputStr == "5") {
      deleteTask(&tasks);
    }

  } while (userInputStr != "0");

  return 0;
}

void displayTitle() { std::cout << "Task Tracker!\n"; }

std::string getUserInput() {
  std::string userInputStr;
  clearScreen();
  std::cout << "Enter an option:\n1. Create Task\n2. Edit Task\n3. Display "
               "Task(s)\n4. Complete Task\n5. Delete Task\n0. Exit\n>>> ";
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

int helperTaskFunc(std::vector<Task> *tasks, std::string str) {
  int selectedTask;

  if (tasks->size() == 0) {
    waitForUserToPressEnter("There are no tasks to display!\n");
    return -1;
  }

  clearScreen();
  displayAllTask(*tasks, false);
  selectedTask = getUserInputForSelection(str, tasks->size()) - 1;

  return selectedTask;
}

void editTask(std::vector<Task> *tasks) {
  int selectedTask =
      helperTaskFunc(tasks, "\nWhat task would you like to edit?: ");

  if (selectedTask == -1) {
    return;
  }

  newTask(tasks, false, selectedTask);
}

void completeTask(std::vector<Task> *tasks) {
  int selectedTask =
      helperTaskFunc(tasks, "\nEnter a task you want to mark complete: ");

  if (selectedTask == -1) {
    return;
  }

  tasks->at(selectedTask).setIsCompleted();
}

void deleteTask(std::vector<Task> *tasks) {
  int selectedTask =
      helperTaskFunc(tasks, "\nEnter a task you want to delete: ");

  if (selectedTask == -1) {
    return;
  }

  tasks->erase(tasks->begin() + selectedTask);
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

int getUserInputForSelection(std::string str, int length) {
  std::string userInput;
  int castedInput;

  std::cout << str;
  std::getline(std::cin, userInput);

  castedInput = std::stoi(userInput);

  while (castedInput > length || castedInput <= 0) {
    std::cout << "Invalid entry!\n" << str << '\n';
    std::getline(std::cin, userInput);
    castedInput = std::stoi(userInput);
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
