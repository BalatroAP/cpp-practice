#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  ofstream csv("expense.csv");

  csv << "testing";

  csv.close();
}
