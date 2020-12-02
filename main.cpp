#include "data.hpp"
#include "ulozData.hpp"
#include "vypocet.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	data pocPar;
	
	pocPar.zadatData();
		
	vypoctiSIR(pocPar);
	
	ulozVysledky(pocPar);
	
	bool g;
	cout << "Chcete vygenerovat soubor pro vytvoreni grafu v Maple? (bez hlavicky) (1/0)" << endl;
	cin >> g;
	
	if (g==1){
	ulozGraf(pocPar);
	}
	
	return 0;
}
