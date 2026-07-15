#include<iostream>
using namespace std;

class WareHouse{

    public:
        virtual void display() = 0;
        virtual double calVolume() = 0; // pure virtual function
};
// -----------------BOX-----------------------
class Box : public WareHouse{
    private:
        double l,b,h;
    public:
        Box(double l,double b,double h):l(l),b(b),h(h){}
        void display() override{
            cout << "Length :" << l << endl;
            cout << "Breadth :" << b << endl;
            cout << "Height :" << h << endl;
        }
        virtual double calVolume(){
            return l*b*h;
        }
};

// -----------------CYLINDER-----------------------
class Cylinder : public WareHouse{
    private:
        double r,h;
    public:
        Cylinder(double r,double h):r(r),h(h){}
        void display() override{
            cout << "Radius :" << r << endl;
            cout << "Height :" << h << endl;
        }
        virtual double calVolume() {
            return 3.14*r*r*h;
        }
};

// -----------------PYRAMID-----------------------
class Pyramid : public WareHouse{
    private:
        double s,h;
    public:
        Pyramid(double s,double h):s(s),h(h){}
        void display() override{
            cout << "Side :" << s << endl;
            cout << "Height :" << h << endl;
        }
        virtual double calVolume() {
            return (1.0/3)*s*s*h;
        }
};
int main(){

    int n,k = 0,m;
    cout << "Enter the number of shapes or elements in the Warehouse\n";
    cin >> n;
    WareHouse* warehouse[n];
    m = n;
    while(n--){

        cout << "-----MENU-----\n";
        cout << "   1.Box   \n";
        cout << "   2.Cylinder   \n";
        cout << "   3.Pyramid   \n";
        int choice;
        cin >> choice;

        switch(choice){

            case 1:{
                double l,b,h;
                cout << "Enter the length of the box\n";
                cin >> l;
                cout << "Enter the breadth of the box\n";
                cin >> b;
                cout << "Enter the height of the box\n";
                cin >> h;

                warehouse[k] = new Box(l,b,h);
                k++;
                break;
            }
            case 2:
            {
                double r,h;
                cout << "Enter the radius of the cylinder\n";
                cin >> r;
                cout << "Enter the height of the cylinder\n";
                cin >> h;

                warehouse[k] = new Cylinder(r,h);k++;
                break;
            }
            case 3:{
                double s,h;
                cout << "Enter the baseArea of the cylinder\n";
                cin >> s;
                cout << "Enter the height of the cylinder\n";
                cin >> h;

                warehouse[k] = new Pyramid(s,h);k++;
                break;
            }
            default:{
                cout << "Input some other value" << endl;
            }
        }
    }

    double totalsum = 0;

    for(int i =0;i<m;i++){
        warehouse[i] -> display();
        double vol = warehouse[i]->calVolume();
        cout << "Volume :" << vol << endl;
        totalsum += vol;
    }

    cout << "Total Volume of the shapes contained in the warehouse :" << totalsum;  
}
