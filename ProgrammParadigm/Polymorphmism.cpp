#include<bits/stdc++.h>
using namespace std;

class BankManager;
class BankAccount{
    private:

        long long AccNum;
        string AccName;
        double Balance;
        static int BankAccs;

    public:
        void read(long long accn,string accnm,double bal){
            AccNum = accn;
            AccName = accnm;
            Balance = bal;
        }
        friend class BankManager;
        BankAccount(){
            BankAccs++;
        }
        BankAccount(long long accn,string accnm,double bal):AccNum(accn),AccName(accnm),Balance(bal){};
};
int BankAccount :: BankAccs = 0;
class BankManager{
    public:

        void NumbankAcc(){
            cout << BankAccount:: BankAccs << endl;
        }
        void DisplayAcc(const BankAccount& a){
            cout << "Name:" << a.AccName<< endl;
            cout << "Account Number:" << a.AccNum<< endl;
            cout << "Balance:" << a.Balance << endl;
        }
        bool CheckBal(const BankAccount& a,double suffbal){
            if(a.Balance >= suffbal){
                cout << "Bank Account has sufficient Balance\n";
                return true;
            }
            return false;
        }
        void transfer(BankAccount &a,BankAccount &b,double transamt){
            if(CheckBal(a,transamt)){
                cout << "Transfering money from AccountNumber: "<< a.AccNum << "to" << b.AccNum << endl;
                a.Balance -= transamt;
                b.Balance += transamt;
                cout << "Successful\n";
            }
            else{
                cout << "Not enough Balance to transfer\n";
            }
        }
};
int main(){

    cout << "Number of Accounts\n";
    int nacc;
    cin >> nacc;
    BankAccount arr[nacc];
    for(int i = 0;i<nacc;i++){

        cout << "Enter details of the " << i+1 << "th Bank Account Holder\n";
        string name;long long acc;double bal;
        cout << "Enter Name:";
        cin >> name;
        cout << "Enter Account Number:";
        cin >> acc;
        cout << "Enter Balance:";
        cin >> bal;
        arr[i].read(acc,name,bal);
    }

    while(1){

        BankManager bm;
        cout << "MENU\n1.Number of Bank Accounts\n2.Display Account Details\n3.Transfer money between Two Accounts\n4.Check if an account has sufficient balance\n5.Exit\n";
        
        cout << "Choose a number\n";
        int choice;
        cin >> choice;

        switch(choice){

            case 1:{
                bm.NumbankAcc();
                break;
            }
            case 2:{
                cout << "Enter the index of the BankHolder you want details of\n";
                int idx;
                cin >> idx;
                bm.DisplayAcc(arr[idx]);
                break;
            }
            case 3:{
                int idx1,idx2;
                cout << "Enter the AccountNumbers from which tranfer will happen to one into: "<< idx1 << "to" << idx2 << endl;
                cin >> idx1 >> idx2;
                cout << "\nEnter the amount transfer\n";
                double tbal;
                cin >> tbal;
                bm.transfer(arr[idx1],arr[idx2],tbal);
                break;
            }
            case 4:{
                cout << "Enter the index of the BankHolder you want details of\n";
                int idx;
                cin >> idx;
                cout << "Enter the sufficient amount to transfer\n";
                double tbal;
                cin >> tbal;
                bm.CheckBal(arr[idx],tbal);
                break;
            }
            case 5:{
                cout << "Exitting\n";
                return 0;
            }
            default:{
                cout << "Choose a different number\n";
                break;
            }
        }
    }
    return 0;
}
