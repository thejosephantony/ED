/*1. Faça um programa que receba dois numeros e mostre qual deles é o maior.*/


#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int a;
    int b;

    cout << "Numero 1: " << endl;
    cin >> a;

    cout << "Numero 2: " << endl;
    cin >> b;

    if (a > b){
        cout << a << " > " << b << endl;
    }
    else if (b > a){
        cout << b << " > " << a << endl;
    }
    else{
        cout << a << " = " << b << endl;
    }
    return 0;
}
