#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

int main()
{
  std::ifstream data_file("../data.txt");
  std::vector<int> elves_calories;
  std::string data_line;
  int calories = 0;

  while(getline (data_file,data_line)) 
  {
    
    if(!data_line.empty())
    {
      calories += stoi(data_line);
    } 
    else
    {
      elves_calories.push_back(calories);
      calories = 0;
    }
  }

  std::vector<int>::iterator result;
  result = std::max_element(elves_calories.begin(), elves_calories.end());
  std::cout << "The elf carrying more calories is the number "
            << std::distance(elves_calories.begin(), result) + 1
            << " with a total of " << *result << " calories \n";
}