#include "GamePlayer.hpp"
#include <iostream>

GamePlayer::GamePlayer()
{
}

void GamePlayer::play()
{
   int cnt = 0;
   while (cnt++ < NumTurns)
   {
      std::cout << "turn " << cnt << " -> result: " << cnt*2 << "\n";
   }
}

GamePlayer2::GamePlayer2()
{

}

void GamePlayer2::play()
{
   std::cout << "Playing with \"the enum hack\":\n";
   int cnt = 0;
   while (cnt++ < NumTurns)
   {
      std::cout << "turn " << cnt << " -> result: " << cnt*3<< "\n";
   }
}
