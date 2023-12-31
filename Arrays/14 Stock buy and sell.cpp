// The cost of stock on each day is given in an array A[] of size N.
// Find all the segments of days on which you buy and sell the stock
// so that in between those days for which profit can be generated.
// Note: Since there can be multiple solutions, the driver code will
// print 1 if your answer is correct, otherwise, it will return 0.
// In case there's no profit the driver code will print the string
// "No Profit" for a correct solution.

// Example 1:

// Input:
// N = 7
// A[] = {100,180,260,310,40,535,695}
// Output:
// 1
// Explanation:
// One possible solution is (0 3) (4 6)
// We can buy stock on day 0,
// and sell it on 3rd day, which will
// give us maximum profit. Now, we buy
// stock on day 4 and sell it on day 6.
// Example 2:

// Input:
// N = 5
// A[] = {4,2,2,2,4}
// Output:
// 1
// Explanation:
// There are multiple possible solutions.
// one of them is (3 4)
// We can buy stock on day 3,
// and sell it on 4th day, which will
// give us maximum profit.
// User function template for C++

class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        // code here
        vector<vector<int>> ans;

        int curr_inv = 0, curr_sell = 0;

        for (int i = 1; i < n; i++)
        {
            if (A[curr_sell] < A[i])
                curr_sell = i;
            else
            {
                if (curr_sell > curr_inv)
                {
                    vector<int> temp(2);
                    temp[0] = curr_inv;
                    temp[1] = curr_sell;
                    ans.push_back(temp);
                }
                curr_inv = i;
                curr_sell = i;
            }
        }

        if (curr_sell > curr_inv)
        {
            vector<int> temp(2);
            temp[0] = curr_inv;
            temp[1] = curr_sell;
            ans.push_back(temp);
        }
        return ans;
    }
};