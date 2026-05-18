#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}


// Pseudo code
// START

// FOR i = 0 to n-2
//     minIndex = i

//     FOR j = i+1 to n-1
//         IF arr[j] < arr[minIndex]
//             minIndex = j
//         END IF
//     END FOR

//     SWAP arr[i] and arr[minIndex]
// END FOR

// STOP


//TC O(n2)