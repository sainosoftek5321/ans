#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    insertionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}

// pseudo code

// START

// FOR i = 1 to n-1
//     key = arr[i]
//     j = i - 1

//     WHILE j >= 0 AND arr[j] > key
//         arr[j + 1] = arr[j]
//         j = j - 1
//     END WHILE

//     arr[j + 1] = key
// END FOR

// STOP


//TC O(n2)