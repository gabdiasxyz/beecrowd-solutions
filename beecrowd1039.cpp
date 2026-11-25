#include "bits/stdc++.h"
using namespace std;

int main(){
    double r1,x1,y1,r2,x2,y2;
    while(cin>>r1>>x1>>y1>>r2>>x2>>y2){
        
        double dist_centers = hypot(x1-x2,y1-y2);

        if (dist_centers + r2 <= r1) cout << "RICO\n";
        else std::cout << "MORTO\n";
    }

    return 0;
}