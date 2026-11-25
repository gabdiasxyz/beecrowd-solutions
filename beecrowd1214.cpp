#include <cstdio>
#include <cctype>
using namespace std;

char buffer[8*1024*1024]; // buffer de 8mb
char* ptr = buffer;

inline int read_int(){
    int num = 0;
    while(!isdigit(*ptr)) ptr++; // pula nao numericos
    while(isdigit(*ptr)){ // construindo o numero
        num = num*10+(*ptr-'0');
        ptr++;
    }
    return num;
}

int main(){
    fread(buffer,1,sizeof(buffer),stdin);

    int C = read_int();

    while(C--){
        int N = read_int();

        int grades[1001]; // no enunciado fala 0 <= N <= 1000
        double sum = 0.0;

        for(int i=0;i<N;i++){
            grades[i] = read_int();
            sum += grades[i];
        }

        double avg = sum/N;

        int above_avg = 0;
        for(int i=0;i<N;i++){
            if(grades[i]>avg) above_avg++;
        }

        double perc = (double)above_avg/(double)N * 100.0;
        printf("%.3f%%\n",perc);
    }
    
    return 0;
}