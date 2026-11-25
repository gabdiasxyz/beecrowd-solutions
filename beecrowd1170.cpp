#include <bits/stdc++.h>
using namespace std;

// x/2^d <= 1 ---> x <= 2^d --> d >= log2(x)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(cin >> n){
        while(n--){
            double x;
            cin >> x;
            
            int d = ceil(log2(x));
            
            cout << d << " dias\n";
        }
    }

    return 0;
}