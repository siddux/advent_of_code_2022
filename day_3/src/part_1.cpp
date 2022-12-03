#include <fstream>
#include <iostream>
#include <map>
#include <vector>

int get_priority(char c)
{
  int i = static_cast<int>(c);

  if (i > 95)
  {
    return i-96;
  } else
  {
    return i-38;
  }
}

int main()
{
  std::ifstream data_file("../data.txt");
  std::string data_line;
  std::string rucksack_1, rucksack_2;
  int priorities = 0;

  while(getline (data_file,data_line)) 
  {
    rucksack_1 = data_line.substr(0, data_line.length()/2);
    rucksack_2 = data_line.substr(data_line.length()/2);

    std::map<char,int> items;
    std::map<char,int>::iterator it;
    for(int i = 0; i < rucksack_1.length(); i++)
    {
      items.insert ( std::pair<char,int>(rucksack_1.at(i),100) );
    }

    for(int i = 0; i < rucksack_2.length(); i++)
    {
      it = items.find(rucksack_2.at(i));
      if (it != items.end())
      {
        priorities += get_priority(rucksack_2.at(i));
        break;
      }
    }

  }

  std::cout << "The total priorities are: " << priorities << '\n'; 
}