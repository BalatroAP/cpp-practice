#include <curl/curl.h>
#include <dpp/dpp.h>
#include <fstream>

#include "Recipe.h"

string getKeys();
string getHeader();
json getRecipeJsonData();
size_t write_to_string(void *ptr, size_t size, size_t count, void *stream);

int main(void) {
  string key = getKeys();

  dpp::cluster bot(key);

  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([](const dpp::slashcommand_t &event) {
    if (event.command.get_command_name() == "recipe") {
      json j = getRecipeJsonData()["data"].get<json>();
      Recipe recipe(j);

      dpp::embed embed =
          dpp::embed()
              .set_color(dpp::colors::red)
              .set_title(recipe.getName())
              .set_description(recipe.getDescription())
              .add_field("Difficulty", recipe.getDifficulty())
              .add_field("Cuisine", recipe.getCuisine())
              .add_field("Marcos", to_string(recipe.getCaloriesPerServing()))
              .set_image("https://i.pinimg.com/1200x/8a/cf/03/"
                         "8acf030195dfa6333f4543dfafa4acbb.jpg")
              .set_timestamp(time(0))
              .set_footer(dpp::embed_footer().set_text("Every Second Counts!"));

      dpp::message msg(event.command.channel_id, embed);

      event.reply(msg);
    }
  });

  bot.on_ready([&bot](const dpp::ready_t &event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot.global_command_create(
          dpp::slashcommand("recipe", "Get a random recipe", bot.me.id));
    }
  });

  bot.start(dpp::st_wait);
}

string getKeys() {
  fstream file;
  string line;
  file.open("api.txt", ios::in);
  getline(file, line);
  file.close();
  return line;
}

string getHeader() {
  string header;
  fstream file;

  file.open("recipeprivatekey.txt");
  getline(file, header);
  file.close();

  return header;
}

json getRecipeJsonData() {
  CURL *curl = curl_easy_init();
  json j;

  struct curl_slist *list = NULL;

  if (curl) {
    CURLcode result;
    string response;
    curl_easy_setopt(
        curl, CURLOPT_URL,
        "https://recipeapi.io/api/v1/recipes/random?lang=en&meal_type=main");

    list = curl_slist_append(list, getHeader().c_str());

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    result = curl_easy_perform(curl);
    j = json::parse(response);

    curl_slist_free_all(list);
    curl_easy_cleanup(curl);
  }

  return j;
}

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
  ((string *)stream)->append((char *)ptr, 0, size * count);
  return size * count;
}
