#include <bits/stdc++.h>
using namespace std;

int count1 = 0;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Merge two subarrays leftArray and rightArray into arr
void merge(int arr[], int const left, int const mid, int const right)
{
    int const subarrayone = mid - left + 1;
    int const subarraytwo = right - mid;

    auto *leftArray = new int[subarrayone];
    auto *rightArray = new int[subarraytwo];

    for (int i = 0; i < subarrayone; i++)
    {
        count1++;
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < subarraytwo; j++)
    {
        count1++;
        rightArray[j] = arr[mid + 1 + j];
    }

    // Maintain current index of sub-arrays and main array
    int indexofsubarrayone = 0, indexofsubarraytwo = 0, indexofmergedarray = left;

    // Until we reach either end of either leftArray or rightArray, pick larger among
    // elements leftArray and rightArray and place them in the correct position at arr[left..right]
    while (indexofsubarrayone < subarrayone && indexofsubarraytwo < subarraytwo)
    {
        // count1++;
        if (leftArray[indexofsubarrayone] <= rightArray[indexofsubarraytwo])
        {
            arr[indexofmergedarray] = leftArray[indexofsubarrayone];
            indexofsubarrayone++;
        }
        else
        {
            arr[indexofmergedarray] = rightArray[indexofsubarraytwo];
            indexofsubarraytwo++;
        }
        indexofmergedarray++;
    }

    // When we run out of elements in either leftArray or rightArray,
    // pick up the remaining elements and put in arr[left..right]
    while (indexofsubarrayone < subarrayone)
    {
        arr[indexofmergedarray] = leftArray[indexofsubarrayone];
        indexofsubarrayone++;
        indexofmergedarray++;
    }

    while (indexofsubarraytwo < subarraytwo)
    {
        arr[indexofmergedarray] = rightArray[indexofsubarraytwo];
        indexofsubarraytwo++;
        indexofmergedarray++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergesort(int arr[], int const begin, int const end)
{
    if (begin >= end)
        return;

    // m is the point where the array is divided into two subarrays
    auto mid = begin + (end - begin) / 2;
    mergesort(arr, begin, mid);
    mergesort(arr, mid + 1, end);

    // Merge the sorted subarrays
    merge(arr, begin, mid, end);
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements [" << i << "]: ";
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    cout << "\nSorted array is\n";
    printArray(arr, n);

    cout << "\ncount1: " << count1;
    return 0;
}
