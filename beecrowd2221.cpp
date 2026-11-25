#include "bits/stdc++.h"
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int B;
        int A1,D1,L1;
        int A2,D2,L2;

        cin >> B;
        cin >> A1 >> D1 >> L1;
        cin >> A2 >> D2 >> L2;

        double val1 = (A1+D1)/2.0;
        double val2 = (A2+D2)/2.0;

        if(L1%2==0) val1 += B;
        if(L2%2==0) val2 += B;

        if(val1>val2) cout << "Dabriel" << endl;
        else if(val2>val1) cout << "Guarte" << endl;
        else cout << "Empate" << endl;
    }
}