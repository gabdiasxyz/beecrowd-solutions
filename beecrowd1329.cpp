#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n && n!=0){
        int mary_wins = 0;
        int john_wins = 0;
        int result;

        for(int i=0;i<n;i++){
            cin >> result;
            if(result==0) mary_wins++;
            else john_wins++;
        }

        cout << "Mary won " << mary_wins << " times and John won " << john_wins << " times" << endl;
    }

    return 0;
}