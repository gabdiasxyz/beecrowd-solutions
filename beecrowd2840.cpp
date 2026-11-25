#include <bits/stdc++.h>
using namespace std;

const double pi = 3.1415;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double R,L;
    cin >> R >> L;

    double volume_balloon = (4.0/3.0)*pi*R*R*R;

    int filled = static_cast<int>(L/volume_balloon);

    cout << filled << endl;

    return 0;
}