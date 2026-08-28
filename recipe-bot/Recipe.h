#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using namespace nlohmann;
using namespace std;

class Recipe {
  public:
    Recipe(json j);

  private:
    int id;
    int calories_per_serving;
    int cook_time;
    int prep_time;
    int protein;
    int servings;
    string meal_type;
    string name;
    string cuisine;
    string description;
    string difficulty;
    vector<string>dietary_tags;
    vector<string>ingredients;
    vector<string>instructions;
};
