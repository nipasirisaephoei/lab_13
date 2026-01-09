#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);
void stat(const double data[], int n, double result[]) {
    double sum = 0.0;
    double geoProduct = 1.0;
    double harmSum = 0.0;

    double maxVal = data[0];
    double minVal = data[0];

    for (int i = 0; i < n; i++) {
        sum += data[i];
        geoProduct *= data[i];
        harmSum += 1.0 / data[i];

        if (data[i] > maxVal) maxVal = data[i];
        if (data[i] < minVal) minVal = data[i];
    }

    double mean = sum / n;

    double sd = 0.0;
    for (int i = 0; i < n; i++) {
        sd += pow(data[i] - mean, 2);
    }
    sd = sqrt(sd / n);

    double geoMean = pow(geoProduct, 1.0 / n);
    double harmMean = n / harmSum;

    result[0] = mean;
    result[1] = sd;
    result[2] = geoMean;
    result[3] = harmMean;
    result[4] = maxVal;
    result[5] = minVal;
}
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
