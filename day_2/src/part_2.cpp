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
        result = 1;
        break;
      case 'B':
        result = 2;
        break;
      case 'C':
        result = 3;
        break;
    }
  return result;
}

int convert_result(char play)
{
  int result;
  switch (play)
    {
      case 'X':
        result = 0;
        break;
      case 'Y':
        result = 3;
        break;
      case 'Z':
        result = 6;
        break;
    }
  return result;
}

int compute_play(int result, int opponent_play)
{
  if(result == 3){return opponent_play;}

  if(result == 0 && opponent_play == 1){return 3;}
  if(result == 0 && opponent_play == 2){return 1;}
  if(result == 0 && opponent_play == 3){return 2;}

  if(result == 6 && opponent_play == 1){return 2;}
  if(result == 6 && opponent_play == 2){return 3;}
  if(result == 6 && opponent_play == 3){return 1;}
}

int main()
{
  std::ifstream data_file("../data.txt");
  std::string data_line;
  int score = 0;

  while(getline (data_file,data_line)) 
  {
    int opponent_play = convert_play(data_line.at(0));
    int result = convert_result(data_line.at(2));

    score += (result + compute_play(result, opponent_play));
  }

  std::cout << "The total score is: " << score << '\n'; 
}