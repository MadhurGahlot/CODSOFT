#include<iostream>
#include<random>
#include<ctime>
using namespace std;

int main(){
    mt19937 gen(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<> distr(1, 100);
    int number;
    number = distr(gen);
    cout<<"The random no is: "<<number<<"\n";
    int guess;
    guess=0;
    while(!(guess ==number)){
        cout<<"Guess The No Between 1 And 100: ";
        cin>>guess;
        if (guess < number) {
        cout << "Too low! The number is higher than " << guess << ".\n";
        }
        else if (guess > number) {
         cout << "Too high! The number is lower than " << guess << ".\n";
        }
        else {
            cout << "Congratulations! You guessed " << number << "\n";
        }
    }
    return 0;
}