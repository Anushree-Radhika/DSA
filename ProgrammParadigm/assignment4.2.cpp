#include<iostream>
using namespace std;
class Person{
    private:
        string name;
        int age;
        string gender;

    public:

        Person(){}
        Person(string nam , int age , string genr) : name(nam),age(age),gender(genr){}
        void ReadData(string n,int ag,string gen){
            this->name = n;
            this->age = ag;
            this->gender = gen;
        }
        virtual void display() {
            cout << "Name :" << name << endl;
            cout << "Age :" << age << endl;
            cout << "Gender :" << gender << endl;
        }
        virtual ~Person() {}
};
class TechnicalMember : virtual public Person {
    private:
        string dept;
        string skillset;

    public:
        TechnicalMember(){}
        TechnicalMember(string dept , string skillset) : dept(dept),skillset(skillset){}
        void ReadData(string dp,string skillset){
            this->dept = dp;
            this->skillset = skillset;
        }
        virtual void display(bool flag) {
            if(flag){
                Person :: display();
            }
            cout << "Department :" << dept << endl;
            cout << "Skillset :" << skillset << endl;
        }
};
class Employee : virtual public Person {
    private:
        string empID;
        double salary;
    
    public:
        Employee(){}
        Employee(string empID , double salary) : empID(empID),salary(salary){}
        void ReadData(string empID , double salary){
            this->empID = empID;
            this->salary = salary;
        }
        virtual void display(bool flag) {
            if(flag){
                Person :: display();
            }
            cout << "Employee ID :" << empID << endl;
            cout << "Salary :" << salary << endl;
        }
};

class Trainee : public TechnicalMember {
    private:
        double duration;
        double stipend;
    public:
        Trainee(){}
        Trainee(string nm,int ag, string gndr,string dept,string skillset,double duration,double stipend) : Person(nm,ag,gndr) ,TechnicalMember(dept,skillset),duration(duration),stipend(stipend){}
        void ReadData(string nm,int ag, string gndr,string dept,string skillset,double duration , double stipend){
            Person :: ReadData(nm,ag,gndr);
            TechnicalMember :: ReadData(dept,skillset);
            this->duration = duration;
            this->stipend = stipend;
        }
        virtual void display() {
            TechnicalMember :: display(true);
            cout << "Duration :" << duration << endl;
            cout << "Stipend :" << stipend << endl;
        }
};

class Developer : public TechnicalMember,Employee {
    private:
        int projects;
        int yearsOfExp;

    public:
        Developer(){}
        Developer(string nm,int ag, string gndr, string eID,double sal, string dept,string skillset, int proj,int yrsOFexp): Person(nm,ag,gndr) , TechnicalMember(dept,skillset) , Employee(eID,sal) ,projects(proj),yearsOfExp(yrsOFexp){}
        void ReadData(string nm,int ag, string gndr, string eID,double sal, string dept,string skillset, int proj,int yrsOFexp){
            Person :: ReadData(nm,ag,gndr);
            TechnicalMember :: ReadData(dept,skillset);
            Employee :: ReadData(eID,sal);

            this->projects = proj;
            this->yearsOfExp = yrsOFexp;
        }
        virtual void display() {
            TechnicalMember :: display(true);
            Employee :: display(false);
            cout << "No. of projects :" << projects << endl;
            cout << "Years of Experience :" << yearsOfExp << endl;
        }
};

class SystemAdmin : public Employee {
    private:
        int workload;

    public:
        SystemAdmin(){}
        SystemAdmin(string nm,int age,string gndr,string empID,double salary,int workload) : Person(nm,age,gndr),Employee(empID,salary),workload(workload){}
        void ReadData(string nm,int age,string gndr,string empID,double salary,int wkld){
            Employee :: ReadData(empID,salary);
            this->workload = wkld;
        }
        virtual void display() {
            Employee :: display(true);
            cout << "WorkLoad :" << workload << endl; 
        }
};
int main(){
    // Using parameterized constructor

    cout << "Enter the details of a developer\n";
    string nm,dpt,gndr,empid,skillset;
    int age,projects,yrsOfExp,workload;
    double salary,stipend,duration;
    cout << "Input name :" << endl;
    getline(cin,nm);
    cout << "Input department :" << endl;
    getline(cin,dpt);
    cout << "Input Gender :" << endl;
    getline(cin,gndr);
    cout << "Input EmployeeID :" << endl;
    getline(cin,empid);
    cout << "Input Skill-set :" << endl;
    getline(cin,skillset);
    cout << "Input age :" << endl;
    cin >> age;cin.ignore();
    cout << "Input Projects :" << endl;
    cin >> projects;cin.ignore();
    cout << "Input YearsOfExperience :" << endl;
    cin >> yrsOfExp;cin.ignore();
    cout << "Input salary :" << endl;
    cin >> salary;cin.ignore();
    Developer d(nm,age,gndr,empid,salary,dpt,skillset,projects,yrsOfExp);
    cout << "Enter the details of System-Admin\n";
    cout << "Input name :" << endl;
    getline(cin,nm);
    cout << "Input Gender :" << endl;
    getline(cin,gndr);
    cout << "Input EmployeeID :" << endl;
    getline(cin,empid);
    cout << "Input age :" << endl;
    cin >> age;cin.ignore();
    cout << "Input salary :" << endl;
    cin >> salary;cin.ignore();
    cout << "Input workload :" << endl;
    cin >> workload;cin.ignore();
    SystemAdmin sa(nm,age,gndr,empid,salary,workload);
    cout << "Enter details of the Trainee \n";
    cout << "Input name:" <<endl;
    getline(cin,nm);
    cout << "Input Gender :" << endl;
    getline(cin,gndr);
    cout << "Input age :" << endl;
    cin >> age;cin.ignore();
    cout << "Input department :" << endl;
    getline(cin,dpt);
    cout << "Input Skill-set :" << endl;
    getline(cin,skillset);
    cout << "Input duration :" << endl;
    cin >> duration;cin.ignore();
    cout << "Input stipend :" << endl;
    cin >> stipend;cin.ignore();
    Trainee t(nm,age,gndr,dpt,skillset,duration,stipend);

    // Using Static Binding

    // cout << "Displaying all the details of Developer:\n";
    // d.display();
    // cout << "Displaying all the details of System Admin:\n";
    // sa.display();
    // cout << "Displaying all the details of Trainee:\n";
    // t.display();

    // Using Dynamic Binding
    // Dynamic Polymorphism

    Person *p;
    p = &d;
    cout << "\nDeveloper Details:\n";
    p->display();

    p = &sa;
    cout << "\nSystem Admin Details:\n";
    p->display();

    p = &t;
    cout << "\nTrainee Details:\n";
    p->display();

}
