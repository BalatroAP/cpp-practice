#include <iostream>

#include "Handler.h"
#include "Task.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {
  Handler handler;
  string command = argv[1];
  int id = handler.getFileUID();

  if (command.compare("add") == 0) {
    handler.appendTask(Task(argv[2], id++), "inactive");

  } else if (command.compare("update")) {

  } else if (command.compare("delete")) {

  } else if (command.compare("list")) {
  }

  cout << "ID: " << id << '\n';
  cout << setw(handler.getFileData().size()) << handler.getFileData() << '\n';
  handler.updateFileData(handler.getFileData());
}
