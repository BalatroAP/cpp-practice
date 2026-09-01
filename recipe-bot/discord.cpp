#include <dpp/dpp.h>
#include <fstream>
#include <iostream>
#include <string>

std::string getKeys();

int main(void) {
  std::string key = getKeys();

  dpp::cluster bot(key);

  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([](const dpp::slashcommand_t &event) {
    if (event.command.get_command_name() == "recipe") {
      dpp::embed embed =
          dpp::embed()
              .set_color(dpp::colors::red)
              .set_title("SOME RECIPE")
              .set_url("https://youtube.com")
              .set_description("This is some recipe")
              .set_thumbnail("https://www.startpage.com/av/"
                             "proxy-image?piurl=https%3A%2F%2Fi.kym-cdn.com%"
                             "2Fentries%2Ficons%2Foriginal%2F000%2F051%2F089%"
                             "2Fcarmy_screaming.jpg&sp="
                             "1788271310Tc3fc12caa92fcfd643c5e7f0303a9e278237ad"
                             "d5586de26a361086c14f26caaf");

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

std::string getKeys() {
  std::fstream file;
  std::string line;
  file.open("api.txt", std::ios::in);
  std::getline(file, line);
  return line;
}
