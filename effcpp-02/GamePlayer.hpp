#ifndef GAMEPLAYER_HPP
#define GAMEPLAYER_HPP

class GamePlayer
{
public:
   GamePlayer();

   void play();

private:
   static const int NumTurns = 5;
   int scores[NumTurns];
};

class GamePlayer2
{
public:
   GamePlayer2();

   void play();

private:
   enum { NumTurns = 5 };
   int scores[NumTurns];

};

#endif // GAMEPLAYER_HPP
