#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

int convert_play(char play)
{
  int result;
  switch (play)
    {
      case 'A':
      case 'X':
        result = 1;
        break;
      case 'B':
      case 'Y':
        result = 2;
        break;
      case 'C':
      case 'Z':
        result = 3;
        break;
    }
  return result;
}

int compute_outcome(int my_play, int opponent_play)
{
  if(my_play == opponent_play){return 3;}

  if(my_play == 1){
    if(opponent_play == 2){return 0;}
    return 6;
  }

  if(my_play == 2){
    if(opponent_play == 3){return 0;}
    return 6;
  }

  if(my_play == 3){
    if(opponent_play == 1){return 0;}
    return 6;
  }
}

int main()
{
  std::ifstream data_file("../data.txt");
  std::string data_line;
  int score = 0;

  while(getline (data_file,data_line)) 
  {
    int opponent_play = convert_play(data_line.at(0));
    int my_play = convert_play(data_line.at(2));

    score += (my_play + compute_outcome(my_play, opponent_play));

  }

  std::cout << "The total score is: " << score << '\n'; 
}