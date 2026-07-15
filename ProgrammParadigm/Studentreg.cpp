#include<iostream>
using namespace std;

class Student {

    string name;
    int age;
    string department;
    int year;

    static const int siz = 5;
    static Student pool[siz];
    static bool used[siz];

public:
    static int personCount;

    Student() {
        name = "";
        age = 0;
        department = "";
        year = 0;
        personCount++;
    }
    void readStudentName(string nm, int age, string dept, int yr) {
        name = nm;
        this->age = age;
        department = dept;
        year = yr;
        cout << "Successful Initialization\n";
    }
    void printStudentName() {
        cout << "----------------------------\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Year: " << year << endl;
    }
    void* operator new(size_t) {
        for(int i = 0; i < siz; i++) {
            if(!used[i]) {
                used[i] = true;
                cout << "Allocating from pool index: " << i << endl;
                return &pool[i];
            }
        }
        cout << "Memory Pool Exhausted\n";
        return nullptr;
    }
    void operator delete(void* ptr) {
        for(int i = 0; i < siz; i++) {
            if(ptr == &pool[i]) {
                used[i] = false;
                cout << "Returned to pool index: " << i << endl;
                return;
            }
        }
    }
};
Student Student::pool[Student::siz];
bool Student::used[Student::siz] = {false};
int Student::personCount = 0;
int main() {

    cout << "Enter number of students: ";
    int n;
    cin >> n;

    Student* s[10];   
    int actual = 0;

    for(int i = 0; i < n; i++) {

        string name, dept;
        int age, year;

        cout << "\nEnter details for student " << i+1 << endl;
        cin >> name >> age >> dept >> year;

        s[i] = new Student;

        if(s[i] == nullptr) {
            cout << "Pool exhausted. Cannot allocate more.\n";
            break;
        }

        s[i]->readStudentName(name, age, dept, year);
        actual++;
    }
    cout << "\n--- Student List ---\n";
    for(int i = 0; i < actual; i++) {
        if(s[i] != nullptr)
            s[i]->printStudentName();
    }
    if(actual >= 1) {
        cout << "\nDeleting student at index \n";
        cout << "Input an index to output\n";
        int idx ;
        cin >> idx;
        delete s[idx];
        s[idx] = nullptr;  
    }
    cout << "\nAdding new student (pool reuse expected)\n";
    Student* sx = new Student;

    if(sx != nullptr) {
        sx->readStudentName("Ganesh", 24, "CSE", 2028);
        sx->printStudentName();
    }
    for(int i = 0; i < actual; i++) {
        if(s[i] != nullptr)
            delete s[i];
    }
    cout << "\nTotal objects created: " << Student::personCount << endl;
    return 0;
}
