#ifndef TRADE_H
#define TRADE_H
#include <numeric>
#include <utility>
#include <iostream>

// TODO your code goes here:
template<class InputIt>
int bestProfit(InputIt a, InputIt b) {
    std::pair<int, int> currMax (*a, 0); //pair containing current min int as key and current max profit as value
    std::accumulate(a, b, 0,
                        [&currMax] (const int i, const int j) {
                            int profit = j - currMax.first;
                            if (profit > currMax.second) currMax.second = profit;
                            if (j < currMax.first) currMax.first = j;
                            return i;
                        });
    return currMax.second;
}
// Don't write any code below this line

#endif
