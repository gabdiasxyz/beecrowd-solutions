#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    while(getline(cin,str1)){
        getline(cin,str2);

        int len1 = str1.length();
        int len2 = str2.length();

        if(len1==0 || len2==0){
            cout << 0 << endl;
            continue;
        }

        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        int maxlen = 0;

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    maxlen = max(maxlen,dp[i][j]);
                }else dp[i][j] = 0;
            }
        }

        cout << maxlen << endl;
    }
    return 0;
}