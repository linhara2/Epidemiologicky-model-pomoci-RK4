#include "data.hpp"
#include "ulozData.hpp"
#include "vypocet.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	data pocPar;
	
	pocPar.zadatData();
		
	vypoctiSIR(pocPar);
	
	ulozVysledky(pocPar);
	
	return 0;
}
