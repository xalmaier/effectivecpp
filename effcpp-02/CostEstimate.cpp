#include "CostEstimate.hpp"
#include <iostream>

// initialize static constants
const double CostEstimate::FudgeFactor = 1.35;

CostEstimate::CostEstimate()
{

}

void CostEstimate::estimate()
{
   std::cout << "Estimated fudge factor: " << FudgeFactor << "\n";
}
