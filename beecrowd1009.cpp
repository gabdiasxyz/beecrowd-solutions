#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string seller;
    double fixed_salary; double sales;

    cin >> seller >> fixed_salary >> sales;

    double bonus = sales*0.15;
    double salary = fixed_salary+bonus;

    cout << "TOTAL = R$ " << fixed << setprecision(2) << salary << endl;

    return 0;
}