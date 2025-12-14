/*2. Leia um numero fornecido pelo usuario. Se esse numero for positivo, calcule a raiz
quadrada do numero. Se o numero for negativo, mostre uma mensagem dizendo que o
numero e invalido.*/

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

using std::fixed;
using std::setprecision;

int main(){
    int num;
    double raizQuadrada;

    cout << "Insira um numero: " << endl;
    cin >> num;

    cout << fixed << setprecision(4);
    if (num >= 0){
        raizQuadrada = sqrt(num);
        cout << "Raiz quadrada de " << num << " = " << raizQuadrada << endl;
    }
    else{
        cout << "Numero invalido. Tem que ser positivo." << endl;
    }
    return 0;

}
