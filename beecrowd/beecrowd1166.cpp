#include <bits/stdc++.h>
using namespace std;

bool perfect_square(int n){
    if(n<0) return false;
    if(n==0) return true;
    int root = static_cast<int>(round(sqrt(n)));
    return root*root==n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> peg_tops(n,0);
        int current_ball = 1;

        while(true){
            bool placed = false;
            
            for(int i=0;i<n;i++){
                if(peg_tops[i]==0 || perfect_square(peg_tops[i]+current_ball)){
                    peg_tops[i] = current_ball;
                    placed = true;
                    break;
                }
            }

            if(!placed){
                cout << current_ball-1 << endl;
                break;
            }

            current_ball++;
        }
    }

    return 0;
}