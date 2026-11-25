#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int time;
    cin >> time;

    cout << time/3600 << ":" << time/60%60 << ":" << time%60 << endl;
    
    return 0;
}