#include <cmath>
#include <fmt/base.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Expense.h"

using namespace std;

vector<Expense> convertParsedStringsToExpenses();
vector<Expense> getExpenses();
vector<vector<string>> convertCsvToParsedStrings();
vector<string> convertExpensesToParsedStrings(vector<Expense> expenses);
vector<string> delimitByComma(string csvLine);
vector<string> getCsvFileLines();
string getFlagArgument(vector<string> flags, string searchFlag);
void deleteId(vector<Expense> &expenses, int id);
void overwriteCsv(vector<string> lines);
void appendLineToCsv(string newLine);
void displayCsvData(vector<string> csvLines);
void displayPrettyExpenses(vector<Expense> expenses);
void displayTotalExpenses(vector<Expense> expenses);

int main(int argc, char *argv[]) {
  vector<Expense> expenses = getExpenses();
  vector<string> flags;
  string option;

  if (argc > 1) {
    option = argv[1];
  }

  if (argc > 2) {
    for (int i = 2; i < argc; i++) {
      flags.push_back(argv[i]);
    }
  }

  if (option == "list") {
    displayPrettyExpenses(expenses);
  } else if (option == "summary") {
    displayTotalExpenses(expenses);
  } else if (option == "delete" && argc > 2) {
    int id = stoi(getFlagArgument(flags, "--id"));
    deleteId(expenses, id);
    overwriteCsv(convertExpensesToParsedStrings(expenses));
  } else {
    fmt::print("Not a valid command for expense-tracker\n");
  }
}

vector<Expense> getExpenses() { return convertParsedStringsToExpenses(); }

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

string getFlagArgument(vector<string> flags, string searchFlag) {
  string flagArg = "";

  for (int i = 0, size = flags.size(); i < size; i++) {
    if (flags[i] == searchFlag) {
      flagArg = flags[i + 1];
    }
  }

  return flagArg;
}

vector<string> convertExpensesToParsedStrings(vector<Expense> expenses) {
  vector<string> parsedStrings;

  for (int i = 0, size = expenses.size(); i < size; i++) {
    parsedStrings.push_back(expenses[i].getExpenseAsString());
  }

  return parsedStrings;
}

vector<vector<string>> convertCsvToParsedStrings() {
  vector<string> csvLines = getCsvFileLines();
  vector<vector<string>> parsedExpenses;
  vector<string> parsedExpense;

  for (int i = 1, size = csvLines.size(); i < size; i++) {
    stringstream ss(csvLines[i]);
    string token;

    while (getline(ss, token, ',')) {
      parsedExpense.push_back(token);
    }
    parsedExpenses.push_back(parsedExpense);
    parsedExpense.clear();
  }

  return parsedExpenses;
}

vector<Expense> convertParsedStringsToExpenses() {
  vector<vector<string>> parsedExpenses = convertCsvToParsedStrings();
  vector<Expense> expenses;

  for (int i = 0, size = parsedExpenses.size(); i < size; i++) {
    Expense newExpense(stoi(parsedExpenses[i][0]), stoi(parsedExpenses[i][3]),
                       parsedExpenses[i][1], parsedExpenses[i][2]);

    expenses.push_back(newExpense);
  }

  return expenses;
}

void deleteId(vector<Expense> &expenses, int id) {
  bool flag = false;

  for (int i = 0, size = expenses.size(); i < size; i++) {
    if (id == expenses[i].getId()) {
      expenses.erase(expenses.begin() + i);
      flag = true;
    }
  }

  if (flag) {
    fmt::print("ID {} successfully deleted!\n", id);
  } else {
    fmt::print("ID {} un-successfully deleted...\n", id);
  }
}

void overwriteCsv(vector<string> lines) {
  lines.insert(lines.begin(), "id,date,description,amount");
  ofstream csv;
  csv.open("expense.csv", ios::out | ios::trunc);
  for (int i = 0, size = lines.size(); i < size; i++) {
    csv << lines[i] << '\n';
  }
  csv.close();
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

void displayPrettyExpenses(vector<Expense> expenses) {
  fmt::print("ID   Date      Description    Amount\n");
  for (int i = 0, size = expenses.size(); i < size; i++) {
    int id = expenses[i].getId();
    int amount = expenses[i].getAmount();
    string date = expenses[i].getDate();
    string description = expenses[i].getDescription();

    fmt::print("{}    {}      {}          ${}\n", id, date, description,
               amount);
  }
}

void displayTotalExpenses(vector<Expense> expenses) {
  int sum = 0;

  for (int i = 0, size = expenses.size(); i < size; i++) {
    sum += expenses[i].getAmount();
  }

  fmt::print("Total expenses: ${}\n", sum);
}
