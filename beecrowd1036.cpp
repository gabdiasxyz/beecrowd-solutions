#include <bits/stdc++.h>
using namespace std;

void bhaskara(double a,double b,double c){
    if(a==0){
        cout << "Impossivel calcular\n";
        return;
    }
    double delta = b*b - 4*a*c;
    if(delta<0){
        cout << "Impossivel calcular\n";
        return;
    }
    double r1 = (-b+sqrt(delta))/(2*a);
    double r2 = (-b-sqrt(delta))/(2*a);

    cout << "R1 = " << r1 << endl;
    cout << "R2 = " << r2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a,b,c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(5);
    bhaskara(a,b,c);
    
    return 0;
}