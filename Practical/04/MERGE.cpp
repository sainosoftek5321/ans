#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {8, 3, 5, 2, 1};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
// Pseudo code

// MERGE_SORT(arr, left, right)

// IF left >= right
//     RETURN

// mid = (left + right) / 2

// MERGE_SORT(arr, left, mid)
// MERGE_SORT(arr, mid + 1, right)

// MERGE(arr, left, mid, right)
// -----------------------------
// MERGE(arr, left, mid, right)

// Create temporary array temp

// i = left
// j = mid + 1

// WHILE i <= mid AND j <= right

//     IF arr[i] <= arr[j]
//         Add arr[i] to temp
//         i++

//     ELSE
//         Add arr[j] to temp
//         j++

// WHILE i <= mid
//     Add arr[i] to temp
//     i++

// WHILE j <= right
//     Add arr[j] to temp
//     j++

// Copy temp back into arr


//-----------------------------------
// TC -O(nlogn)