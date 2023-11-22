#include <iostream>
#include <a.out.h>
#include <cstring>
using namespace std;



class Person{
    char* firstname;
    char* lastname;
    char* sdi;
    static int plithos ;
    int numoffirstanme;
    int numoflastname;
    int numofsdi;



    public:
        Person();
        Person(char* f , char* l , char* s );
        ~Person();
        Person(const Person &p);
        static void showplithos();
        friend istream &operator >>(istream &str, Person &obj);
        friend ostream &operator <<(ostream &str , Person &obj);


};
Person::Person():firstname(0), lastname(0),sdi(0), numoffirstanme(0),numoflastname(0),numofsdi(0){
    plithos++;
}

Person::Person(const Person &p){
    firstname= p.firstname;
    lastname= p.lastname;
    sdi=p.sdi;
    numoffirstanme= p.numoffirstanme ;
    numoflastname=p.numoflastname;
    numofsdi=p.numofsdi;
}

Person::Person(char* f , char* l , char* s):numoffirstanme(strlen(f)), numoflastname(strlen(l)), numofsdi(strlen(s)){
    firstname = new char[numoffirstanme+1];
    lastname = new char[numoflastname +1];
    sdi = new char[numofsdi + 1];
    plithos++;
}

Person::~Person(){
    delete[] firstname;
    delete[] lastname;
    delete[] sdi;
    plithos--;
}

 void Person::showplithos(){
    cout<<"number of person are "<< plithos << endl;
}

istream &operator >> (istream  &str , Person &obj ){
    cout<<"give firstname";
    str >> obj.firstname;
    cout << "give number of letter firstname";
    str >> obj.numoflastname;

    cout<<"give lattname";
    str >> obj.lastname;
    cout << "give number of letter lastname";
    str >> obj.numoflastname;

    cout<<"give sdi";
    str >> obj.sdi;
    cout << "give number of letter sdi";
    str >> obj.numofsdi;
    return str;
}

ostream &operator << (ostream &str , Person &obj){
    str<< obj.firstname <<endl;
    str<< obj.lastname <<endl;
    str<< obj.sdi <<endl;
    return str;
}


int  Person::plithos=0; 


int main(){


 


}