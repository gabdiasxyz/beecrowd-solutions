#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int employee_num; int worked_hours; double amount_hour;
    cin >> employee_num >> worked_hours >> amount_hour;

    double salary = worked_hours*amount_hour;

    cout << "NUMBER = " << employee_num << endl;
    cout << "SALARY = U$ " << fixed << setprecision(2) << salary << endl;

    return 0;
}