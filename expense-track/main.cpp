#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getCsvFileLines();
void appendLineToCsv(string newLine);
void displayCsvData(vector<string> csvLines);

int main(void) {
  displayCsvData(getCsvFileLines());
}

vector<string> getCsvFileLines() {
  ifstream csvRead("expense.csv");
  string csvLine;
  vector<string> csvLines;

  while (getline(csvRead, csvLine)) {
    csvLines.push_back(csvLine);
  }

  csvRead.close();

  return csvLines;
}

void appendLineToCsv(string newLine) {
  ofstream csv;
  csv.open("expense.csv", ios::out | ios::app);
  csv << newLine << '\n';
  csv.close();
}

void displayCsvData(vector<string> csvLines) {
  for (int i = 0, size = csvLines.size(); i < size; i++) {
    cout << csvLines[i] << '\n';
  }
}
