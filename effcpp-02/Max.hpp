#ifndef MAX_HPP
#define MAX_HPP

template<typename T>
void g(const T & a)
{
   std::cout << "called g with " << a << "\n";
}

template<typename T>
inline void callWithMax(const T & a, const T & b)
{
   g(a > b ? a : b);
}

#endif // MAX_HPP
