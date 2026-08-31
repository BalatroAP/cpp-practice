#include "Recipe.h"

Recipe::Recipe(json j) {
  this->id = j["id"];
  this->name = j["name"];
  this->description = j["description"];
  this->difficulty = j["difficulty"];
  this->mealType= j["meal_type"];
  this->cuisine = j["cuisine"];
  this->dietaryTags = j["dietary_tags"];
  this->servings = j["servings"];
  this->prepTime = j["prep_time"];
  this->cookTime = j["cook_time"];
  this->caloriesPerServing = j["calories_per_serving"];
  this->protein = j["protein"];
  this->instructions = j["instructions"];
}
