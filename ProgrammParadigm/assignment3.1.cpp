#include<bits/stdc++.h>
using namespace std;


class ComplexNum{

    private:
        int real;
        int img;

    public:
        ComplexNum(int r = 0,int i = 0):real(r),img(i){};
        ComplexNum operator+(const ComplexNum &);
        ComplexNum operator-(const ComplexNum &);

        void display(){
            if(this->img < 0){
                cout << this->real << this->img << "i" << endl;
            }
            else{
                cout << this->real << "+" << this->img << "i" << endl;
            }
        }
};


ComplexNum ComplexNum::operator+(const ComplexNum &a){
    ComplexNum temp;
    temp.real = this->real + a.real;
    temp.img = this->img + a.img;
    return temp;
}

ComplexNum ComplexNum::operator-(const ComplexNum &a){
    ComplexNum temp;
    temp.real = this->real - a.real;
    temp.img = this->img - a.img;
    return temp;
}

int main(){

    cout << "Lets first input two complexNumbers to add and the same to subtract" << endl;
    int rl1,img1,rl2,img2;
    cout << "Input the real part of the first Complex Number" << endl;
    cin >> rl1;
    cout << "Input the real part of the second Complex Number" << endl;
    cin >> rl2;
    cout << "Input the imaginary part of the first Complex Number" << endl;
    cin >> img1;
    cout << "Input the imaginary part of the second Complex Number" << endl;
    cin >> img2;

    ComplexNum a(rl1,img1);
    ComplexNum b(rl2,img2);
    ComplexNum c = a+b, d = a-b;
    cout << "The addition of the input numbers:" << endl;
    c.display();
    cout << "The subtraction of the input numbers:" << endl;
    d.display();
}
