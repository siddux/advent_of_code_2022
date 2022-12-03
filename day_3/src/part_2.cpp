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
  int priorities = 0;
  
  int line_group = 0;

  
  std::map<char,int> items;
  std::map<char, int>::iterator it;

  while(getline (data_file,data_line)) 
  {
    if (line_group > 2)
    {
      for (auto& it : items) 
      {
        if (it.second == 3) {
          priorities += get_priority(it.first);
        }
      }
      items.clear();
      line_group = 0;   
    }
    for (int j = 0; j < data_line.length(); j++)
    {
      if ( line_group == 0){
        items.insert(std::make_pair(data_line.at(j), 1));
      } else
      {
        it = items.find(data_line.at(j));
        // key already present on the map
        if (it != items.end()) 
        {
          if ((it->second == 1 && line_group == 1)){
            it->second++;    // increment map's value for key `c`
          }
          if ((it->second == 2 && line_group == 2)){
            it->second++;    // increment map's value for key `c`
          }
        }
      }
    }
    line_group++;
  }

  for (auto& it : items) 
  {
    if (it.second == 3) {
      priorities += get_priority(it.first);
    }
  }

  std::cout << "The total priorities are: " << priorities << '\n'; 
}