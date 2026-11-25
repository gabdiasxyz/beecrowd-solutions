#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n;
    cin >> n;

    vector<int> notes = {10000,5000,2000,1000,500,200}; // em centavos
    vector<int> coins = {100,50,25,10,5,1};

    int64 total = round(n*100);
    cout << fixed << setprecision(2);

    cout << "NOTAS:" << endl;
    for(int note : notes){
        int64 count = total/note;
        cout << count << " nota(s) de R$ " << (double)note/100.0 << endl;
        total %= note;
    }
    cout << "MOEDAS:" << endl;
    for(int coin : coins){
        int64 count = total/coin;
        cout << count << " moeda(s) de R$ " << (double)coin/100.0 << endl;
        total %= coin;
    }

    return 0;
}