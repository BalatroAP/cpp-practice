#include "Recipe.h"

void tabbedFmtPrint(string title, string member) {
  fmt::print("\t{}: {}\n", title, member);
}

Recipe::Recipe(json j) {
  this->id = j["id"];
  this->name = j["name"];
  this->description = j["description"];
  this->difficulty = j["difficulty"];
  this->mealType = j["meal_type"];
  this->cuisine = j["cuisine"];
  this->dietaryTags = j["dietary_tags"];
  this->servings = j["servings"];
  this->prepTime = j["prep_time"];
  this->cookTime = j["cook_time"];
  this->caloriesPerServing = j["calories_per_serving"];
  this->protein = j["protein"];
  this->instructions = j["instructions"];
  this->ingredients = j["ingredients"];
}

void Recipe::displayRelevantData() {
  fmt::print("\n");
  this->displayMetaData();
  this->displayTimes();
  this->displayMacros();
  this->displayInstructions();
}

void Recipe::displayMetaData() {
  fmt::print("Dish Name: {}\n\n", this->name);
  tabbedFmtPrint("Description", this->description);
  fmt::print("\n");
  tabbedFmtPrint("Cuisine", this->cuisine);
  tabbedFmtPrint("Meal Type", this->mealType);
  tabbedFmtPrint("Difficulty", this->difficulty);
}
void Recipe::displayTimes() {
  fmt::print("Cook Times:\n\n");
  tabbedFmtPrint("Prep Time", to_string(this->prepTime));
  tabbedFmtPrint("Active Cooking Time", to_string(this->cookTime));
}
void Recipe::displayMacros() {
  fmt::print("Macros:\n\n");
  tabbedFmtPrint("Servings", to_string(this->servings));
  tabbedFmtPrint("Calories Per Serving", to_string(this->caloriesPerServing));
  tabbedFmtPrint("Protein", to_string(this->protein));
}
void Recipe::displayInstructions() {
  fmt::print("Instructions:\n\n");
  for (int i = 0, size = this->instructions.size(); i < size; i++) {
    fmt::print("\t{} - {}\n\n", i + 1, this->instructions[i]);
  }
}
void Recipe::displayIngredients() {}

// Getter

int Recipe::getId() { return this->id; }
int Recipe::getCaloriesPerServing() { return this->caloriesPerServing; }
int Recipe::getCookTime() { return this->cookTime; }
int Recipe::getPrepTime() { return this->prepTime; }
int Recipe::getProtein() { return this->protein; }
int Recipe::getServings() { return this->servings; }
string Recipe::getMealType() { return this->mealType; }
string Recipe::getName() { return this->name; }
string Recipe::getCuisine() { return this->cuisine; }
string Recipe::getDescription() { return this->description; }
string Recipe::getDifficulty() { return this->difficulty; }
vector<string> Recipe::getDietaryTags() { return this->dietaryTags; }
vector<string> Recipe::getInstructions() { return this->instructions; }
vector<json> Recipe::getIngredients() { return this->ingredients; }

// Setter

void Recipe::setId(int id) { this->id = id; }
void Recipe::setCaloriesPerServing(int caloriesPerServing) {
  this->caloriesPerServing = caloriesPerServing;
}
void Recipe::setCookTime(int cookTime) { this->cookTime = cookTime; }
void Recipe::setPrepTime(int prepTime) { this->prepTime = prepTime; }
void Recipe::setProtein(int protein) { this->protein = protein; }
void Recipe::setServings(int servings) { this->servings = servings; }
void Recipe::setMealType(string mealType) { this->mealType = mealType; }
void Recipe::setName(string name) { this->name = name; }
void Recipe::setCuisine(string cuisine) { this->cuisine = cuisine; }
void Recipe::setDescription(string description) {
  this->description = description;
}
void Recipe::setDifficulty(string difficulty) { this->difficulty = difficulty; }
void Recipe::setDietaryTags(vector<string> dietaryTags) {
  this->dietaryTags = dietaryTags;
}
void Recipe::setInstructions(vector<string> instructions) {
  this->instructions = instructions;
}
void Recipe::setIngredients(vector<json> ingredients) {
  this->ingredients = ingredients;
}
