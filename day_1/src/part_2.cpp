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
  int total_calories;

  for(int i = 0; i < 3; i++)
  {
    result = std::max_element(elves_calories.begin(), elves_calories.end());
    total_calories += *result;
    elves_calories.erase(std::remove(elves_calories.begin(), \
                         elves_calories.end(), *result), elves_calories.end());
  }
  
  std::cout << "The top 3 elves are carrying a total of "
            << total_calories << " calories \n";
}