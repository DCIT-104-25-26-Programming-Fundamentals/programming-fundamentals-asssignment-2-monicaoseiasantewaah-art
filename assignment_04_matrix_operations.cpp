// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10; // Fixed maximum size of 10 for array dimensions

// Function to read matrix values element by element from user input
void readMatrix(int matrix[MAX][MAX], int rows, int cols, char name = 'A') {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element " << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display matrix aligned using setw
void displayMatrix(const int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << "\n";
    }
}

// PART A: Transpose a Matrix
void partA_Transpose() {
    int rows, cols;
    int A[MAX][MAX], T[MAX][MAX];

    cout << "--- PART A: Transpose Matrix ---\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(A, rows, cols, 'A');

    // Compute transpose using nested loops (rows become cols)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(A, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(T, cols, rows);
}

// PART B: Add Two Matrices
void partB_Add() {
    int rows, cols;
    int A[MAX][MAX], B[MAX][MAX], Sum[MAX][MAX];

    cout << "\n--- PART B: Add Two Matrices ---\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nReading Matrix A:\n";
    readMatrix(A, rows, cols, 'A');

    cout << "\nReading Matrix B:\n";
    readMatrix(B, rows, cols, 'B');

    // Compute element-wise sum using nested loops
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nMatrix A + Matrix B:\n";
    displayMatrix(Sum, rows, cols);
}

// PART C: Multiply Two Matrices
void partC_Multiply() {
    int r1, c1, r2, c2;

    cout << "\n--- PART C: Multiply Two Matrices ---\n";
    cout << "Enter rows for Matrix A: ";
    cin >> r1;
    cout << "Enter columns for Matrix A: ";
    cin >> c1;

    cout << "Enter rows for Matrix B: ";
    cin >> r2;
    cout << "Enter columns for Matrix B: ";
    cin >> c2;

    // Validation: Number of columns in A must equal number of rows in B
    if (c1 != r2) {
        cout << "Error: Matrix multiplication not possible. Columns of A (" 
             << c1 << ") must equal rows of B (" << r2 << ").\n";
        return;
    }

    int A[MAX][MAX], B[MAX][MAX], Product[MAX][MAX] = {0};

    cout << "\nReading Matrix A:\n";
    readMatrix(A, r1, c1, 'A');

    cout << "\nReading Matrix B:\n";
    readMatrix(B, r2, c2, 'B');

    // Compute matrix multiplication (r1 x c2 result) using triple nested loops
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            Product[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                Product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatrix A x Matrix B:\n";
    displayMatrix(Product, r1, c2);
}

int main() {
    // Execute each operation function in order
    partA_Transpose();
    partB_Add();
    partC_Multiply();

    return 0;
