#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int highest_value = -1; int highest_idx = 0;
    for(int i=1;i<=100;i++){
        int current;
        cin >> current;

        if(current>highest_value){
            highest_value = current;
            highest_idx = i;
        }
    }
    
    cout << highest_value << '\n';
    cout << highest_idx << '\n';

    return 0;
}