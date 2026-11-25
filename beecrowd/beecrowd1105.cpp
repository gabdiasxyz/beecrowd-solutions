#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool possible;
    int amount[21];
    int B,N,debtor,creditor,value;

    while(cin >> B >> N){
        if(!B && !N) break;

        for(int i=1;i<=B;i++) cin >> amount[i];
        
        for(int i=0;i<N;i++){
            cin >> debtor >> creditor >> value;

            amount[debtor] -= value;
            amount[creditor] += value;
        }

        possible = true;
        for(int i=1;i<=B;i++){
            if(amount[i]<0){
                possible = false;
                break;
            }
        }

        cout << (possible ? 'S' : 'N') << endl;
    }

    return 0;
}