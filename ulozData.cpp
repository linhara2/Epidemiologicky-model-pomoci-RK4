#include "ulozData.hpp"
#include "data.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int ulozVysledky(data &pocPar){
	
	ofstream mujSoubor("Vysledky.txt");
	
	mujSoubor << "Zakladni reprodukcni cislo bylo zadano: " << pocPar.r0 << endl;
	mujSoubor << "Celkovy pocet jedincu: " << pocPar.N << endl;
	mujSoubor << "---------------------------------------------------------------" << endl;
	mujSoubor << "t - cas ve dnech" << endl;
	mujSoubor << "S - jedinci, kteri nemoc neprodelali a muzou se nakazit" << endl;
	mujSoubor << "I - infekcni jedinci" << endl;
	mujSoubor << "R - uzdraveni/imunni jedinci" << endl;
	mujSoubor << "---------------------------------------------------------------" << endl;
	mujSoubor << "#t \t S \t I \t R" << endl; //hlavicka pro tabulku napocitanych hodnot
		
	for (int i = 0; i <= pocPar.n; i++){
		
		mujSoubor << pocPar.t[i] << "\t" << pocPar.S[i] << "\t" << pocPar.I[i] << "\t" << pocPar.R[i] << endl;
	}
		
	mujSoubor.close();

	return 0;
}

int ulozGraf(data &pocPar){
	ofstream mujGraf("VysledkyGraf.txt");
	
	mujGraf << "#t \t S \t I \t R" << endl; //hlavicka pro tabulku napocitanych hodnot
		
	for (int i = 0; i <= pocPar.n; i++){
		
		mujGraf << pocPar.t[i] << "\t" << pocPar.S[i] << "\t" << pocPar.I[i] << "\t" << pocPar.R[i] << endl;
	}
		
	mujGraf.close();

	return 0;
}
