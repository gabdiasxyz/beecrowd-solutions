#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int64 gcd(int64 a,int64 b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        int64 n1,d1,n2,d2;
        char op,slash;
        
        // format: n1/d1 op n2/d2
        cin >> n1 >> slash >> d1 >> op >> n2 >> slash >> d2;

        int64 n,d;
        switch(op){
            case '+':
                n = n1*d2 + n2*d1;
                d = d1*d2;
                break;
            case '-':
                n = n1*d2 - n2*d1;
                d = d1*d2;
                break;
            case '*':
                n = n1*n2;
                d = d1*d2;
                break;
            case '/':
                n = n1*d2;
                d = n2*d1;
                break;
        }

        int64 common_divisor = gcd(abs(n),abs(d));
        int64 ns = n/common_divisor;
        int64 ds = d/common_divisor;

        if(ds<0){ ds *= -1; ns *= -1; }

        cout << n << "/" << d << " = " << ns << "/" << ds << endl;
    }

    return 0;
}