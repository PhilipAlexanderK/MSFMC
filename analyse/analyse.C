#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int analyse()
{


	char buffer[50] = "output/sim.root";
	TChain* Sing = new TChain("Singles");
	TChain* Coinc = new TChain("Coincidences");

	Sing->Add("output/sim.root");
	Coinc->Add("output/sim.root");

	int n_singles = Sing->GetEntries();
	int n_coinc = Coinc->GetEntries();

	printf("Number of single events detected: %i.\n", n_singles); 
	printf("Number of coincidences: %i.\n", n_coinc);
	return 0;

}

