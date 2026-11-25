#include <bits/stdc++.h>
using namespace std;

// 0/1 knapsack problem

struct order {
    int time;
    int pizzas;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while(cin>>N && N!=0){
        int capacity;
        cin >> capacity;

        vector<order> orders(N);
        for(int i=0;i<N;i++) cin >> orders[i].time >> orders[i].pizzas;

        vector<int> dp(capacity+1,0);

        for(int i=0;i<N;i++){
            int current_time = orders[i].time;
            int current_pizzas = orders[i].pizzas;

            for(int j=capacity;j>=current_pizzas;j--) dp[j] = max(dp[j],dp[j-current_pizzas]+current_time);
        }

        cout << dp[capacity] << " min." << endl;
    }

    return 0;
}