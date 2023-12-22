// Given an array arr[] of positive integers of size N.
// Reverse every sub-array group of size K.
// Input:
// N = 5, K = 3
// arr[] = {1,2,3,4,5}
// Output: 3 2 1 5 4
// Explanation: First group consists of elements
// 1, 2, 3. Second group consists of 4,5.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
class Solution
{
public:
    // Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        // code here
        for (int i = 0; i + k <= n;)
        {
            for (int j = 0; j < k / 2; j++)
            {
                swap(arr[j + i], arr[i + k - j - 1]);
            }
            i += k;
        }
        int rem = n % k;
        if (rem > 0)
        {
            for (int j = 0; j < rem / 2; j++)
            {
                swap(arr[n - rem + j], arr[n - j - 1]);
            }
        }
    }
};