/* 6.6 BUY AND SELL A STOCK ONCE
Write a program that takes an array denoting the daily stock price, and returns the
maximum profit that could be made by buying and then selling one share of that
stock.
*/

#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  double lowestSoFar = std::numeric_limits<double>::max();
  double maxProfit = 0.0;
  for(const double price : prices){
    if(price < lowestSoFar){
      lowestSoFar = price;
    }
    else if(price - lowestSoFar > maxProfit){
      maxProfit = price - lowestSoFar;
    }
  }
  return maxProfit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
