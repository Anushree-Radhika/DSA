#include<iostream>
#include<cstring>
using namespace std;

class Book{
    private:
        char * title;
        int pages;
    public:
        // Default construtor
        Book(){
            title = nullptr;
            pages = 0;
        };
        //Parameterized constructor
        Book(char* tt , int pgs){
            title = new char[strlen(tt) + 1];
            strcpy(title,tt);
            this->pages = pgs;
        }

        // Copy constructor
        Book(const Book & b):pages(b.pages){
            title = new char[strlen(b.title) + 1];
            strcpy(title,b.title);
        }
        // Assignment operator
        Book & operator = (const Book &b){
            if(this != &b){
                delete[] title;
                pages = b.pages;
                title = new char[strlen(b.title) + 1];
                strcpy(title,b.title);
            }
            return *this;
        }

        void ReadData(int pag, char * tt){
            title = new char[strlen(tt) + 1];
            strcpy(title,tt);
            this->pages = pag;
        }

        virtual void DisplayData(){
            cout << "Title :" << title << endl;
            cout << "Pages :" << pages << endl;
        }
};

class Ebook : public Book{
    private:
        double file_size; 
        char * format;
    
    public:
        // Default construtor
        Ebook(){
            file_size = 0;
            format = nullptr;
        };
        //Parameterized constructor
        Ebook(char * tit,int pag,double filesize,char * formt) : Book(tit , pag){
            file_size = filesize;
            format = new char[strlen(formt) + 1];
            strcpy(format,formt);
        }
        // Copy constructor
        Ebook(const Ebook &eb):Book(eb),file_size(eb.file_size){
            format = new char[strlen(eb.format) + 1];
            strcpy(format,eb.format);
        }
        // Assignment operator
        Ebook & operator = (const Ebook &eb){
            if(this != &eb){
                delete[] format;
                Book :: operator = (eb);
                file_size = eb.file_size;
                format = new char[strlen(eb.format) + 1];
                strcpy(format,eb.format);
            }
            return *this;
        }

        void ReadData(int pag, char * tt,char *f,double filesize){
            Book :: ReadData(pag,tt);
            format = new char[strlen(f) + 1];
            strcpy(format,f);
            this->file_size = filesize;
        }
        void DisplayData() override{
            Book :: DisplayData();
            cout << "FileSize :" << file_size << endl;
            cout << "Format :" << format << endl;
        }

};


int main(){

    double fs;int pgs;
    char * title , *form;
    int x,f;
    cout << "Enter the number of pages in the book: " << endl;
    cin >> pgs; 
    cout << "Enter the file-size\n";
    cin >> fs;
    cout << "Input the length of the title\n";
    cin >> x;
    cout << "Input the length of the format\n";
    cin >> f;

    cout << "Input the title\n";
    title = new char[x+1];
    cin.ignore();
    cin.getline(title,x);
    cout << "Input the format\n";
    form = new char[f+1];
    cin.ignore();
    cin.getline(form ,f);
    Book * b;
    b = new Ebook(title,pgs,fs,form);

    b->DisplayData();  
}
