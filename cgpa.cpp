#include <iostream>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses taken this semester: ";
    cin >> numCourses;

    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        double grade;
        int creditHours;

        cout << "Enter grade for course " << (i + 1) << ": ";
        cin >> grade;

        cout << "Enter credit hours for course " << (i + 1) << ": ";
        cin >> creditHours;

        totalGradePoints += grade * creditHours;
        totalCredits += creditHours;
    }

    double semesterGPA = totalGradePoints / totalCredits;
    cout << "Semester GPA: " << semesterGPA << endl;

    double overallGradePoints;
    int overallCredits;

    cout << "Enter total grade points accumulated over all semesters: ";
    cin >> overallGradePoints;

    cout << "Enter total credit hours accumulated over all semesters: ";
    cin >> overallCredits;

    double overallCGPA = overallGradePoints / overallCredits;
    cout << "Overall CGPA: " << overallCGPA << endl;

    return 0;
}