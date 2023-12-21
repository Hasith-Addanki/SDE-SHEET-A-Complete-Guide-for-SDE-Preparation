// Given an array A of n positive numbers. 
// The task is to find the first equilibrium point in an array. 
// Equilibrium point in an array is an index (or position) such that 
// the sum of all elements before that index is same as sum of elements after it.

// Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 
// Input: 
// n = 5 
// A[] = {1,3,5,2,2} 
// Output: 
// 3 
// Explanation:  
// equilibrium point is at position 3 as sum of elements before
//  it (1+3) = sum of elements after it (2+2). 
// Your Task:
// The task is to complete the function equilibriumPoint() which takes 
// the array and n as input parameters and returns the point of equilibrium. 

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 105
// 1 <= A[i] <= 109
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long sum = 0;
        for(int i=0;i<n;i++)
            sum += a[i];
        
        long long running_sum = 0;
        
        if(n==1) return 1;
        
        for(int i=1;i<n;i++){
            
            running_sum += a[i-1];
            if(sum-running_sum-a[i] == running_sum)
                return i+1;
        }
        
        return -1;
    }

};