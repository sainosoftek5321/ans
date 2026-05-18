#include <iostream>
using namespace std;

int factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial = " << factorial(n);
    return 0;
}

// Pseudo code

// START
// factorial(n)
// IF n == 0 OR n == 1
//     RETURN 1
// RETURN n * factorial(n-1)
// STOP

// Time complexity
// Time Complexity:
// Each recursive call runs once for every value from n to 1
// Total calls = n

// Therefore:

// Time Complexity = O(n)