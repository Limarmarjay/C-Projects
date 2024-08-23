#include <iostream>
using namespace std;

class Classroom {
private:
    static const int NUM_STUDENTS_ROWS = 6;
    static const int NUM_EXAMS_COLS = 5;
    int student_scores[NUM_STUDENTS_ROWS][NUM_EXAMS_COLS];

public:
    // Method to input scores
    void getScores() {
        for (int row_index = 0; row_index < NUM_STUDENTS_ROWS; row_index++) {
            for (int cols_index = 0; cols_index < NUM_EXAMS_COLS; cols_index++) {
                cout << "Enter Student " << (row_index + 1) << ", Exam " << (cols_index + 1) << " score: " << endl;
                cin >> student_scores[row_index][cols_index];
            }
        }
    }

    // Method to calculate and display the class average
    void classAverage() const {
        double classAverage = 0;
        int classTotal = 0;

        for (int row_index = 0; row_index < NUM_STUDENTS_ROWS; row_index++) {
            for (int cols_index = 0; cols_index < NUM_EXAMS_COLS; cols_index++) {
                classTotal += student_scores[row_index][cols_index];
            }
        }

        cout << "The class total is: " << classTotal << endl;
        classAverage = static_cast<double>(classTotal) / (NUM_STUDENTS_ROWS * NUM_EXAMS_COLS);
        cout << "The Class Average is: " << classAverage << endl;
    }

    // Method to calculate and display the average for each exam
    void examAverage() const {
        for (int cols_index = 0; cols_index < NUM_EXAMS_COLS; cols_index++) {
            int examTotal = 0;

            for (int row_index = 0; row_index < NUM_STUDENTS_ROWS; row_index++) {
                examTotal += student_scores[row_index][cols_index];
            }

            double examAvg = static_cast<double>(examTotal) / NUM_STUDENTS_ROWS;
            cout << "The total for Exam " << (cols_index + 1) << " is: " << examTotal << endl;
            cout << "The average for Exam " << (cols_index + 1) << " is: " << examAvg << endl;
        }
    }

    // Method to calculate and display the average for each student
    void studentAverage() const {
        for (int row_index = 0; row_index < NUM_STUDENTS_ROWS; row_index++) {
            int studentTotal = 0;

            for (int cols_index = 0; cols_index < NUM_EXAMS_COLS; cols_index++) {
                studentTotal += student_scores[row_index][cols_index];
            }

            double studentAvg = static_cast<double>(studentTotal) / NUM_EXAMS_COLS;
            cout << "The total for Student " << (row_index + 1) << " is: " << studentTotal << endl;
            cout << "The average for Student " << (row_index + 1) << " is: " << studentAvg << endl;
        }
    }
};

int main() {
    Classroom classroom;

    classroom.getScores();
    classroom.classAverage();
    classroom.examAverage();
    classroom.studentAverage();

    return 0;
}
