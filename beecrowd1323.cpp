#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n && n!=0){
        // os numeros de quadrados nxi dentro da grid nxn é dado por (n - i + 1)^2
        // entao a soma é: 1^2 + 2^2 + 3^3 ... + n^2 -> n*(n+1)*(2*n+1)/6
        long long total_squares = (long long)(n*(n+1)*(2*n+1)/6);
        cout << total_squares << endl;
    }

    return 0;
}