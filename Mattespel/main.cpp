/*
 * main.cpp
 *
 *  Created on: 14. jan. 2013
 *      Author: eirik
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


//Definer funksjonane
int multiplikasjon();
int lagre_poengsum(int poengsum);

int main(int argc, char *argv[])
{


	std::cout << "Velkomen til Mattespel v1.0" << std::endl;

	lagre_poengsum(multiplikasjon());

	return 0;
}

int multiplikasjon()
{
	int poengsum = 0;

	srand((unsigned)time(0));


	for(int i = 0; i < 2; i++)
	{
		int tilfeldig1 = (rand()%99) + 1;
		int tilfeldig2 = (rand()%99) + 1;
		int svar = 0;

		int fasit = tilfeldig1*tilfeldig2;

		std::cout << tilfeldig1 << " * " << tilfeldig2 << " = ";
		std::cin >> svar;

		if(fasit == svar)
		{
			std::cout << "Riktig!!!" << std::endl;
			poengsum++;
		}
		else
		{
			std::cout << "Feil!!!" << std::endl;
			std::cout << "Riktig svar er: " << fasit << std::endl;
		}
	}

	return poengsum;
}

int lagre_poengsum(int poengsum)
{
	char namn[] = "";

	std::cout << "Gratulera du fekk: " << poengsum << " poeng." << std::endl;
	std::cout << "Skriv namnet ditt: ";
	std::cin >> namn;

	std::ofstream poengfil;

	poengfil.open("poengsum.txt", std::ios::app);
	poengfil << "Namn: " << namn << ", poengsum: " << poengsum << std::endl;
	poengfil.close();

	return 0;
}
