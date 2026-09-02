#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

// #include "Recipe.h"

using namespace std;
using namespace nlohmann;

string getHeader();
size_t write_to_string(void *ptr, size_t size, size_t count, void *stream);

int main(void) {
  json recipe;
  CURL *curl = curl_easy_init();
  string response;

  struct curl_slist *list = NULL;

  if (curl) {
    CURLcode result;
    curl_easy_setopt(
        curl, CURLOPT_URL,
        "https://recipeapi.io/api/v1/recipes/random?lang=en&meal_type=main");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    list = curl_slist_append(list, getHeader().c_str());

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

    result = curl_easy_perform(curl);
    recipe = json::parse(response);

    curl_slist_free_all(list);
    curl_easy_cleanup(curl);
  }

  cout << setw(recipe.size()) << recipe << '\n';
}

string getHeader() {
  string header;
  fstream file;

  file.open("recipeprivatekey.txt");
  getline(file, header);
  file.close();

  cout << "[DEBUG] " << header << '\n';

  return header;
}
size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
  ((string *)stream)->append((char *)ptr, 0, size * count);
  return size * count;
}
