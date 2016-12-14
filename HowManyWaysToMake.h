#ifndef HOW_MANY_WAYS_TO_MAKE_H
#define HOW_MANY_WAYS_TO_MAKE_H
#include <numeric>
#include <utility>

// TODO: Your code goes here
template<class InputIt>
int howManyWaysToMake (InputIt a, InputIt b, int amountOfMoney) {
    if (amountOfMoney == 0) return 1;
    else if (amountOfMoney < 0) return 0;
    else if (a == b) return 0;
    else return howManyWaysToMake(a, b, amountOfMoney - *a) + howManyWaysToMake(++a, b, amountOfMoney);
}
// Do not write any code below this line

#endif
