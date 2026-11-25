#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    while(cin>>input){
        if(input[0]=='-') break;

        unsigned int number;

        stringstream ss;
        ss << input;
        if(input.rfind("0x",0)==0){
            // input is hex
            ss >> hex >> number;
            cout << dec << number << '\n';
        }else{
            // input is dec
            ss >> dec >> number;
            cout << "0x" << hex << uppercase << number << '\n';
        }
    }
    
    return 0;
}