#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    int mathGrade;
    int physicsGrade;
    int informaticsGrade;
    double averageGrade;
};

bool compareStudents(const Student& s1, const Student& s2) {
    return s1.averageGrade > s2.averageGrade;
}

int main() {
    string line = "DataRating.txt";

    ofstream fout;

    fout.open(line);

    if (!fout.is_open())
    {
        cout << "Error opening file!\n";
    }
    else
    {
        fout << "Markov Valeriy 5 5 5\nSergey Petrov 1 1 1\nPetrov Petr 3 3 3";
    }
    fout.close();

    ifstream fin("DataRating.txt");
    if (!fin.is_open()) {
        cout << "Error opening file!\n";
        return 1;
    }

    vector<Student> students;
    string firstName, lastName;
    int mathGrade, physicsGrade, informaticsGrade;

    while (fin >> firstName >> lastName >> mathGrade >> physicsGrade >> informaticsGrade) {
        Student student;
        student.firstName = firstName;
        student.lastName = lastName;
        student.mathGrade = mathGrade;
        student.physicsGrade = physicsGrade;
        student.informaticsGrade = informaticsGrade;
        student.averageGrade = (mathGrade + physicsGrade + informaticsGrade) / 3.0;
        students.push_back(student);
    }

    fin.close();

    sort(students.begin(), students.end(), compareStudents);

    for (const auto& student : students) {
        cout << student.firstName << " " << student.lastName << endl;
    }

    return 0;
}