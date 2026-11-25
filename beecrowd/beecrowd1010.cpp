#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int code1, units1; double price1;
    int code2, units2; double price2;

    cin >> code1 >> units1 >> price1;
    cin >> code2 >> units2 >> price2;

    double total_cost = (units1*price1)+(units2*price2);

    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << total_cost << endl;

    return 0;
}
