#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void checkFileForMatches(
    std::string wordSearch,
    std::vector<std::vector<std::string>> delimitedStrings);
std::vector<std::vector<std::string>>
getDelimitedLines(std::vector<std::string> fileLines);
std::vector<std::string> getFileLines(std::string fileName);
std::vector<std::string> delimitLine(std::string line, char delimiter);
std::string joinVecToString(std::vector<std::string> line);
bool isWordInLine(std::string word, std::vector<std::string> line);

int main(int argc, char *argv[]) {
  std::vector<std::string> fileLines = getFileLines(argv[2]);
  std::vector<std::vector<std::string>> delimitedStrings =
      getDelimitedLines(fileLines);

  checkFileForMatches(argv[1], delimitedStrings);

  return 0;
}

void checkFileForMatches(
    std::string wordSearch,
    std::vector<std::vector<std::string>> delimitedStrings) {
  int count = 0;

  for (int i = 0, outSize = delimitedStrings.size(); i < outSize; i++) {

    if (isWordInLine(wordSearch, delimitedStrings[i])) {
      std::cout << "Line " << i + 1 << " "
                << joinVecToString(delimitedStrings[i]) << "\n\n";
      count++;
    }
  }

  std::cout << "Occurances: " << count << '\n';
}

std::vector<std::string> getFileLines(std::string fileName) {
  std::vector<std::string> fileLines;
  std::string line;
  std::fstream file;

  file.open(fileName, std::ios::in);

  while (std::getline(file, line)) {
    fileLines.push_back(line);
  }

  file.close();

  return fileLines;
}

std::vector<std::vector<std::string>>
getDelimitedLines(std::vector<std::string> fileLines) {
  std::vector<std::vector<std::string>> delimitedStrings;

  for (int i = 0, size = fileLines.size(); i < size; i++) {
    delimitedStrings.push_back(delimitLine(fileLines[i], ' '));
  }

  return delimitedStrings;
}

std::vector<std::string> delimitLine(std::string line, char delimiter) {
  std::vector<std::string> delimitedStrings;
  std::stringstream ss(line);
  std::string token;

  while (getline(ss, token, delimiter)) {
    delimitedStrings.push_back(token);
  }

  return delimitedStrings;
}

bool isWordInLine(std::string word, std::vector<std::string> line) {
  for (int i = 0, size = line.size(); i < size; i++) {
    if (line[i].find(word) == 0) {
      return true;
    }
  }

  return false;
}

std::string joinVecToString(std::vector<std::string> line) {
  std::string newString;

  newString.append(line[0]);
  for (int i = 1, size = line.size(); i < size; i++) {
    newString.append(" ");
    newString.append(line[i]);
  }

  return newString;
}
