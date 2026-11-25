#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    double total = 0, distance; int count = 0;

    while(getline(cin,name)){
        cin >> distance;

        total += distance;
        count++;

        // qnd lemos com >>, o \n fica no input buffer
        // a gente tem que ignorar ele pq se nao a proxima call do getline vai ler uma linha vazia
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }

    double avg = total/(double)max(count,1);
    cout << fixed << setprecision(1) << avg << endl;

    return 0;
}