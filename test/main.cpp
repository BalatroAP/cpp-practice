#include <curl/curl.h>
#include <fstream>
#include <string>

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream);

int main(void) {
  std::string data;
  std::fstream file("text.txt", std::ios::out | std::ios::app);
  CURL *curl = curl_easy_init();

  if (curl) {
    CURLcode result;
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://steamcommunity.com/market/"
                     "orderbook?q=Load&qp=[730%2C%22Revolution+Case%22]");
  }
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

  curl_easy_cleanup(curl);
}

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
  ((std::string *)stream)->append((char *)ptr, 0, size * count);
  return size * count;
}
