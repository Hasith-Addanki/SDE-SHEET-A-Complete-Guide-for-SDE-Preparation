// Given an array arr[] of N non-negative integers representing
// the height of blocks. If width of each block is 1, compute how
// much water can be trapped between the blocks during the rainy season.

// Example 1:

// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        stack<int> s_mr, s_ml;
        vector<int> mr(n);
        mr[n - 1] = arr[n - 1];
        vector<int> ml(n);
        ml[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            ml[i] = max(ml[i - 1], arr[i]);
            // mr[n-i-1] = max(mr[n-i], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            mr[i] = max(mr[i + 1], arr[i]);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += (min(mr[i], ml[i]) - arr[i]);
        return ans;
    }
};

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        stack<int> s;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {

            while ((!s.empty()) && (arr[s.top()] < arr[i]))
            {
                int height = arr[s.top()];
                s.pop();
                if (s.empty())
                    break;
                int dist = i - s.top() - 1;
                int minHeight = min(arr[i], arr[s.top()]) - height;
                ans += (minHeight * dist);
            }

            s.push(i);
        }

        return ans;
    }
};

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        int l = 0, r = n - 1, lmax = 0, rmax = n - 1;
        long long ans = 0;
        while (l <= r)
        {
            if (arr[lmax] < arr[rmax])
            {
                if (arr[l] < arr[lmax])
                {
                    ans += arr[lmax] - arr[l];
                    l++;
                }
                else
                {
                    lmax = l;
                    l++;
                }
            }
            else
            {
                if (arr[r] < arr[rmax])
                {
                    ans += arr[rmax] - arr[r];
                    r--;
                }
                else
                {
                    rmax = r;
                    r--;
                }
            }
        }

        return ans;
    }
};