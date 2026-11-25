#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(2);

    int n;
    while(cin>>n && n!=0){
        vector<int64> expenses(n);
        int64 total = 0;
        for(int i=0;i<n;i++){
            double amount;
            cin >> amount;

            expenses[i] = (int64)round(amount*100.0);
            total += expenses[i];
        }
        int64 avg_cents = total/n;
        int64 rem_cents = total%n;

        sort(expenses.begin(),expenses.end());

        int64 positive_diff_sum = 0;
        for(int i=0;i<n;i++){
            int64 fair_share;
            if(i<n-rem_cents) fair_share = avg_cents;
            else fair_share = avg_cents+1;

            if(expenses[i]>fair_share) positive_diff_sum += (expenses[i]-fair_share); // povo pao duro do krl
        }
        
        double result = (double)positive_diff_sum/100.0;
        cout << "$" << result << '\n';
    }

    return 0;
}