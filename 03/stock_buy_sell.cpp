#include <iostream>
#include <vector>

using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5

int max_profit(vector<int> num)
{
    // solution - assume each of the ith element is the selling day, start from i = 1

    int max_profit = 0;
    int min_price = num[0];

    for (int i = 1; i < num.size(); i++)
    {
        int max_curr = 0;
        if (num[i] > min(min_price, num[i - 1]))
        {
            max_curr = num[i] - min(min_price, num[i - 1]);
            max_profit = max(max_profit, max_curr);
        }
        min_price = min(min_price, num[i]);
    }

    return max_profit;
}

int main()
{
    vector<int> days = {7, 1, 5, 3, 6, 4};

    int max_prof = max_profit(days);
    cout << max_prof << endl;

    return 0;
}
