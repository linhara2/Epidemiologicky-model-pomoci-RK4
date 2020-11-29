#pragma once

#include "data.hpp"
#include <cmath>

#define f(S,I) (-(pocPar.beta*S*I)/pocPar.N)
#define g(S,I) (((pocPar.beta*S*I)/pocPar.N) - pocPar.gamma*I)

using namespace std;

int vypoctiSIR(data &pocPar){
	double k1, k2, k3, k4, l1, l2, l3, l4, k, l;
		pocPar.t[0] = pocPar.t0;
		pocPar.S[0] = pocPar.S0;
		pocPar.I[0] = pocPar.I0;
		pocPar.R[0] = pocPar.R0;
	for (int i = 1; i <= pocPar.n; i++){
		pocPar.t[i] = pocPar.t0 + pocPar.dt;
		k1 = f(pocPar.S0, pocPar.I0);
		l1 = g(pocPar.S0, pocPar.I0);
		k2 = f((pocPar.S0 + (pocPar.dt*k1/2)), (pocPar.I0 + (pocPar.dt*l1/2)));
		l2 = g((pocPar.S0 + (pocPar.dt*k1/2)), (pocPar.I0 + (pocPar.dt*l1/2)));
		k3 = f((pocPar.S0 + (pocPar.dt*k2/2)), (pocPar.I0 + (pocPar.dt*l2/2)));
		l3 = g((pocPar.S0 + (pocPar.dt*k2/2)), (pocPar.I0 + (pocPar.dt*l2/2)));
		k4 = f((pocPar.S0 + pocPar.dt*k3), (pocPar.I0 + pocPar.dt*l3));
		l4 = g((pocPar.S0 + pocPar.dt*k3), (pocPar.I0 + pocPar.dt*l3));
		k = pocPar.dt*(k1+2*k2+2*k3+k4)/6;
		l = pocPar.dt*(l1+2*l2+2*l3+l4)/6;
		pocPar.S[i] = pocPar.S0 + k;
		pocPar.I[i] = pocPar.I0 + l;
		pocPar.R[i] = pocPar.N-pocPar.S[i]-pocPar.I[i]; //neni nutne pocitat hodnoty R pomoci RK4, protoze N = konst. = S(t) + I(t) + R(t)
		
		//prepis promennych pro opakovani cyklu
		pocPar.t0 = pocPar.t[i];
		pocPar.S0 = pocPar.S[i];
		pocPar.I0 = pocPar.I[i];
	}
}
