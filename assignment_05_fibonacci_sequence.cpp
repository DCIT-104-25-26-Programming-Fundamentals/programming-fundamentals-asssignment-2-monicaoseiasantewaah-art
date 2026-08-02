// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

include <iostream>
using namespace std;

// PART A: Print the First N Terms
void printFibonacci(int N) {
    if (N <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";
    
    long long first = 0, second = 1;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << first;
        } else if (i == 1) {
            cout << " " << second;
        } else {
            long long next = first + second;
            cout << " " << next;
            first = second;
            second = next;
        }
    }
    cout << endl;
}

// PART B: Check If a Number Belongs to the Sequence
bool isFibonacciNumber(long long num) {
    if (num < 0) return false;
    if (num == 0 || num == 1) return true;

    long long first = 0, second = 1, next = 1;

    while (next < num) {
        next = first + second;
        first = second;
        second = next;
    }

    return (next == num);
}

void checkFibonacci() {
    long long num;
    cout << "Enter a number to check: ";
    cin >> num;

    if (num < 0) {
        cout << "Error: Input must be a positive integer." << endl;
        return;
    }

    if (isFibonacciNumber(num)) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    // Execute Part A
    int terms;
    cout << "How many terms? ";
    cin >> terms;
    printFibonacci(terms);

    cout << endl;

    // Execute Part B
    checkFibonacci();

    return 0;
}