// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// ========#include <iostream>

// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Define a struct called Student as required
struct Student {
    string name;
    string id;
    vector<double> scores;
};

// Helper function to calculate average score of a student
double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// Display menu options
void displayMenu() {
    cout << "====================================\n";
    cout << "    STUDENT RECORD SYSTEM MENU      \n";
    cout << "====================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
    cout << "====================================\n";
}

// Option 1: Add a new student record
void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 1; i <= numScores; i++) {
        double score;
        cout << "Enter score " << i << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully.\n";
}

// Option 2: Display formatted table of all student records
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << "\n------------------------------------------------------------\n";
    cout << left << setw(20) << "Name" 
         << setw(15) << "ID" 
         << setw(15) << "Average" << "\n";
    cout << "------------------------------------------------------------\n";

    for (const auto& student : students) {
        double avg = calculateAverage(student.scores);
        cout << left << setw(20) << student.name 
             << setw(15) << student.id 
             << fixed << setprecision(2) << setw(15) << avg << "\n";
    }
    cout << "------------------------------------------------------------\n";
}

// Option 3: Calculate & display average score for a specific student ID
void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    string searchID;
    cout << "Enter student ID: ";
    cin >> searchID;

    bool found = false;
    for (const auto& student : students) {
        if (student.id == searchID) {
            double avg = calculateAverage(student.scores);
            cout << student.name << "'s average score: " 
                 << fixed << setprecision(2) << avg << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Error: Student ID " << searchID << " not found.\n";
    }
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
                break;
        }
        cout << "\n";
    }

    return 0;
}