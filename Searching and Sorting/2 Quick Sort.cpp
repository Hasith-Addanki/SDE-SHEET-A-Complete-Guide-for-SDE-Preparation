// Quick Sort is a Divide and Conquer algorithm. It picks
// an element as a pivot and partitions the given array
// around the picked pivot.
// Given an array arr[], its starting position is
// low (the index of the array) and its ending position is
// high(the index of the array).

// Note: The low and high are inclusive.

// Implement the partition() and quickSort() functions to sort the array.

// Example 1:

// Input:
// N = 5
// arr[] = { 4, 1, 3, 9, 7}
// Output:
// 1 3 4 7 9
class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low >= high)
            return;
        int partitionIndex = partition(arr, low, high);
        int temp = arr[partitionIndex];
        arr[partitionIndex] = arr[high];
        arr[high] = temp;
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }

public:
    int partition(int arr[], int low, int high)
    {
        // Your code here
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] > pivot)
                continue;

            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        return i + 1;
    }
};