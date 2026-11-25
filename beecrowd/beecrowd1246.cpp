#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C,N;
    while(cin>>C>>N){
        vector<int> parking_lot(C,0);
        map<int,int> car_positions; // placa -> posicao
        map<int,int> car_lengths; // placa -> tamanho
        
        int billing = 0;
        for(int i=0;i<N;i++){
            char event_type; int plate;
            cin >> event_type >> plate;

            if(event_type=='C'){
                int length;
                cin >> length;
                
                bool parked = false;
                for(int start_pos=0;start_pos<=C-length;start_pos++){
                    bool space_is_free = true;

                    for(int j=0;j<length;j++){
                        if(parking_lot[start_pos+j]!=0){
                            space_is_free = false;
                            start_pos += j;
                            break;
                        }
                    }

                    if(space_is_free){
                        for(int j=0;j<length;j++) parking_lot[start_pos+j] = plate;
                        car_positions[plate] = start_pos;
                        car_lengths[plate] = length;
                        billing += 10;
                        parked = true;
                        break;
                    }
                }
            }else{ // event_type = 'S'
                if(car_positions.count(plate)){
                    int start_pos = car_positions[plate];
                    int length = car_lengths[plate];

                    for(int j=0;j<length;j++) parking_lot[start_pos+j] = 0;

                    car_positions.erase(plate);
                    car_lengths.erase(plate);
                }
            }
        }
        cout << billing << endl;
    }

    return 0;
}