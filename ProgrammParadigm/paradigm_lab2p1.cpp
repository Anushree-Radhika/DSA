#include<iostream>
using namespace std;

typedef struct Student {

        string name;
        int age;
        string department;
        int year;
}student;

void ReadStudentData(student &s,int idx){

                cout << "\nEnter details of student " << idx << "\n";

                cin.ignore();
                cout << "Name: ";
                getline(cin,s.name);

                cout << "Age: ";
                cin >> s.age;

                cin.ignore();
                cout << "Department: ";
                getline(cin,s.department);

                cout << "Year:";
                cin >> s.year;
}

void PrintStudentData(student& s,int idx){

        cout << "\n ------Student Information ------\n";
        cout << "Name:" << s.name << endl;
        cout << "Age:" << s.age << endl;
        cout << "Department:" << s.department << endl;
        cout << "Year:" << s.year << endl;
}
int main(){
            int n;
        cin >> n;

        student students[n];
        for(int i=0;i<n;i++){

                ReadStudentData(students[i],i+1);
                PrintStudentData(students[i],i+1);

        }

        return 0;
}
