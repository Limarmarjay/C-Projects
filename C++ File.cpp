#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Family 
{
protected:
    string FamilyName;
    string FamilyAddress;
public:
    Family(string FamilyName = "", string FamilyAddress = "") 
    {
        this->FamilyName = FamilyName;
        this->FamilyAddress = FamilyAddress;
    }
    virtual void Get_Info() 
    {
        cout << "Please enter Family Name: ";
        cin >> this->FamilyName;
        
        cout << "Please enter current Family Address: ";
        cin >> this->FamilyAddress;
    }
    virtual void Display_Info() 
    {
        cout << "\nFamily Information displayed below:\n";
        cout << "Family Name: " << this->FamilyName << endl;
        cout << "Family Address: " << this->FamilyAddress << endl;
    }
    virtual ~Family() {}
};

class Community {
protected:
    string CommunityName;
    string CommunityAddress;
public:
    Community(string CommunityName = "", string CommunityAddress = "") 
    {
        this->CommunityName = CommunityName;
        this->CommunityAddress = CommunityAddress;
    }
    virtual void Get_Info() 
    {
        cout << "Please enter Community Name: ";
        cin >> this->CommunityName);
        
        cout << "Please enter Community Address: ";
        cin >> this->CommunityAddress);
    }
    virtual void Display_Info() 
    {
        cout << "\nCommunity Information displayed below:\n";
        cout << "Name of Community: " << this->CommunityName << endl;
        cout << "Community Address: " << this->CommunityAddress << endl;
    }
    virtual ~Community() {}
};

class City 
{
protected:
    string CityName;
    string CityAddress;
public:
    City(string CityName = "", string CityAddress = "") 
    {
        this->CityName = CityName;
        this->CityAddress = CityAddress;
    }
    virtual void Get_Info() 
    {
        cout << "Please enter Name of City: ";
        cin >> this->CityName;
        
        cout << "Please enter current City Address: ";
        getline(cin >> ws, this->CityAddress);
    }
    virtual void Display_Info() 
    {
        cout << "\nCity Information displayed below:\n";
        cout << "Name of City: " << this->CityName << endl;
        cout << "City Address: " << this->CityAddress << endl;
    }
    virtual ~City() {}
};

class University 
{
protected:
    string UniversityName;
    string UniversityAddress;
public:
    University(string UniversityName = "", string UniversityAddress = "") 
    {
        this->UniversityName = UniversityName;
        this->UniversityAddress = UniversityAddress;
    }
    virtual void Get_Info() {
        cout << "Please enter Name of University: ";  // Fixed prompt
        cin >> this->UniversityName;
        
        cout << "Please enter University Address: ";  // Fixed prompt
        cin >> this->UniversityAddress;
    }
    virtual void Display_Info() {
        cout << "\nUniversity Information displayed below:\n";
        cout << "Name of University: " << this->UniversityName << endl;
        cout << "University Address: " << this->UniversityAddress << endl;
    }
    virtual ~University() {}
};

class Student : public Family, public Community, public City, public University 
{
    char letterGrade;
private:
    struct StudentRecord {
        string studentName;
        double courses[5];
        double exams[4];
        double quizzes[6];
        double projects[5];
        double grades[5];
        double classParticipation;
        char letterGrades[5];
        double GPA;
    };
    StudentRecord studentrecord;

    char calculateLetterGrade(double grade) 
    {
        if (grade >= 90) 
        {
            return 'A';
        }
        else if (grade >= 80) 
        {
            return 'B';
        }
        else if (grade >= 70)
        {
            return 'C';
        }
        else if (grade >= 60) 
        {
            return 'D';
        }
        else 
        {
            return 'F';
        }
    }

    // Helper function to convert letter grade to GPA points
    double letterToGPAPoints(char letter) {
        switch(letter) 
        {
            case 'A': 
                return 4.0;
            case 'B': 
                return 3.0;
            case 'C': 
                return 2.0;
            case 'D': 
                return 1.0;
            default: 
                return 0.0;
        }
    }

public:
    Student(string Name = "", double gpa = 0.0, double classP = 0.0) {
        studentrecord.studentName = Name;
        studentrecord.GPA = gpa;
        studentrecord.classParticipation = classP;
        
        for (int i = 0; i < 5; i++) {
            studentrecord.courses[i] = 0.0;
            studentrecord.projects[i] = 0.0;
            studentrecord.grades[i] = 0.0;
            studentrecord.letterGrades[i] = 'F';
        }
        for (int i = 0; i < 6; i++) {
            studentrecord.quizzes[i] = 0.0;
        }
        for (int i = 0; i < 4; i++) {
            studentrecord.exams[i] = 0.0;
        }
    }

