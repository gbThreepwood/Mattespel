/*********************************************
 * vim:sw=8:ts=8:si:et
 * To use the above modeline in vim you must have "set modeline" in your .vimrc
 *
 * main.cpp
 *
 *  Created on: 14. jan. 2013
 *
 * Author: Eirik
 *
 * Copyright:GPL V3
 * See http://www.gnu.org/licenses/gpl.html
 *
 * Eit enkelt mattespel for å demonstrera C++.
 *********************************************/

// Standard C++ bibliotek
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

// Gettext, for omsetjing
#include <libintl.h>
#include <locale>

// Ncurses, for litt meir fancy grafikk.
#include <ncurses.h>
#include <menu.h>

#include "main.h"



int main(int argc, char *argv[])
{
	if ( argc != 2 ) // argc må vera 2
		std::cout <<"usage: "<< argv[0] <<" <ant oppg>\n";

	// Set opp gettext
	setlocale( LC_ALL, "" );
	bindtextdomain( "hello", "/usr/share/locale" );
	textdomain( "hello" );

	// gjeldande tid og dato, basert på systemtid.
	time_t now = time(0);

	// konverter til streng
	char* dt = ctime(&now);

	std::cout << _("Welcome to Mattespel v1.0") << std::endl;
	std::cout << "Lokal tid: " << dt << std::endl;

	// Storleiken til forskjellige variabeltypar
	std::cout << "Short: " << sizeof(short) << std::endl;
	std::cout << "Int: " << sizeof(int) << std::endl;
	std::cout << "Long: " << sizeof(long) << std::endl;
	std::cout << "Char: " << sizeof(char) << std::endl;

	// Multiplikasjon
	lagre_poengsum(tilfeldigOppg(4));

	return 0;
}

int tilfeldigOppg(int ant_oppg)
{
	int poengsum = 0;
	int svar = 0;
	int fasit = 0;
	int tilfeldig1 = 0;
	int tilfeldig2 = 0;
	enum regneart {multiplikasjon, divisjon, subtraksjon, addisjon, last};

	// Initialiser tilfeldighetsgeneratoren basert på klokka.
	srand((unsigned)time(0));

	for(int i = 0; i < ant_oppg; i++)
	{
		// Generer tilfeldige tal
		tilfeldig1 = (rand()%9) + 1;
		tilfeldig2 = (rand()%9) + 1;

		//Velg ein tilfeldig regneart
		regneart oppgType = static_cast<regneart>(rand()%last);

		if (oppgType == multiplikasjon)
		{
			fasit = tilfeldig1*tilfeldig2;
			std::cout << tilfeldig1 << " * " << tilfeldig2 << " = ";
		}
		else if (oppgType == divisjon)
		{
			fasit = tilfeldig1/tilfeldig2;
			std::cout << tilfeldig1 << " / " << tilfeldig2 << " = ";
		}
		else if (oppgType == subtraksjon)
		{
			fasit = tilfeldig1-tilfeldig2;
			std::cout << tilfeldig1 << " - " << tilfeldig2 << " = ";
		}
		else
		{
			fasit = tilfeldig1+tilfeldig2;
			std::cout << tilfeldig1 << " + " << tilfeldig2 << " = ";
		}

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
	//char namn[] = "";
	std::string namn = "";

	std::cout << "Gratulera du fekk: " << poengsum << " poeng." << std::endl;
	std::cout << "Skriv namnet ditt: ";
	std::getline(std::cin, namn);
	std::cout << std::endl << "Lagrer poengsum . . .";

	std::ofstream poengfil;

	poengfil.open("poengsum.txt", std::ios::app);
	poengfil << "Namn: " << namn << ", poengsum: " << poengsum << std::endl;
	poengfil.close();

	return 0;
}
