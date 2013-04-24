#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::ifstream filename("Mats.txt");
  std::string line;

  while (std::getline(filename, line))
    {
      ;
    }
  return 0;
}
