#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double [],int ,double []);



int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
       


    return 0;
}


void stat(const double A[],int N,double B[]){
    double H_Mean = 0.0 ,SD=0.0,sum=0.;
    double Max = A[0],  Min = A[0], GM = A[0];
    for (int i = 0 ; i < N ; i++ ){
        sum += A[i];
        H_Mean += 1/A[i];
        if (i < N-1 ) GM = GM*A[i+1];
        if (Max < A[i])Max = A[i];
        if (Min > A[i])Min = A[i];
    }
    B[0] = sum/N ;  //Arithmetic Mean
    for (int i = 0 ; i < N ; i++ ){
        SD += pow(A[i]-B[0],2);
    }
    
    B[1] = sqrt(SD/N); //Standard deviation
    B[2] = pow(GM,1.0/N);   //GM
    B[3] = N/H_Mean ;
    B[4] = Max ;
    B[5] = Min ;
}

