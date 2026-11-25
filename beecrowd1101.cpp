#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    while(cin>>m>>n && m>0 && n>0){
        int start = min(m,n);
        int end = max(m,n);

        int sum = 0;
        for(int i=start;i<=end;i++){
            cout << i << " ";
            sum += i;
        }

        cout << "Sum=" << sum << endl;
    }
}