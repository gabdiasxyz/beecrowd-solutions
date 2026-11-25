#pragma GCC optimize("O3,unroll-loops")
#include <cstdio>

// principio da inclusao-exclusao

#define PI 3.14159265358979323846
#define SQRT_3 1.73205080756887719318

const double C1 = (1.0-SQRT_3+PI/3.0);
const double C2 = (2.0*SQRT_3-4.0+PI/3.0);
const double C3 = (4.0-SQRT_3-(2.0*PI/3.0));

int main(){
    double a;
    while(scanf("%lf",&a)==1){
        double a2 = a*a;

        double area1 = a2*C1;
        double area2 = a2*C2;
        double area3 = a2*C3;

        printf("%.3f %.3f %.3f\n",area1,area2,area3); // muito mais rapido pra formatar
    }

    return 0;
}