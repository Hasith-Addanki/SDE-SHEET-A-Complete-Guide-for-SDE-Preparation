// Given a list of non negative integers, arrange them in such a
// manner that they form the largest number possible.The result is
// going to be very large, hence return the result in the form of a
// string.

// Example 1:

// Input:
// N = 5
// Arr[] = {3, 30, 34, 5, 9}
// Output: 9534330
// Explanation: Given numbers are {3, 30, 34,
// 5, 9}, the arrangement 9534330 gives the
// largest value.
// Example 2:

// Input:
// N = 4
// Arr[] = {54, 546, 548, 60}
// Output: 6054854654
// Explanation: Given numbers are {54, 546,
// 548, 60}, the arrangement 6054854654
// gives the largest value.
// User function template for C++
bool myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two
    // formed numbers is greater
    return XY.compare(YX) > 0 ? true : false;
}

class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    string printLargest(vector<string> &arr)
    {
        // code here
        sort(arr.begin(), arr.end(), myCompare);
        int n = arr.size();

        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += arr[i];
        }
        return ans;
    }
};