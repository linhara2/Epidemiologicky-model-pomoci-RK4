#include <iostream>
#include "data.hpp"

using namespace std;

void data::zadatData(){
	cout << "Zadej rychlost nakazeni\n";
	cin >> beta;
	cout << "Zadej rychlost uzdraveni\n";
	cin >> gamma;
	cout << "Zadej celkovy pocet jedincu\n";
	cin >> N;
	cout << "Zadej pocatecni pocet nakazenych\n";
	cin >> I0;
	cout << "Zadej casovy usek ve dnech\n";
	cin >> T;
	cout << "Zadej delku kroku ve dnech\n";
	cin >> dt;
	
	R0 = 0.0;
	S0 = N - I0 - R0;
	t0 = 0.0;
	r0 = beta / gamma;
	n = T/dt;
	
	t.resize(n+1);
	S.resize(n+1);
	I.resize(n+1);
	R.resize(n+1);
}
