// Best time to Buy and Sell Stock 1
// Andy Tseng, 3/16/18

#include <vector>
#include <iostream>

using namespace std;

int max_profit(vector<int>& prices) {
    int n = prices.size(); 
    int min_price = INT_MAX;
    int max_cost = 0;
    for(int i = 0; i < n; ++i) {
        if(min_price > prices[i]) {
            min_price = prices[i];
        } else if(prices[i] - min_price > max_cost) {
            max_cost = prices[i] - min_price;
        }
    }
    return max_cost;
}

int main() {
    vector<int> v1 = {7, 1, 5, 3, 6, 4};
    cout << max_profit(v1) << endl;
}
