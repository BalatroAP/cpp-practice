#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "Recipe.h"

using namespace std;
using namespace nlohmann;

int main(void) {
  json j;
  vector<Recipe> recipes;

  ifstream file;
  file.open("recipes.json", ios::in);
  j = json::parse(file);
  file.close();

  vector<json> idk = j["data"].get<vector<json>>();

  for (int i = 0, size = idk.size(); i < size; i++) {
    recipes.push_back(Recipe(idk[i]));
  }

  for (int i = 0, size = recipes.size(); i < size; i++) {
    recipes[i].displayRelevantData();
  }

}
