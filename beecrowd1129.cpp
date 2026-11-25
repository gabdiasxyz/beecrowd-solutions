#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n && n!=0){
        for(int i=0;i<n;i++){
            int values[5];
            int marked_count = 0;
            int marked_idx = -1;

            for(int j=0;j<5;j++){
                cin >> values[j];
                if(values[j]<=127){
                    marked_count++;
                    marked_idx = j;
                }
            }

            if(marked_count==1){
                char ans = 'A'+marked_idx;
                cout << ans << endl;
            }else cout << '*' << endl;
        }
    }

    return 0;
}