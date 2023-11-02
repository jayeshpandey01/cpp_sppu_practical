/*
Create employee bio-data using following classes i) Personal record ii))Professional record 
iii)Academic record Assume appropriate data members and member function to accept 
required data & print bio-data. Create bio-data using multiple inheritance using C++.
*/

#include <iostream>
#include <string>
using namespace std;
class PersonalRecord {
protected:
    string name;
    int age;
    string address;

public:
    PersonalRecord(const string& n, int a, const string& addr) : name(n), age(a), address(addr) {}

    void inputPersonalData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore(); // Consume the newline character
        cout << "Enter Address: ";
        getline(cin, address);
    }

    void printPersonalData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

class ProfessionalRecord {
protected:
    string company;
    string jobTitle;
    int experienceYears;

public:
    ProfessionalRecord(const string& comp, const string& title, int exp)
        : company(comp), jobTitle(title), experienceYears(exp) {}

    void inputProfessionalData() {
        cout << "Enter Company: ";
        getline(cin, company);
        cout << "Enter Job Title: ";
        getline(cin, jobTitle);
        cout << "Enter Years of Experience: ";
        cin >> experienceYears;
    }

    void printProfessionalData() {
        cout << "Company: " << company << endl;
        cout << "Job Title: " << jobTitle << endl;
        cout << "Years of Experience: " << experienceYears << " years" << endl;
    }
};

class AcademicRecord {
protected:
    string degree;
    string university;
    int graduationYear;

public:
    AcademicRecord(const string& deg, const sstring& univ, int gradYear)
        : degree(deg), university(univ), graduationYear(gradYear) {}

    void inputAcademicData() {
        cout << "Enter Degree: ";
        getline(cin, degree);
        cout << "Enter University: ";
        getline(cin, university);
        cout << "Enter Graduation Year: ";
        cin >> graduationYear;
    }

    void printAcademicData() {
        cout << "Degree: " << degree << endl;
        cout << "University: " << university << endl;
        cout << "Graduation Year: " << graduationYear << endl;
    }
};

class Employee : public PersonalRecord, public ProfessionalRecord, public AcademicRecord {
public:
    Employee(
        const string& name, int age, const string& address,
        const string& company, const string& jobTitle, int experienceYears,
        const string& degree, const string& university, int graduationYear)
        : PersonalRecord(name, age, address),
          ProfessionalRecord(company, jobTitle, experienceYears),
          AcademicRecord(degree, university, graduationYear) {}

    void createBioData() {
        cout << "Employee Bio-Data" << endl;
        printPersonalData();
        printProfessionalData();
        printAcademicData();
    }
};

int main() {
    string name, address, company, jobTitle, degree, university;
    int age, experienceYears, graduationYear;

    cout << "Enter Employee Details:" << endl;

    Employee employee(
        name, age, address, company, jobTitle, experienceYears, degree, university, graduationYear);

    employee.inputPersonalData();
    employee.inputProfessionalData();
    employee.inputAcademicData();

    // Create and display the bio-data
    employee.createBioData();

    return 0;
}
