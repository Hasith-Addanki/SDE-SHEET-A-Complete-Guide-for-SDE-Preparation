// Given an unsorted array A of size N that contains only non 
// negative integers, find a continuous sub-array that adds to a 
// given number S and return the left and right index(1-based indexing) 
// of that subarray.

// In case of multiple subarrays, return the subarray indexes which 
// come first on moving from left to right.

// Note:- You have to return an ArrayList consisting of two elements
// left and right. In case no such subarray exists return an array 
// consisting of element -1.

// Example 1:

// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 2 4
// Explanation: The sum of elements 
// from 2nd position to 4th position 
// is 12.
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int start = 0, last =0;
        long long sum = 0;
        vector<int> ans;
        bool flag = false;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            if(sum>=s){
                last = i;
                while(sum>s && start<last){
                    sum -= arr[start];
                    ++start;
                }
                if(sum==s ){
                    flag = true;
                    ans.push_back(start+1);
                    ans.push_back(last+1);
                    break;
                }
            }
        }    
        
        if(flag == false)
            ans.push_back(-1);
        return ans;
    }
};