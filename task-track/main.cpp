#include <iostream>
#include <string>

#include "Handler.h"
#include "Task.h"

using namespace std;
using json = nlohmann::json;

Task getUserTask();

int main(int argc, char *argv[]) {
  Handler handler;
  int id = 1;

  handler.appendTask(getUserTask(), to_string(id++)); 
  handler.appendTask(getUserTask(), to_string(id++)); 
  handler.appendTask(getUserTask(), to_string(id++)); 

  cout << setw(handler.getFileData().size()) << handler.getFileData() << '\n';
}

Task getUserTask() {
  string userInput;

  cout << "Enter task you want to track: ";
  getline(cin, userInput);

  return Task(userInput);
}
