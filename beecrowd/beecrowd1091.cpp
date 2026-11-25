#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    while(cin>>k && k!=0){
        int div_n, div_m;
        cin >> div_n >> div_m;

        for(int i=0;i<k;i++){
            int x,y;
            cin >> x >> y;
            if(x==div_n || y==div_m) cout << "divisa" << endl;
            else if(x>div_n && y>div_m) cout << "NE" << endl;
            else if(x<div_n && y>div_m) cout << "NO" << endl;
            else if(x>div_n && y<div_m) cout << "SE" << endl;
            else /* x>div_n && y>div_m */ cout << "SO" << endl;
        }
    }

    return 0;
}