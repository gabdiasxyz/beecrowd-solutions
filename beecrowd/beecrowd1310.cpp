#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n){
        int per_day_cost;
        cin >> per_day_cost;

        int max_profit = 0; int current_profit = 0;

        for(int i=0;i<n;i++){
            int revenue;
            cin >> revenue;

            int daily_net = revenue-per_day_cost;
            current_profit += daily_net;

            if(current_profit<0) current_profit = 0;

            max_profit = max(max_profit,current_profit);
        }
        cout << max_profit << endl;
    }

    return 0;
}