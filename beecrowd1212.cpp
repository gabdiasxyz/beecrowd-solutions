#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n1,n2;

    while(cin >> n1 >> n2 && (n1!=0 || n2!=0)){
        int carries = 0; int carry = 0;

        while (n1>0 || n2>0) {
            int d1 = n1%10; int d2 = n2%10;

            int sum = d1+d2+carry;

            if(sum>=10){
                carry = 1;
                carries++;
            }else carry = 0;

            n1 /= 10;
            n2 /= 10;
        }

        if(carries==0) cout << "No carry operation.\n";
        else if(carries==1) cout << "1 carry operation.\n";
        else cout << carries << " carry operations.\n";
    }

    return 0;
}