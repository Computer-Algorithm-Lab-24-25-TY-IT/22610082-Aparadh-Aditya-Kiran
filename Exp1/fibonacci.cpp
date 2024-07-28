// Name : ADITYA APARADH
// PRN : 22610082
// Class : TY IT  

// This program calculates the nth Fibonacci number using three different methods: recursive, iterative, and memoized recursive.


#include <bits/stdc++.h>
using namespace std;


// Simple Iterative Function using a for loop
int iterativeFibonacci( int n ){
    int prev= 0;
    int prev2= 1;
    if (n <= 1) { 
      return n;
    }

    for( int i= 2; i <= n; i++ ){
        int temp= prev + prev2;
        prev= prev2;
        prev2= temp;
    }
    return prev2;
}


// Uses recursion to calculate the nth Fibonacci number
int RecursiveFibonacci(int n) {
    if (n <= 1) { 
      return n;
    }
    return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}

// Optimizes the Recursive Method by storing intermediate values in an array/memo
int MemoizedRecursiveFibonacci(int n, int* memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] == 0) {
        memo[n] = MemoizedRecursiveFibonacci(n - 1, memo) + MemoizedRecursiveFibonacci(n - 2, memo);
    }
    return memo[n];
}



int main() {
    int n = 40;
    cout << "n: " << n << endl << endl;
    cout << "Iterative Fibonacci: " << iterativeFibonacci(n) << endl;
    cout << "Simple Recursive Fibonacci: " << RecursiveFibonacci(n) << endl;
    cout << "Memoized Recursive Fibonacci: " << MemoizedRecursiveFibonacci(n, new int[n + 1]) << endl;
    return 0;
}