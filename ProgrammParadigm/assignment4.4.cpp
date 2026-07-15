#include<iostream>
#include<fstream>
using namespace std;

class FMS {
public:

    virtual void displayInfo() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;


    virtual void saveInfo(ofstream &out) = 0;
    virtual void loadInfo(ifstream &in) = 0;

    virtual ~FMS() {}
};


class Car : public FMS {
private:
    bool begin = false, end = true;
    string CarModel, CarNum, Carfeature;

public:
    Car() {}  

    Car(string model, string num, string fea) {
        CarModel = model;
        CarNum = num;
        Carfeature = fea;
    }

    void start() {
        begin = true; end = false;
    }

    void stop() {
        end = true; begin = false;
    }

    void displayInfo() {
        cout << "Type: Car\n";
        cout << "Start: " << begin << "\n";
        cout << "Stop: " << end << "\n";
        cout << "Model: " << CarModel << "\n";
        cout << "Number: " << CarNum << "\n";
        cout << "Feature: " << Carfeature << "\n\n";
    }

    void saveInfo(ofstream &out) {
        out << "Car " << CarModel << " " << CarNum << " " << Carfeature << endl;
    }

    void loadInfo(ifstream &in) {
        in >> CarModel >> CarNum >> Carfeature;
    }
};


class Bus : public FMS {
private:
    bool begin = false, end = true;
    string BusModel, BusNum, Busfeature;

public:
    Bus() {}

    Bus(string model, string num, string fea){
        BusModel = model;
        BusNum = num;
        Busfeature = fea;
    }

    void start() {
        begin = true; end = false;
    }

    void stop() {
        end = true; begin = false;
    }

    void displayInfo() {
        cout << "Type: Bus\n";
        cout << "Start: " << begin << "\n";
        cout << "Stop: " << end << "\n";
        cout << "Model: " << BusModel << "\n";
        cout << "Number: " << BusNum << "\n";
        cout << "Feature: " << Busfeature << "\n\n";
    }

    void saveInfo(ofstream &out) {
        out << "Bus " << BusModel << " " << BusNum << " " << Busfeature << endl;
    }

    void loadInfo(ifstream &in) {
        in >> BusModel >> BusNum >> Busfeature;
    }
};

class Truck : public FMS {
private:
    bool begin = false, end = true;
    string TruckModel, TruckNum, Truckfeature;

public:
    Truck() {}

    Truck(string model, string num, string fea){
        TruckModel = model;
        TruckNum = num;
        Truckfeature = fea;
    }

    void start() {
        begin = true; end = false;
    }

    void stop() {
        end = true; begin = false;
    }

    void displayInfo() {
        cout << "Type: Truck\n";
        cout << "Start: " << begin << "\n";
        cout << "Stop: " << end << "\n";
        cout << "Model: " << TruckModel << "\n";
        cout << "Number: " << TruckNum << "\n";
        cout << "Feature: " << Truckfeature << "\n\n";
    }

    void saveInfo(ofstream &out) {
        out << "Truck " << TruckModel << " " << TruckNum << " " << Truckfeature << endl;
    }

    void loadInfo(ifstream &in) {
        in >> TruckModel >> TruckNum >> Truckfeature;
    }
};

int main() {

    cout << "Enter number of vehicles:\n";
    int n, count = 0;
    cin >> n;

    FMS* coll[n];

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "1.Car 2.Bus 3.Truck:\n";
        cin >> choice;

        string model, num, feature;
        cout << "Enter model, number, feature:\n";
        cin >> model >> num >> feature;

        if (choice == 1)
            coll[count++] = new Car(model, num, feature);
        else if (choice == 2)
            coll[count++] = new Bus(model, num, feature);
        else if (choice == 3)
            coll[count++] = new Truck(model, num, feature);
        else {
            cout << "Invalid choice\n";
            i--;
        }
    }


    for (int i = 0; i < count; i++) {
        coll[i]->start();
        coll[i]->displayInfo();
        coll[i]->stop();
    }


    ofstream out("fleet.txt");
    for (int i = 0; i < count; i++) {
        coll[i]->saveInfo(out);
    }
    out.close();

    ifstream in("fleet.txt");
    string type;

    FMS* loaded[n];
    int lcount = 0;

    while (in >> type) {
        FMS* v = nullptr;

        if (type == "Car") v = new Car();
        else if (type == "Bus") v = new Bus();
        else if (type == "Truck") v = new Truck();

        if (v) {
            v->loadInfo(in);
            loaded[lcount++] = v;
        }
    }
    in.close();

    cout << "\nLoaded Vehicles:\n";
    for (int i = 0; i < lcount; i++) {
        loaded[i]->displayInfo();
    }

    // -------- FREE MEMORY --------
    for (int i = 0; i < count; i++) delete coll[i];
    for (int i = 0; i < lcount; i++) delete loaded[i];

    return 0;
}
