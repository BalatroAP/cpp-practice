#pragma once 

#include <fmt/base.h>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using namespace nlohmann;
using namespace std;

class Recipe {
public:
  Recipe(json j);

  // Display;
  void displayRelevantData();
  void displayMetaData();
  void displayTimes();
  void displayMacros();
  void displayInstructions();
  void displayIngredients();

  // Getter
  int getId();
  int getCaloriesPerServing();
  int getCookTime();
  int getPrepTime();
  int getProtein();
  int getServings();
  string getMealType();
  string getName();
  string getCuisine();
  string getDescription();
  string getDifficulty();
  vector<string> getDietaryTags();
  vector<string> getInstructions();
  vector<json> getIngredients();

  // Setter
  void setId(int id);
  void setCaloriesPerServing(int caloriesPerServing);
  void setCookTime(int cookTime);
  void setPrepTime(int prepTime);
  void setProtein(int protein);
  void setServings(int servings);
  void setMealType(string mealType);
  void setName(string name);
  void setCuisine(string cuisine);
  void setDescription(string description);
  void setDifficulty(string difficulty);
  void setDietaryTags(vector<string> dietaryTags);
  void setInstructions(vector<string> instructions);
  void setIngredients(vector<json> ingredients);

private:
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
  vector<string> dietaryTags;
  vector<string> instructions;
  vector<json> ingredients;
};
