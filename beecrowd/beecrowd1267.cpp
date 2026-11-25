#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,D,x;
    bool answer;
    vector<int> dinner;

    while(cin >> N >> D){
        if(!N && !D) break;

        answer = false;
        dinner.assign(N, 0);

        for(int i=0;i<D;i++){
            for(int j=0;j<N;j++){
                cin >> x;
                dinner[j] += x;
            }
        }

        for(int i=0;i<N;i++){
            if(dinner[i]==D){
                answer = true;
                break;
            }
        }

        cout << (answer ? "yes" : "no") << endl;
    }

    return 0;
}