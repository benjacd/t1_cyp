#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;
/*
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
*/
int encontrar_gra(char *argv[])
{
    int gra = 0;
    for (int i=0 ; argv[1][i] != '\0'; i++)
    {
        if(argv[1][i] == 'x')  //Encuentra la primera x
        {
            if(argv[1][i+1] == '*')  //Verifica si hay algun asterisco
            {
                gra = argv[1][i+3] - '0'; // Guarda el grado
                return gra; //retorta el grado
            }
            return gra=1; // Si no encuentra asterisco el grado es 1
        }
    }
    return gra; //Si no encuentra nada grado = 0
}
void vect_pol(char *argv[], int gra)
{
    int n = gra + 1;
    int pos = 0, coef = 1, signo = 1 ; //inicializa la pos y el coef
    float v[n];
    for (int i = 0; i<n; i++)
    {v[i]=0;} //Coloca 0 en todo el arreglo

    for (int i=0 ; argv[1][i] != '\0'; i++) //recorre el strig
    {
        if(argv[1][i] == 'x') //Encuentra la primera x
        {
            if(argv[1][i+1] == '*')  //Verifica si hay algun asterisco
            {
               pos = argv[1][i+3] - '0' ; // Convierte la posicion del coeficiente}
               if (pos == gra) //Verifica un menos en la primera iteracion jejej
               {
                  if(argv[1][i-2] == '-') // Verifica si es menos
                    {signo = signo * -1;}
               }
               else if(argv[1][i-3] == '-') // Verifica si es menos
               {signo = signo * -1;}   // SI es menos multiplica por -1
               coef = argv[1][i-1] - '0'; // Convierte el coeficiente
               coef = coef * signo;
               v[pos] = coef; // COloca el coef en la pos
               signo = 1;  // Vuelve el signo a ser +
            }
            else // Caso que no haya exp
            {
                if(argv[1][i-3] == '-') // Verifica si es menos
                {signo = signo * -1;}
                coef = argv[1][i-1] - '0';
                coef = coef * signo;
                v[1] = coef; // Coloca el coef en la pos
                signo = 1;
            }
        }
        else // Si no encuentra la x
        { 

            if(argv[1][i] == '+' || argv[1][i] == '-')
            {
               if(argv[1][i] == '-') // Verifica si es menos
               {signo = signo * -1;}   // SI es menos multiplica por -1 
               coef = argv[1][i+2] - '0';
               coef = coef * signo;
               if(coef == -72){coef = 0;}
               v[0] = coef; // COloca el coef en la pos 
               signo = 1;  // Vuelve el signo a ser +
            }
        } 
    }
    for (int i = 0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(int argc,char *argv[]) //SI EL COEF ES 1 SE DEBE INGRESAR
{
     //cout <<argv[1][0]<<endl;
     //int gra = argv[1][0] - '0';    //CONVIERTE EL CHAR A ENTERO JEJ
    int gra = encontrar_gra(argv);
    //cout <<gra<<endl;
    vect_pol(argv,gra);
    cout<<"TRISTE"<<endl;
    //newtonRaphson();
    return 0;
}