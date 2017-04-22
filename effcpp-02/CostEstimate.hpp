#ifndef COSTESTIMATE_HPP
#define COSTESTIMATE_HPP

class CostEstimate
{
public:
   CostEstimate();

   void estimate();

private:
   static const double FudgeFactor;
};

#endif // COSTESTIMATE_HPP
