#pragma once
#include <vector>

using namespace std;

class data{
	public:
		double beta;			//rychlost nakazeni
		double gamma;			//rychlost uzdraveni
		double r0;				//zakladni reprodukcni cislo
		int N;					//celkovy pocet jedincu (pocet obyvatel CR)
		int T;					//casovy usek ve dnech
		int dt;					//delka kroku je 1 den
		int n;					//pocet opakovani pro vypocet pomoci RK4
		double t0, S0, I0, R0;	//zavedeni promennych pro poc.podm. a napocitane hodnoty	
		void zadatData();		//fce pro zadani parametru
	
		vector<double> t;		//vektory pro ulozeni napocitanych hodnot
		vector<double> S;
		vector<double> I;
		vector<double> R;
		
};
