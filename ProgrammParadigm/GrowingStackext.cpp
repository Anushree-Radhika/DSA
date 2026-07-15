#include<iostream>
using namespace std;

class GrowingStack{

    private:

        int cap,idx,maxcap;
        int *digit;
        static int objectCOUNT;
        GrowingStack(){
            idx = -1;
            objectCOUNT++;
            cout << "Stack is created. Total:" << objectCOUNT << endl;
        }   
        static const int MAX = 5;

    public:
        static GrowingStack* stack(){
            if(objectCOUNT < MAX){
                return new GrowingStack();
            }
            else{
                cout << "Maximum stack limit reached.\n";
                return nullptr;
            }

        }

        bool isEmpty(){
                if(this->idx == 0){
                        return true;
                }
                else{
                        return false;
                }
        }

        void inflate(){

                if (this->cap == this->maxcap) {
                        cout << "No more insertions possible\n";
                        return ;
                }

                int newCap;
                if (this->cap * 2 <= this->maxcap) {
                        newCap = this->cap * 2;
                        cout << "Inflating the stack\n";
                }
                else {
                        newCap = this->maxcap;
                        cout << "Last inflation\n";
                }
                int* newArr = new int[newCap];

                // Copy existing elements (NO pop)
                for (int i = 0; i <= this->idx; i++) {
                        newArr[i] = this->digit[i];
                }
                
                delete[] digit;
                digit = newArr;
                cap = newCap;

                return ;
        }

        void top(){
                if(isEmpty()){
                        cout << "Stack is empty" << "\n";
                        return ;
                }
                int x = digit[idx - 1];
                cout << "Topmost element is:" << x <<"\n";
                return ;
        }

        bool isFull(){
                if(cap == idx){
                        return true;
                }
                else{
                        return false;
                }
        }

        void initialize(){
                cout << "Enter the size of the stack\n";
                cin >> cap;
                cout <<"Enter the maximum size of the stack\n";
                cin >> maxcap;
                idx = 0;
                digit  = new int[cap];
                if(!digit){
                        cout << "Stack initialization invalid\n";
                }
                return;
        }
        void push(int x){
            if (this->isFull()) {
                    if(this->cap < this->maxcap){
                            this->inflate();

                    }
                    else{
                            cout << "No elements can be pushed in the stack" << "\n";
                            return ;
                    }
            }
            this->digit[this->idx] =  x;
            this->idx += 1;
            cout << "Successful insertion" << "\n";
            return ;
        }

        int pop(){
                if(this->isEmpty()){
                        cout << "No elements to pop" << "\n";
                        return 0;
                }
                else{
                        int t = this->digit[this->idx - 1];
                        this->idx --;
                        cout << "The popped element is:" << t << "\n";
                        return t;
                }
        };

        int getMaxSize(){
                return this->maxcap;
        };
        int currentSize(){
                return this->idx;
        }
};
int GrowingStack :: objectCOUNT = 0;
int main(){

        GrowingStack*s = GrowingStack :: stack();
        GrowingStack*s2 = GrowingStack :: stack();
        GrowingStack*s3 = GrowingStack :: stack();
        GrowingStack*s4 = GrowingStack :: stack();
        GrowingStack*s5 = GrowingStack :: stack();
        GrowingStack*s6 = GrowingStack :: stack();

        while(1){
                cout << "\nMENU" << "\n";
                cout << "-----------------------\n";
                cout << "1.Check if its empty" << "\n";
                cout << "2.Check if its full" << "\n";
                cout << "3.Push an element" << "\n";
                cout << "4.Pop an element" << "\n";
                cout << "5.Get max size" << "\n";
                cout << "6.Get topmost element" << "\n";
                cout << "7.Get current size" << "\n";
                cout << "8.Implementing function with 3 stack instances" << "\n";
                cout << "9.Initializing a stack\n";
                cout << "10.Exit\n";
                cout << "Enter your choice\n" ;

                int choice;
                cin >> choice;

                switch(choice){
                        case 1:{
                               if((s)->isEmpty()){
                                       cout << "Stack is empty\n";
                               }
                               else{
                                       cout << "Stack is not empty\n";
                               }
                               break;
                       }
                case 2:{
                               if(s->isFull()){
                                       cout << "Stack is full\n";
                               }
                               else{
                                       cout << "Stack is not full\n";
                               }
                               break;
                                                      }
                case 3:{
                               cout << "Input element to insert\n";
                               int x;
                               cin >> x;
                               s->push(x);
                               break;
                       }
                case 4:{
                               s->pop();
                               break;
                       }
                case 5:{
                                cout << s->getMaxSize() << "\n";
                                break;
                        }
                case 6:{
                               s->top();
                               break;
                       }
                case 7:{
                                cout <<  s->currentSize() << "\n";
                                break;
                       }
                case 8:{
                               cout << "Initializing three stacks together\n";
                               cout << "Initializing stack 1\n";
                               s2->initialize();
                               cout << "Input number of elements to insert in stack1\n";
                               int y;
                               cin >> y;
                               while(y--){
                                        int x;
                                        cin >> x;
                                        s2->push(x);
                                }
                                cout << "Initializing stack 2\n";
                                s3->initialize();
                                cout << "Input size of elements to insert in stack2\n";
                                                 cin >> y;
                                while(y--){
                                        int x;
                                        cin >> x;
                                        s3->push(x);
                                }
                                cout << "Initializing stack3\n";
                                s4->initialize();

                                while(!(s3->isEmpty()) && !(s2->isEmpty())){
                                        s4->push(s2->pop());
                                        s4->push(s3->pop());
                                }
                                while(!s2->isEmpty()){
                                      s4->push(s2->pop());
                                }
                                while(!s3->isEmpty()){
                                      s4->push(s3->pop());
                                }

                                cout << "Do you want to check elements present in stack3\n If yes write 1 and if no 0\n";
                                int z;
                                cin >> z;
                                if(z){
                                        while(!s4->isEmpty()){
                                                s4->pop();
                                        }
                                }
                                break;

                       }
                case 9:{
                                s->initialize();
                                break;
                       }
                case 10:{
                                cout << "Exitting\n";
                                return 0;
                        }
                default:{
                                cout << "Choose some other input\n";
                                break;
                       }
                }
        }

        return 0;
}
