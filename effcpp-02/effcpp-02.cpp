#include <iostream>
#include "CostEstimate.hpp"
#include "GamePlayer.hpp"
#include "Max.hpp"

void f(int x)
{
   std::cout << "called f with " << x << "\n";
}

// call f with the maximum of a and b
#define CALL_WITH_MAX(a,b) f((a > b) ? a : b)

int main(void)
{
   // each ASPECT_RATIO may be removed by preprocessor (replaced by 1.653)
   #define ASPECT_RATIO 1.653
   // better use a constant:
   const double AspectRatio = 1.653;
   std::cout << "ASPECT_RATIO is " << ASPECT_RATIO << " (#define)\n";
   std::cout << "AspectRatio is " << AspectRatio << " (const dobule)\n";

   // be careful with strings
   #define AUTHOR_NAME "Alexander Maier"
   const char * AuthorName = "Alexander Maier";
   std::cout << "AUTHOR_NAME is " << AUTHOR_NAME << " (#define)\n";
   std::cout << "AuthorName is " << AuthorName << " (const char *)\n";

   AuthorName = "Rednaxela Reiam"; // OK: pointer is not const!
   std::cout << "AuthorName is " << AuthorName << " (const char *)\n";

   // make pointer const too
   const char * const ConstAuthorName = "Alexander Maier";
   std::cout << "ConstAuthorName is " << ConstAuthorName << " (const char * const)\n";
//   ConstAuthorName = "Rednaxela Reiam"; // error! assignment of read-only variable
   std::cout << "ConstAuthorName = \"Rednaxela Reiam\"; // error! assignment of read-only variable \n";

   // let's test class constants
   std::cout << "Playing GamePlayer:\n";
   GamePlayer gp;
   gp.play();

   // and estimate some costs
   std::cout << "Cost estimate:\n";
   CostEstimate ce;
   ce.estimate();

   // play with "the enum hack" version
   GamePlayer2 gp2;
   gp2.play();

   // now do some stuff with macro vs. template
   int a = 5, b = 0;
   CALL_WITH_MAX(a, b); // fine
   std::cout << "a is now " << a << " and b is " << b << "\n";
   CALL_WITH_MAX(++a, b);
   std::cout << "a is now " << a << " and b is " << b << "\n";
   // output: a is now 7 and b is 0 - huch? 7? each a gets replaced by ++a -> 5->7
   b = 10;
   CALL_WITH_MAX(++a, b);
   std::cout << "a is now " << a << " and b is " << b << "\n";
   // output: a is now 8 and b is 10 - huch? 8? a gets only incremented once now
   //         because b is greater (so ++a gets only called once)

   // instead: use an inline template function instead
   std::cout << "Same calls with template function:\n";
   a = 5;
   b = 0;
   callWithMax(a, b);
   std::cout << "a is now " << a << " and b is " << b << "\n";
   callWithMax(++a, b);
   std::cout << "a is now " << a << " and b is " << b << "\n";
   b = 10;
   callWithMax(++a, b);
   std::cout << "a is now " << a << " and b is " << b << "\n";
   return 0;
}
