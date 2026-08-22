#include "Expense.h"

Expense::Expense(int id, int amount, string date, string description) {
  this->id = id;
  this->amount = amount;
  this->date = date;
  this->description = description;
}

// Getter

int Expense::getId() { return this->id; }
int Expense::getAmount() { return this->amount; }
string Expense::getDate() { return this->date; }
string Expense::getDescription() { return this->description; }

// Setter

void Expense::setId(int id) { this->id = id; }
void Expense::setAmount(int amount) { this->amount = amount; }
void Expense::setDate(string date) { this->date = date; }
void Expense::setDescription(string description) {
  this->description = description;
}
