class Solution
{
public:
    int missingNumber(vector<int> &array, int n)
    {
        // Your code goes here
        /*int ans = n;
        for(int i=0;i<n-1;i++){
            ans += i+1 - array[i];
        }
        return ans;
        */
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans ^= i;
        for (int i = 0; i < n - 1; i++)
            ans ^= array[i];
        return ans;
    }
};