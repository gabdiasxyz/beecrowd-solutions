#include <iostream>
using namespace std;

int survivor(int n,int k){
    if(n==1)  return 0;
    return (survivor(n-1,k)+k)%n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int NC,n,k;

    cin >> NC;

    for(int i=1;i<=NC;i++){
        cin >> n >> k;
        cout << "Case " << i << ": " << survivor(n,k)+1 << endl;
    }

    return 0;
}