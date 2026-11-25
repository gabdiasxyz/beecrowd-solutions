#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

string binary(int64 decimal){
    string binary_str = bitset<64>(decimal).to_string();
    // we need to remove the leading 0s now
    size_t msb = binary_str.find('1');
    if(msb!=string::npos) return binary_str.substr(msb);
    else return "0";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    for(int i=1;i<=test_cases;i++){
        string num_str,base_str;
        cin >> num_str >> base_str;

        cout << "Case " << dec << i << ":" << endl;

        int64 decimal;

        if(base_str=="bin"){
            decimal = stoll(num_str,nullptr,2);
            cout << dec << decimal << " dec" << endl;
            cout << hex << decimal << " hex" << endl;
        }else if(base_str=="dec"){
            decimal = stoll(num_str,nullptr,10);
            cout << hex << decimal << " hex" << endl;
            cout << binary(decimal) << " bin" << endl;
        }else{ // base_str == "hex"
            decimal = stoll(num_str,nullptr,16);
            cout << dec << decimal << " dec" << endl;
            cout << binary(decimal) << " bin" << endl;
        }

        cout << endl;
    }

    return 0;
}