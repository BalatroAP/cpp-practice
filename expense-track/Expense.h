#pragma once

#include <string>

using namespace std;

class Expense {
  public:
    Expense(int id, int amount, string date, string description);

    int getId();
    int getAmount();
    string getDate();
    string getDescription();

    void setId(int id);
    void setAmount(int  amount);
    void setDate(string date);
    void setDescription(string description);

  private:
    int id;
    int amount;
    string date;
    string description;

};
