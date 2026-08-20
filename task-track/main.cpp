#include <iostream>

#include "Handler.h"

using namespace std;

int main(int argc, char *argv[]) {
  Handler handler;

  cout << "PATH: " << handler.getPath() << '\n';
  cout << "FILE NAME: " << handler.getFileName() << '\n';
  cout << "DOES PATH EXISTS: " << handler.isFileExist() << '\n';
  cout << "IS FILE OPEN: " << handler.file.is_open() << '\n';
  handler.file << "SOME TEXT";

  handler.closeFile();
}
