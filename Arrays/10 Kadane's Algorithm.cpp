// Given an array Arr[] of N integers. Find the contiguous
//  sub-array(containing at least one number) which has the
//   maximum sum and return its sum.


// Example 1:

// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long sum = INT_MIN;
        long long csum = 0;
        for(int i=0;i<n;i++){
            csum += arr[i];
            sum = max(sum, csum);
            if(csum<0) csum = 0;
  
        }
        return sum;
    }
};