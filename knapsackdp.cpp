#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &weight, vector<int> &profit, int index, int cap, vector<vector<int>> dp)
{
    // If we have single item and which is less then capacity of the guven max capacity then include else dont
    // Considering from right to left
    if (index == 0)
    {
        // If the value is less then the maximum capacity
        if (weight[0] <= cap)
        {
            return profit[0];
        }
        else
        {
            return 0;
        }
    }
    // Ans is stored and return the answer
    if (dp[index][cap] != -1)
    {
        cout << index << "";
        return dp[index][cap];
    }

    dp[index][cap] = max(profit[index] + solve(weight, profit, index - 1, cap - weight[index], dp), solve(weight, profit, index - 1, cap, dp));
    return dp[index][cap];
}
int knapsack(vector<int> &weight, vector<int> &profit, int n, int maxweight)
{
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, -1));
    return solve(weight, profit, n - 1, maxweight, dp);
}
int main()
{

    vector<int> weight = {60,
                          100,
                          120};
    vector<int> profit = {60,
                          100,
                          120};
    int n = 3;
    int maxwei = 50;
    int ans = knapsack(weight, profit, n, maxwei);
    cout << ans << " ";
}

/*
Dp ALgorithm

Step 1 - make dp array if one state change then 1D dp and if 2 changes 2D dp
Step 2 - store the recursive call  in the array if the ans is stored then return the ans
Step 3 - if after base array contains ans
 */
