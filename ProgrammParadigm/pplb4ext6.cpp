#include<iostream>
#include <climits>
using namespace std;

 class Cricketer{

        string name;
        protected:
                string *country;
                int matchs;

        public:
                Cricketer(string n,int match):name(n),matchs(match){
                        country = new string[match+1];
                };

                virtual void display(){
                        cout << "Name :" << name;
                        cout << "Number of matches :" << matchs;
                }
};

class Batsman : virtual public Cricketer{

        protected:
                int *runs;
        public:
                Batsman(string n,int mth):Cricketer(n,mth){
                        runs = new int[mth+1];
                }
                virtual void display(){
                        for(int i = 1;i<matchs+1;i++){
                                cout << i <<"-th match against " << country[i] << " the runs scored are:" << runs[i] << endl;
                        }
                }

};
class Bowler : virtual public Cricketer{

        protected:
                int* wickets;
        public:
                Bowler(string n,int mth):Cricketer(n,mth){
                        wickets = new int[mth+1];
                }

                virtual void display(){
                        for(int i = 1;i<matchs+1;i++){
                                cout << i << "-th match against " << country[i] << " wickets taken are:" << wickets[i] << endl;
                        }
                }
};
class AllRounder : public Batsman,Bowler{

        public:

                AllRounder(string n,int mtch):Cricketer(n,mtch),Batsman(n,mtch),Bowler(n,mtch){}

                // Average Run
                double avgRun(){
                        double avgscore = 0;
                        for(int i = 1;i<(Batsman::matchs+1);i++){
                                avgscore += runs[i];
                        }
                        avgscore = avgscore/(Batsman::matchs);
                        return avgscore;
                }

                // Average Wicket
                double avgWic(){
                        double avgwic = 0;
                        for(int i =1;i<(Bowler::matchs+1);i++){
                                avgwic += wickets[i];
                                                        }
                        avgwic = avgwic/(Bowler::matchs);
                        return avgwic;
                }

                // Insertion of Runs and wickets per Match against a country
                void insertion(){

                        int m = Batsman :: matchs;
                        for(int i = 1;i< m+1;i++){
                                string n;
                                cout << "Country name:";
                                cin >> n;
                                Batsman :: country[i] = n;
                        }

                        for(int i = 1;i<m+1;i++){
                                cout << "Enter the number of wickets taken by the bowler  in the " << i << "-th match";
                                int wic;
                                cin >> wic;
                                wickets[i] = wic;
                        }

                        for(int i = 1;i <m+1;i++){
                                cout << "Enter the number of runs made in the " << i << "-th match";
                                int run;
                                cin >> run;
                                runs[i] = run;
                        }
                }

                // Highest wicket taken
                int highestWicket(){
                        int mx = INT_MIN,midx = 0;
                        for(int i =1;i<(Batsman :: matchs+1);i++){
                                if(mx < wickets[i]){
                                        mx = wickets[i];
                                        midx = i;
                                                                        }
                        }
                        cout << "The highest wickets obtained was against" << Batsman ::country[midx] ;
                        return wickets[midx];
                }

                // Maximum Runs
                int highestRun(){
                        int mx = INT_MIN,midx = 0;
                        for(int i = 1;i<(Batsman :: matchs+1);i++){
                                if(mx < runs[i]){
                                        mx = runs[i];
                                        midx = i;
                                }
                        }
                        cout << "The highest runs obtained was against" << Batsman :: country[midx] ;
                        return runs[midx];
                }

                void display(){

                        Batsman :: display();
                        Bowler:: display();
                }

};

int main(){

        cout << "Enter name:\n";
        string name;
        cin >> name;
        cout << "Enter no of matches:\n";
        int match;
        cin >> match;
        AllRounder C1(name,match);
        C1.insertion();
        C1.avgRun();
        C1.avgWic();
        int x = C1.highestRun();
        cout << "is: " << x << endl;
        int y = C1.highestWicket();
        cout << "is: " << y << endl;
        C1.display();

}