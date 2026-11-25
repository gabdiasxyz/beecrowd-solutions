#include <bits/stdc++.h>
using namespace std;

/*
    X = 60, Y = 90 ---> dist/min = (Y-X)/60 = 30/60 = 0.5 km/min
    --> T*0.5 = D ---> T = D*2
*/

int main(){
    int distance;
    cin >> distance;

    cout << distance*2 << " minutos\n";
    return 0;
}