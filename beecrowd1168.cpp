#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int leds_per_digit[] = {6,2,5,5,4,5,6,3,7,6}; // indx = digito
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        string value_str;
        cin >> value_str;

        long long total = 0;
        for(char digit_char : value_str){
            int digit = digit_char-'0';
            total += leds_per_digit[digit];
        }

        cout << total << " leds" << endl;
    }

    return 0;
}