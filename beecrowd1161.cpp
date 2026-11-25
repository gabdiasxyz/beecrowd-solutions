#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int64 factorial(int n) {
    int64 fat = 1;
    for(int i=1;i<=n;i++) fat *= i;
    return fat;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n;

    while(cin >> m >> n){
        int64 sum = factorial(m) + factorial(n);
        cout << sum << endl;
    }

    return 0;
}