#include<iostream>
#include<queue>
using namespace std;

void HeapSort(vector<int> &arr){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(auto x : arr){
        pq.push(x);
    }

    arr.clear();

    while(pq.size()>0){
        arr.push_back(pq.top());
        pq.pop();
    }
}

void printArray(vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    
    cout<<endl;
}

int main(){
    vector<int> arr = {7,8,3,5,6,11,10};
    cout<<"Orignal Array\n";
    printArray(arr);

    HeapSort(arr);

    cout<<"Sorted Array\n";
    printArray(arr);

}


// Pseudo Code
// START

// FUNCTION heapify(arr, n, i)
//     largest = i
//     left = 2*i + 1
//     right = 2*i + 2

//     IF left < n AND arr[left] > arr[largest]
//         largest = left
//     END IF

//     IF right < n AND arr[right] > arr[largest]
//         largest = right
//     END IF

//     IF largest != i
//         SWAP arr[i] and arr[largest]
//         heapify(arr, n, largest)
//     END IF
// END FUNCTION


// FUNCTION heapSort(arr, n)

//     // Build Max Heap
//     FOR i = n/2 - 1 DOWNTO 0
//         heapify(arr, n, i)
//     END FOR

//     // Extract elements one by one
//     FOR i = n-1 DOWNTO 0
//         SWAP arr[0] and arr[i]
//         heapify(arr, i, 0)
//     END FOR

// END FUNCTION

// STOP



//TC O(nlogn)