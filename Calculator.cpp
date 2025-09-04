#include<iostream>
#include<string>
using namespace std;
double onlydouble(string prompt){
 string input;
 double num;

 while(true){
    cout<<prompt;
    getline(cin,input);
    try{
        num=stod(input);// This convert the string into decimal input
        return num;
    }
    catch(...){
     cout<<"Please Enter a valid integer ..."<<"\n";
    }

 }
}

class calculator{
    public:
double a,b;

public: 
//Constructor
calculator(double a ,double b){
   this->a = a;
   this->b = b;
}

double sum(){
    return a + b;
}

double substraction(){
    return a - b ;
}

double multiplication(){
    return a*b;
}

double division(){
    if(b==0){        // IF b==0 the division will became infinite
        return 0;
    }
    else{
        double result;
        result=(a /b);
        return result;
        }
}
//destructor
~calculator(){
    cout<<" ";
};

};

int main(){
    double num1 ,num2;
    char choice;
    int operation;
do{
num1=onlydouble("Enter the first number: ");
num2=onlydouble("Enter the second number: ");
calculator c1(num1 , num2);
cout<<"CHOOSE THE OPERATION :      "<<"\n";
cout<<"1 for ADDITION       "<<"\n";
cout<<"2 for SUBSTRACTON    "<<"\n";
cout<<"3 for MULTIPLICATION "<<"\n";
cout<<"4 for DIVISION       "<<"\n";
cin>>operation;
cin.ignore();

switch(operation){
case 1:
 cout<<"The addition of "<< num1 << " and "<< num2 <<" is "<< c1.sum() <<": \n";
 break;

case 2: 
 cout<<"The substraction of "<< num1 << " and "<< num2 <<" is "<< c1.substraction() <<": \n";
 break;

case 3:
 cout<<"The multiplication of "<< num1 << " and "<< num2 <<" is "<< c1.multiplication() <<": \n";
 break;

case 4:
 cout<<"The division of "<< num1 <<" and "<< num2 << " is "<< c1.division() <<": \n";
 break;

  default:
    cout<<"Enter a valid operaton..... "<<"\n";
  
}
cout<<"DO you want to perform another operation ( Y/N ): "<<"\n";
cin>>choice;
cin.ignore();
cout<<".............................................."<<"\n";
}
while(choice == 'Y' || choice == 'y');

return 0;
}