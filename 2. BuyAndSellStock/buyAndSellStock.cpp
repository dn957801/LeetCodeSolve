#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int min_value = INT_MAX;
    int profit = 0;

    /* Caluclate the profit by following the below logic.
       Find the first minimum value, and then subtract it from
       next highest selling price to get the max profit.
       Update the profit only when current_value - previous value is
       bigger than current profit
       */
    for(auto price:prices){
        min_value = min(price, min_value);
        profit = max(profit, price - min_value);
    }

    return profit;
}

int main()
{
    vector<int> pricesWeek1 = {7,1,5,3,6,4};
    vector<int> pricesWeek2 = {6,5,4,3,2,1};

    cout<<"Max profit from Week 1 : "<<maxProfit(pricesWeek1)<<endl;
    cout<<"Max profit from Week 2 : "<<maxProfit(pricesWeek2)<<endl;

    return 0;
}