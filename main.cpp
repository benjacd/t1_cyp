#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
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
string removeSpaces(const string& s) {  //METODO QUE REMUEVE ESPACIOS EN BLANCOS
    string tmp(s);
    tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
    return tmp;
}
void vect_pol(char *argv[], int gra)
{
    int n = gra + 1,k=0;;
    int pos = 0, pos_aux = 0; float coef = 0; //inicializa la pos y el coef
    float v[n];
    for (int i = 0; i<n; i++)
    {v[i]=0;} //Coloca 0 en todo el arreglo
    for (int i=0 ; argv[1][i] != '\0'; i++) //recorre todo
    {
        if(argv[1][i] == 'x') //Encuentra la primera x
        {
            string str,str_aux;
            while(pos_aux<=i-1)  //INGRESA A UN STRING LOS CHAR
            {
             str.append(1, argv[1][pos_aux]);
             pos_aux++;
            }
            str_aux = removeSpaces(str);
            coef = std::stof(str_aux);  //Convierte el string en un flotante con signo y to ja
            if(argv[1][i+1] == '*')  //Verifica si hay algun asterisco
            {
                pos = argv[1][i+3] - '0' ; // Convierte la posicion del coeficiente}
                pos_aux= i+5;
            }
            else
            {
                pos = 1;
                pos_aux= i+1;
            }
        }
        v[pos] = coef;
        k = pos_aux;
    }
    /*  //FAlTA ARREGLAR ESTO
    if (argv[1][k] != '\0')
        {
            pos = 0;
            string str,str_aux;
            while(argv[1][k] != '+' || argv[1][k] != '-' || argv[1][k] == '\0'){ k++; }
            if(argv[1][k] != '\0')
            {
            while(argv[1][k] != '\0')  //INGRESA A UN STRING LOS CHAR
            {
             str.append(1, argv[1][k]);
             k++;
            }
            str_aux = removeSpaces(str);
            coef = std::stof(str_aux);  //Convierte el string en un flotante con signo y to ja
            v[pos] = coef;
            }
        }
        */
    
    for (int i = 0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<endl;
}
int main(int argc,char *argv[]) //SI EL COEF ES 1 SE DEBE INGRESAR
{
    int gra = encontrar_gra(argv);
     vect_pol(argv,gra);
    return 0;
}