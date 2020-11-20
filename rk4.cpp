#include <iostream>
#include <cmath>
#include <fstream>

//definovani soustavy ODR modelu SIR s konst.incidenci
#define f(S,I) (-(beta*S*I)/N)
#define g(S,I) (((beta*S*I)/N) - gamma*I)
//define h(I) gamma*I

//f = dSdt, g = dIdt, h = dRdt

using namespace std;

int main(){

double beta = 0.4;		//rychlost nakazeni
double gamma = 0.04;	//rychlost uzdraveni
double r0 = beta/gamma;	//zakladni reprodukcni cislo
int N = 10690000;		//celkovy pocet jedincu (pocet obyvatel CR)
int T = 360;			//casovy usek ve dnech
int dt = 1;				//delka kroku je 1 den

int n=T/dt;				//pocet opakovani pro vypocet pomoci RK4
double t0, S0, I0, R0;	//zavedeni promennych pro poc.podm. a napocitane hodnoty

//zadani pocatecnich podminek
S0 = 10689980.0;
I0 = 20.0;
R0 = 0.0;
t0 = 0.0;

ofstream mujsoubor("data.txt"); //zacatek zapisu do souboru txt.
mujsoubor << "Zakladni reprodukcni cislo bylo zadano: " << r0 << endl;
mujsoubor << "Celkovy pocet jedincu: " << N << endl;
mujsoubor << "---------------------------------------------------------------" << endl;
mujsoubor << "t - cas ve dnech" << endl;
mujsoubor << "S - jedinci, kteri nemoc neprodelali a muzou se nakazit" << endl;
mujsoubor << "I - infekcni jedinci" << endl;
mujsoubor << "R - uzdraveni/imunni jedinci" << endl;
mujsoubor << "---------------------------------------------------------------" << endl;
mujsoubor << "#t \t S \t I \t R" << endl; //hlavicka pro tabulku napocitanych hodnot
mujsoubor << t0 << "\t" << S0 << "\t" << I0 << "\t" << R0 << endl;

//RK4 a zapis hodnot do souboru txt
double t, S, I, R, k1, k2, k3, k4, l1, l2, l3, l4, k, l;
for (int i = 0; i < n; i++){
	t = t0 + dt;
	k1 = f(S0, I0);
	l1 = g(S0, I0);
	k2 = f((S0 + (dt*k1/2)), (I0 + (dt*l1/2)));
	l2 = g((S0 + (dt*k1/2)), (I0 + (dt*l1/2)));
	k3 = f((S0 + (dt*k2/2)), (I0 + (dt*l2/2)));
	l3 = g((S0 + (dt*k2/2)), (I0 + (dt*l2/2)));
	k4 = f((S0 + dt*k3), (I0 + dt*l3));
	l4 = g((S0 + dt*k3), (I0 + dt*l3));
	k = dt*(k1+2*k2+2*k3+k4)/6;
	l = dt*(l1+2*l2+2*l3+l4)/6;
	S = S0 + k;
	I = I0 + l;
	R = N-S-I; //neni nutne pocitat hodnoty R pomoci RK4, protoze N = konst. = S(t) + I(t) + R(t)
	
	mujsoubor << t << "\t" << S << "\t" << I << "\t" << R << endl;
	
	//prepis promennych pro opakovani cyklu
	t0 = t;
	S0 = S;
	I0 = I;
}

mujsoubor.close(); //konec zapisu do souboru

return 0;
}
