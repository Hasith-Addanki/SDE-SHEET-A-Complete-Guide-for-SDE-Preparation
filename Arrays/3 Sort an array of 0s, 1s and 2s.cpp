// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// Input:
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 10^6
// 0 <= A[i] <= 2
class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (low < high && mid < n)
        {
            if (a[mid] == 0)
            {
                swap(a[mid], a[low]);
                mid++;
                low++;
            }
            else if (a[mid] == 2)
            {
                swap(a[mid], a[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};