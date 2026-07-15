#include<iostream>
using namespace std;
#define N 15

class Shape{

        public:
                virtual void display() = 0;
                virtual double Area() = 0;

               
            virtual ~Shape() {}

};
class ShapeStack{
        int sz;

        public:
                Shape **s;
                static int top;

                ShapeStack(int sz):sz(sz){
                        s = new Shape*[sz];
                }

                void push(Shape *sh){
                        s[top] = sh;
                        top++;
                }
                Shape* pop(){
                        if(top == -1){
                                cout << "No more shapes to pop." << endl;
                                return NULL;
                        }
                        return s[--top];
                }

};
int ShapeStack :: top = 0;
class Circle : public Shape{

        private:
            double radius;

        public:

                Circle(double r):radius(r){}
                void display(){
                        cout << "Radius :" << radius;
                }
                double Area(){
                        return 2*3.14*radius;
                }

};
class Triangle : public Shape{

        double base, height;

        public:
                Triangle(double b,double h):base(b),height(h){}
                void display(){
                        cout << "Base :" << base;
                        cout << "Height :" << height;
                }
                double Area(){
                        return 0.5*base*height;
                }

};
class Rectangle : public Shape{

        double length, breadth;

        public:
                Rectangle(double l,double b):length(l),breadth(b){}
                void display(){

                        cout << "Length :" << length;
                        cout << "Breadth :" << breadth;
                }
                
                double Area(){
                        return length*breadth;
                }

};
int main(){

        int size;
        cout << "Enter the number of shapes that you want to store:\n";
        cin >> size;

        ShapeStack stack(size);

        while(1){
        cout << "MENU\n";
        cout << "------------\n";
        cout << "1.Push a shape 2.Pop a Shape \n";
        int cho,k = 0;
        cin >> cho;
        if(cho ==  1){

                while(k < size){
                        cout << "MENU\n";
                        cout << "Enter the shape you want to insert 1.Circle 2.Traiangle 3.Rectangle\n";
                        int choice;
                        cin >> choice;
                        switch(choice){
                                case 1:{
                                        double r;
                                        cout << "Radius :" << endl;
                                        cin >> r;
                                        Circle* s = new Circle(r);
                                        stack.push(s);
                                        break;
                                }

                                        case 2:{
                                                double b,h;
                                                cout << "Base and Height :";
                                                cin >> b >> h;
                                                Triangle* s = new Triangle(b,h);
                                                stack.push(s);
                                                break;
                                        }

                                        case 3:{
                                                double l,b;
                                                cout << "Length and Breadth :";
                                                cin >> l >> b;
                                                Rectangle* s = new Rectangle(l,b);
                                                stack.push(s);
                                                break;
                                        }
                                        case 4:{
                                                cout << "Exiting..\n";
                                                break;
                                        }
                                }
                                k++;
                        }
                }
                else{
                        Shape *sha = stack.pop();
                        if(sha != NULL){
                                sha->display();
                                delete sha;
                        }
                }
                cout << "Do you want to end(enter 0)" << endl;
                int fg = 1;
                cin >> fg;
                if(fg == 0){
                        break;
                }

        }

        double sum = 0;
        for(int i = 0;i<stack.top;i++){
                sum += stack.s[i]->Area();
        }
        cout << "Total calculated Area :" << sum;
        return 0;
}
