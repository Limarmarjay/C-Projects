#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct PatientRecord {
    string Name;
    string DOB;
    string Address;
    string Physician_Name;
    string Last_Visited[6];
};
const int RECORD_SIZE = 30;

void createPatientFile(PatientRecord []);
void readPatientFile(PatientRecord []);
void displayPatientsRecords(PatientRecord []);
void writeToNewFile(PatientRecord []);
void displayNewFile();

int main() {
    PatientRecord patients[RECORD_SIZE];
    createPatientFile(patients);
    readPatientFile(patients);
    displayPatientsRecords(patients);
    writeToNewFile(patients);
    displayNewFile();
    system("pause");
    return 0;
}

void createPatientFile(PatientRecord patients[]) {
    fstream MyFile;
    MyFile.open("Patient.txt", ios::out);
    if (MyFile) {
        for (int i = 0; i < RECORD_SIZE; i++) {
            cout << "\n\tEnter information for Patient " << i + 1 << ":\n";

            cout << "Enter Patient's Name: ";
            getline(cin, patients[i].Name);
            
            cout << "Enter Patient's DOB (MM/DD/YYYY): ";
            getline(cin, patients[i].DOB);
            
            cout << "Enter Patient's Address: ";
            getline(cin, patients[i].Address);
            
            cout << "Enter Primary Care Physician's Name: ";
            getline(cin, patients[i].Physician_Name);
            
            cout << "Enter 6 dates of visits:\n";
            for (int j = 0; j < 6; j++) {
                cout << "Visit " << j + 1 << " (MM/DD/YYYY): ";
                getline(cin, patients[i].Last_Visited[j]);
            }

            // Write patient information to file
            MyFile << patients[i].Name << endl;
            MyFile << patients[i].DOB << endl;
            MyFile << patients[i].Address << endl;
            MyFile << patients[i].Physician_Name << endl;
            for (int j = 0; j < 6; j++) {
                MyFile << patients[i].Last_Visited[j] << endl;
            }
        }
        MyFile.close();
    } 
    else 
    {
        cout << "File not found. Please Try again" << endl;
    }
}

void readPatientFile(PatientRecord patients[]) {
    fstream MyFile;
    MyFile.open("Patient.txt", ios::in);
    if (MyFile) 
    {
        for (int i = 0; i < RECORD_SIZE; ++i) {
            getline(MyFile, patients[i].Name);
            getline(MyFile, patients[i].DOB);
            getline(MyFile, patients[i].Address);
            getline(MyFile, patients[i].Physician_Name);
            for (int j = 0; j < 6; ++j) {
                getline(MyFile, patients[i].Last_Visited[j]);
            }
        }
        MyFile.close();
    } 
    else 
    {
        cout << "File not found. Please try again later" << endl;
    }
}

void displayPatientsRecords(PatientRecord patients[]) {
    for (int i = 0; i < RECORD_SIZE; ++i) {
        cout << "Patient: " << patients[i].Name << endl;
        cout << "DOB: " << patients[i].DOB << endl;
        cout << "Address: " << patients[i].Address << endl;
        cout << "Physician: " << patients[i].Physician_Name << endl;
        cout << "Last 6 visits:" << endl;
        for (int j = 0; j < 6; ++j) {
            cout << "  " << patients[i].Last_Visited[j] << endl;
        }
        cout << endl;
    }
}

void writeToNewFile(PatientRecord patients[]) {
    fstream MyNewFile;
    MyNewFile.open("Patient_2.txt", ios::out);
    if (MyNewFile) {
        for (int i = 0; i < RECORD_SIZE; ++i) {
            MyNewFile << patients[i].Name << endl;
            MyNewFile << patients[i].DOB << endl;
            MyNewFile << patients[i].Address << endl;
            MyNewFile << patients[i].Physician_Name << endl;
            for (int j = 0; j < 6; ++j) {
                MyNewFile << patients[i].Last_Visited[j] << endl;
            }
        }
        MyNewFile.close();
    } 
    else 
    {
        cout << "File not found. Please try again later" << endl;
    }
}

void displayNewFile() {
    fstream MyNewFile;
    MyNewFile.open("Patient_2.txt", ios::in);
    if (MyNewFile) 
    {
        string line;
        while (getline(MyNewFile, line)) 
        {
            cout << line << endl;
        }
        MyNewFile.close();
    } 
    else 
    {
        cout << "File not found. Please try again later" << endl;
    }
}