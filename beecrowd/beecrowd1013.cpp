#include <bits/stdc++.h>
using namespace std;

// ao inves de fazer do jeito chato de só usar std::max, vamos fazer de um jeito mais legal

int my_abs(int n){
    if(n<0) return -n;
    return n;
}
int my_max(int a,int b){
    return (a+b+my_abs(a-b))/2;
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << my_max(a,my_max(b,c)) << " eh o maior\n";
    return 0;
}