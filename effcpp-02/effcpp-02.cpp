#include <iostream>

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
   std::cout << "ConstAuthorName = \"Rednaxela Reiam\"; // error! assignment of read-only variable";

   return 0;
}
