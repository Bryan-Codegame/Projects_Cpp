#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
#include <string>
#include <locale.h>
#include <vector>
using namespace std;

int main() {

    /*
    rangoMenor: el numero mas bajo desde donde quieres empezar a buscar el primo
    rangoMayor: el numero mas alto hasta donde quieres empezar a buscar el primo
    divisor: el numero con el cual vamos a dividir para saber si es o no numero primo
    primo: vector donde se guardan los numeros primos
    residuo: guarda el residuo de dividir el rangoMenor con el divisor
    x: contador para el vector "primo"
    esPrimo = booleano para saber si el numero en el que acutalmente estamos es primo o no
    */
    int rangoMenor, rangoMayor, divisor, residuo, x = 0;
    vector<int> primo;
    bool esPrimo = false;

    cout << "Rango Menor: " << endl;
    cin >> rangoMenor;
    cout << "Rango Mayor: " << endl;
    cin >> rangoMayor;

    //Repite el ciclo mientras rangoMenor sea menor o igual a rangoMayor
    for (rangoMenor; rangoMenor <= rangoMayor; rangoMenor++)
    {
        //Repite el ciclo desde 2 mientras que divisor sea menor o igual a 9
        for (divisor = 2; divisor <= 9; divisor++)
        {
            //Evitamos dividir numeros iguales
            if (divisor != rangoMenor)
            {
                residuo = rangoMenor % divisor;//%=obtiene el residuo de la fraccion
                //Comprobacion de que esta dividiendo
                //cout<<rangoMenor<<" / "<<divisor<<" = "<<residuo<<endl;
            }

            //Comprobamos si el residuo es igual a 0 o el numero que estamos dividiendo es 1
            if (residuo == 0 or rangoMenor == 1)
            {
                //En caso de que su residuo sea 0 (eso hace que no sea primo), hace falso esPrimo y termina el ciclo for
                esPrimo = false;
                break;
            }
            else
            {
                //En caso que su residuo sea diferente de 0 hace la variable esPrimo verdadera
                esPrimo = true;
            }

        }

        //Comprobamos si el numero actual esPrimo
        if (esPrimo)
        {
            //En caso de serlo lo agregamos al vector "primo" y aumentamos el contador(x)
            primo.push_back(rangoMenor);
            x++;
        }

    }

    //Repite el ciclo mientras x sea menor que el tamaño del vector primo
    for (x = 0; x < primo.size(); x++)//primo.size()=obtiene el tamaño del vector primo
    {
        cout << primo[x] << endl;
    }


	return 0;
}