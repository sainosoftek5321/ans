#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {8, 3, 5, 2, 1};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
// 
// QUICK_SORT(arr, low, high)

// IF low < high

//     pivotIndex = PARTITION(arr, low, high)

//     QUICK_SORT(arr, low, pivotIndex - 1)

//     QUICK_SORT(arr, pivotIndex + 1, high)

// ---------------------------------------------

// PARTITION(arr, low, high)

// pivot = arr[high]

// i = low - 1

// FOR j = low TO high - 1

//     IF arr[j] < pivot

//         i++

//         Swap arr[i] and arr[j]

// Swap arr[i + 1] and arr[high]

// RETURN i + 1



// TC O(nlogn)