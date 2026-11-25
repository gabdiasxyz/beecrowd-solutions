#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int64 sum_up_to(int64 n){
    if(n<=0) return 0;
    return n*(n+1)*0.5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 A,B;
    while(cin>>A>>B){
        int64 total = sum_up_to(B)-sum_up_to(A-1);
        cout << total << endl;
    }

    return 0;
}