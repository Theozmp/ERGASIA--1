#include <iostream>
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
//constuctor
Person::Person():firstname(0), lastname(0),sdi(0), numoffirstanme(0),numoflastname(0),numofsdi(0){
    plithos++;
}
//copy constuctor
Person::Person(const Person &p){
    delete[]  firstname;
    delete[] lastname;
    delete[] sdi;
    numoffirstanme = p.numoffirstanme;
    numoflastname =p.numoflastname;
    numofsdi = p.numofsdi;

    firstname=new char[numoffirstanme+1];
    lastname=new char[numoflastname+1];
    sdi=new char[numofsdi+1];

    strcpy(firstname, p.firstname);
    strcpy(lastname, p.lastname);
    strcpy(sdi, p.sdi);

    plithos++;
}
//constructor
Person::Person(char* f , char* l , char* s):numoffirstanme(strlen(f)), numoflastname(strlen(l)), numofsdi(strlen(s)){
    firstname = new char[numoffirstanme + 1];
    lastname = new char[numoflastname + 1];
    sdi = new char[numofsdi + 1];
    plithos++;
}
//deconstuctor
Person::~Person(){
    delete[] firstname;
    delete[] lastname;
    delete[] sdi;
    plithos--;
}
//sunarthshsgia to plithos
 void Person::showplithos(){
    cout<<"number of person are "<< plithos << endl;
}
// sunarthshs gia  cin
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
//synarthshs gia cout
ostream &operator << (ostream &str , Person &obj){
    str<< obj.firstname <<endl;
    str<< obj.lastname <<endl;
    str<< obj.sdi <<endl;
    return str;
}


int  Person::plithos=0; //arxikopoihshsh


int main(){
    Person person1("John", "Doe", "12345");
    Person person2;

    cout << "Person 1: " << person1 << endl;

    cout << "Enter details for Person 2:" << endl;
    cin >> person2;

    cout << "Person 2: " << person2 << endl;

    // Show the count of Person objects
    person2.showplithos();

    return 0;


 


}