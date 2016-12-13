#ifndef TRADE_H
#define TRADE_H
#include <numeric>
#include <utility>

// TODO your code goes here:
template<class InputIt>
int bestProfit(InputIt a, InputIt b) {
    int currentMinInt = *a;
    int currentMaxProfit = 0;
    std::accumulate(a, b, 0,
                        [&currentMinInt, &currentMaxProfit] (const int i, const int j) {
                            int profit = j - currentMinInt;
                            if (profit > currentMaxProfit) currentMaxProfit = profit;
                            if (j < currentMinInt) currentMinInt = j;
                            return i;
                        });
    return currentMaxProfit;
}
// Don't write any code below this line

#endif
