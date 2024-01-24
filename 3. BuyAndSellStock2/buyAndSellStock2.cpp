#include <iostream>
#include <vector>
using namespace std;

int calculateProfit(vector<int> & prices)
{
    int i=0,profit=0;
    int n = prices.size();

    for (i=1; i<n; i++) {
        if(prices[i] > prices[i-1]) {
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}
int main()
{
    vector<int> price1 = {7,1,5,3,6,4};
    vector<int> price2 = {7,6,1,5,8,9,4,7,8};
    vector<int> price3 = {7,6,4,3,1};

    cout<<"Maximum profit with price1 : "<<calculateProfit(price1)<<endl;
    cout<<"Max profit with price2 : "<<calculateProfit(price2)<<endl;
    cout<<"Max profit with price3 : "<<calculateProfit(price3)<<endl;
    return 0;
}