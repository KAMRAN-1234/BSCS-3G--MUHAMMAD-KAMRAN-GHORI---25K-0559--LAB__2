#include <iostream>
using namespace std;

void addNewStudent(int**& studentGrades, int& studentCount) {
    int** updatedGrades = new int*[studentCount + 1];
    for (int index = 0; index <= studentCount; ++index) {
        updatedGrades[index] = new int[3];
    }

    for (int student = 0; student < studentCount; ++student) {
        for (int subject = 0; subject < 3; ++subject) {
            updatedGrades[student][subject] = studentGrades[student][subject];
        }
    }

    cout << "\nEnter grades for new student:\n";
    for (int subject = 0; subject < 3; ++subject) {
        cin >> updatedGrades[studentCount][subject];
    }

    for (int student = 0; student < studentCount; ++student) {
        delete[] studentGrades[student];
    }
    delete[] studentGrades;

    studentGrades = updatedGrades;
    ++studentCount;

    cout << "\nMemory transition: " << studentCount - 1 << " x 3 -> " << studentCount << " x 3\n";
    cout << "New student added successfully.\n";
}

int main() {
    int studentCount;
    cout << "Enter number of students: ";
    cin >> studentCount;

    int** studentGrades = new int*[studentCount];
    for (int student = 0; student < studentCount; ++student) {
        studentGrades[student] = new int[3];
    }

    cout << "Enter grades for " << studentCount << " students:\n";
    for (int student = 0; student < studentCount; ++student) {
        cout << "Student " << student + 1 << ": ";
        for (int subject = 0; subject < 3; ++subject) {
            cin >> studentGrades[student][subject];
        }
    }

    cout << "\nInitial memory: " << studentCount << " x 3\n";
    addNewStudent(studentGrades, studentCount);

    cout << "\nUpdated grades:\n";
    for (int student = 0; student < studentCount; ++student) {
        cout << "Student " << student + 1 << ": ";
        for (int subject = 0; subject < 3; ++subject) {
            cout << studentGrades[student][subject] << ' ';
        }
        cout << endl;
    }

    for (int student = 0; student < studentCount; ++student) {
        delete[] studentGrades[student];
    }
    delete[] studentGrades;

    return 0;
}