    void Get_Info() {
        Family::Get_Info();
        Community::Get_Info();
        City::Get_Info();
        University::Get_Info();

        cout << "\nPlease enter Student information below:\n";
        cout << "Please enter student's name: ";
        cin >> studentrecord.studentName;
        
        cout << "Please enter student's participation score: ";
        cin >> studentrecord.classParticipation;
        
        cout << "\nPlease enter exam scores (4 exams):\n";
        for (int i = 0; i < 4; i++) {
            cout << "Exam " << i + 1 << ": ";
            cin >> studentrecord.exams[i];
        }
        
        cout << "\nPlease enter quiz scores (6 quizzes):\n";
        for (int i = 0; i < 6; i++) {
            cout << "Quiz " << i + 1 << ": ";
            cin >> studentrecord.quizzes[i];
        }
        
        cout << "\nPlease enter project scores (5 projects):\n";
        for (int i = 0; i < 5; i++) {
            cout << "Project " << i + 1 << ": ";
            cin >> studentrecord.projects[i];
        }

        calculateGrades();
    }
    
    void calculateGrades() {
        double examAvg = 0.0;
        double quizAvg = 0.0;
        double projectAvg = 0.0;
        
        for (int i = 0; i < 4; i++) {
            examAvg += studentrecord.exams[i];
        }
        examAvg /= 4.0;
        
        for (int i = 0; i < 6; i++) {
            quizAvg += studentrecord.quizzes[i];
        }
        quizAvg /= 6.0;
        
        for (int i = 0; i < 5; i++) {
            projectAvg += studentrecord.projects[i];
        }
        projectAvg /= 5.0;
    
        for (int i = 0; i < 5; i++ {
        	double finalGrade = (examAvg * 0.50) + (quizAvg * 0.15) + (studentrecord.classParticipation * 0.10) + (projectAvg * 0.25);
        	studentrecord.grades[course] = finalGrade;
            studentrecord.letterGrades[course] = calculateLetterGrade(finalGrade);
            studentrecord.courses[course] = finalGrade;
          
            totalGPA += letterToGPAPoints(studentrecord.letterGrades[course]);
        }

    }

    void Display_Info() {
        Family::Display_Info();
        Community::Display_Info();
        City::Display_Info();
        University::Display_Info();

        cout << "\nStudent Information:\n";
        cout << "Student Name: " << studentrecord.studentName << endl;
        cout << "Class Participation: " << fixed << setprecision(2) << studentrecord.classParticipation << endl;
        
        cout << "\nExam Scores:\n";
        for (int i = 0; i < 4; i++) {
            cout << "Exam " << i + 1 << ": " << studentrecord.exams[i] << endl;
        }
        
        cout << "\nQuiz Scores:\n";
        for (int i = 0; i < 6; i++) {
            cout << "Quiz " << i + 1 << ": " << studentrecord.quizzes[i] << endl;
        }
        
        cout << "\nProject Scores:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Project " << i + 1 << ": " << studentrecord.projects[i] << endl;
        }
        
        for (i = 0; i < 5; i++)
        {   cout << "\nFinal Grade: " << studentrecord.grades[i] << endl;
            cout << "Letter Grade: " << studentrecord.letterGrades[i] << endl;
        }
        cout << "GPA: " << studentrecord.GPA << endl;
    }

    ~Student() {}
};

int main() {
    const int STUDENT_SIZE = 10;
    Student students[STUDENT_SIZE];
    
    cout << "Enter information for all the students:\n";
    for (int i = 0; i < STUDENT_SIZE; i++) {
        cout << "\nEntering information for student " << i + 1 << ":\n";
        students[i].Get_Info();
    }
    
    cout << "\nDisplaying information for all students:\n";
    for (int i = 0; i < STUDENT_SIZE; i++) {
        cout << "\n=== Student " << i + 1 << " ===\n";
        students[i].Display_Info();
    }
    
    return 0;
}