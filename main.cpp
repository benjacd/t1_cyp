#include <iostream>
#include <math.h>
#include <string>
using namespace std;
double inputPolynomial(double coeff[], double n, double x)
{
    double fx = 0.0;
    for (int i = n; i >= 0; i--)
    {
        double temp = coeff[i];
        if (i == 0)
            fx = fx + temp;
        else
            fx = fx + (pow(x, i) * temp);
    }
    return fx;
}
double getDerivative(double coeff[], double n, double x, double vfx)
{
    double dfx = 0;
    for (int i = n; i >= 0; i--)
    {
        double temp = coeff[i];
        if (i == 1)
        {
            dfx = dfx + temp;
            return dfx;
        }
        else
            dfx = dfx + (pow(x, i - 1) * temp * i);
    }
}
void newtonRaphson()
{
    int n;
    cout << "Enter the highest degree of the polynomial : ";
    cin >> n;
    double coeff[n + 1];
    for (int i = n; i >= 0; i--)
    {
        double temp;
        cout << "Enter the coefficient of " << i << " degree : ";
        cin >> coeff[i];
    }
    double x;
    cout << "Enter the initial assumed value of x : ";
    cin >> x;
    while (true)
    {
        double fx = inputPolynomial(coeff, n, x);
        double dfx = getDerivative(coeff, n, x, fx);
        double h = fx / dfx;
        if (abs(h) < 0.00001)
            break;
        x = x - h;
    }
    cout << "\nThe value of the root is " << x << endl;
}
int main(int argc,char *argv[])
{
    for (int i=1; i<argc;i++)
    {
     cout <<argv[i]<<endl;
    }
    
    newtonRaphson();
    return 0;
}