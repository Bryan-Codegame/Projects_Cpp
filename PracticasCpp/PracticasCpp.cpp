// PracticasCpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <cstdlib>;
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".UTF8");

	srand(time(NULL));

	int randomNumber = rand();
	int guessComputer = (randomNumber % 100) + 1;
	int tries = 0;
	int currentHighNum = 100;
	int currentLowNum = 1;

	string th = "muy alto";
	string tl = "muy bajo";
	string yw = "Ganaste";

	string clue;
	string ready;
	bool youWin = false;

	cout << "\nBienvenido, antes de empezar piensa en un número entre 1 y 100";
	cout << "\n¿Estás listo? (si/no)";
	getline(cin, ready);

	if (ready == "si")
	{
		do
		{
			tries++;

			cout << "\nRandom: " << randomNumber << endl;

			cout << "\nTu número es: " << guessComputer << "?" << endl;
			cout << "Dame una pista, muy alto, muy bajo o ganaste: ";
			getline(cin, clue);

			if (clue == th)
			{
				currentHighNum = guessComputer - 1;
			}
			else if(clue == tl) 
			{
				currentLowNum = guessComputer + 1;
			}
			else if (clue == yw)
			{
				youWin = true;
				break;
			}
			else
			{
				cout << "\nPista inválida";
				tries--;
			}

			//Depuración
			cout << "\n------------------------" << endl;
			cout << "\nMas alto: " << currentHighNum << endl;
			cout << "\nMas bajo: " << currentLowNum << endl;
			cout << "\n------------------------" << endl;


			if (currentHighNum != currentLowNum)
			{
				guessComputer = (randomNumber % (currentHighNum - currentLowNum));
				guessComputer = currentHighNum - guessComputer;
			}
			else
			{
				guessComputer = currentHighNum;
				youWin = true;
				break;
			}
			

		} while (!youWin);

		cout << "Gané, tu número es " << guessComputer << endl;
		cout << "!!He adivinado en " << tries << " intentos!!\n\n" << endl;
	}
	else
	{
		cout << "\nVuelve pronto!!";
	}
}
