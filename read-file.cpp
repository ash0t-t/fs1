#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void printFileContent(const std::string &filePath)
{
  std::ifstream file(filePath, std::ios::in);

  if (!file.is_open())
  {
    std::cerr << "can open file " << filePath << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string line;
  while (std::getline(file, line))
  {
    std::cout << line << std::endl;
  }

  file.close();
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "./read-file <file_name>" << std::endl;
    return EXIT_FAILURE;
  }

  std::string filePath = argv[1];
  printFileContent(filePath);

  return EXIT_SUCCESS;
}