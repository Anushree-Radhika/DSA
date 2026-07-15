#include"array.h"
#include<iostream>
using namespace std;

int main(){
        printf("Enter the option from the functions:\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
                  case 1:{
                                cout << "ENter the size of the array" << endl;
                                int n;
                                cin >> n;
                                int numbers[n];
                                for(int i=0;i<n;i++){
                                        cin >> numbers[i];
                                }
                                cout << "THe largest number in the array" << endl;
                                int m = largest(numbers,0,-1e9,n);
                                cout << m  << endl;
                                return 0;
                        }
                case 2:{
                                cout << "ENter the size of the array" << endl;
                                int n,key;
                                cin >> n >> key;
                                int numbers[n];
                                for(int i=0;i<n;i++){
                                        cin >> numbers[i];
                                }
                                bool  m = checker(numbers,0,key,n);
                                cout << m  << endl;
                                return 0;

                }
                case 3:{
                                cout << "ENter the size of the array" << endl;
                                int n;
                                cin >> n;
                                                   int num[n];
                                for(int i=0;i<n;i++){
                                        cin >> num[i];
                                }
                                reverse(num,n,0);
                                return 0;
                        }
                case 4:{
                                int n;
                                cin >> n;
                                int num[n];
                                for(int i=0;i<n;i++){
                                        cin >> num[i];
                                }
                                int sm = 0;
                                sm = sum(0,num,n,0);
                                cout << sm << endl;
                                return 0;
                        }
        }
}