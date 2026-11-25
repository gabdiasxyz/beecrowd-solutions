#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159

int main(){
    double A,B,C;
    cin >> A >> B >> C;
    cout << fixed << setprecision(3) << "TRIANGULO: " << A*C*0.5 << endl;
    cout << fixed << setprecision(3) << "CIRCULO: " << PI*C*C << endl;
    cout << fixed << setprecision(3) << "TRAPEZIO: " << (B+A)*C*0.5 << endl;
    cout << fixed << setprecision(3) << "QUADRADO: " << B*B << endl;
    cout << fixed << setprecision(3) << "RETANGULO: " << A*B << endl;
    return 0;
}