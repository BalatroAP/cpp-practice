#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using namespace nlohmann;
using namespace std;

class Recipe {
  public:
    Recipe(json j);

    int id;
    int caloriesPerServing;
    int cookTime;
    int prepTime;
    int protein;
    int servings;
    string mealType;
    string name;
    string cuisine;
    string description;
    string difficulty;
    vector<string>dietaryTags;
    vector<string>ingredients;
    vector<string>instructions;
};
