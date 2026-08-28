#include <fmt/base.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

int main(void) {
  json j;
  ifstream file;
  file.open("receipes.json", ios::in);
  j = json::parse(file);
  file.close();

  vector<json> idk = j["data"].get<vector<json>>();
}
