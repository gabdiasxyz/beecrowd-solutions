#include <bits/stdc++.h>
using namespace std;

int main(){
    int value;
    cin >> value;

    int type[] = {100,50,20,10,5,2,1};

    cout << value << endl;
    for(int i=0;i<7;i++){
        cout << (value/type[i]) << " nota(s) de R$ " << type[i] << ",00\n";
        value %= type[i];
    }

    return 0;
}