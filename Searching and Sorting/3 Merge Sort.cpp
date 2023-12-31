// Given an array arr[], its starting position l and its
// ending position r. Sort the array using merge sort algorithm.
// Example 1:

// Input:
// N = 5
// arr[] = {4 1 3 9 7}
// Output:
// 1 3 4 7 9

class Solution
{
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int s1 = m - l + 1;
        int s2 = r - m;
        int[] arr1 = new int[s1];
        int[] arr2 = new int[s2];
        for (int i = 0; i < s1; i++)
            arr1[i] = arr[l + i];

        for (int i = 0; i < s2; i++)
            arr2[i] = arr[m + i + 1];

        int j = 0;
        int p = 0;
        int q = 0;
        while (j < s1 + s2 && p < s1 && q < s2)
        {
            if (arr1[p] < arr2[q])
            {
                arr[j + l] = arr1[p];
                j++;
                p++;
            }
            else
            {
                arr[j + l] = arr2[q];
                q++;
                j++;
            }
        }

        while (p < s1)
        {
            arr[j + l] = arr1[p];
            p++;
            j++;
        }
        while (q < s2)
        {
            arr[j + l] = arr2[q];
            q++;
            j++;
        }
    }
    void mergeSort(int arr[], int l, int r)
    {
        // code here
        if (l >= r)
            return;
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}