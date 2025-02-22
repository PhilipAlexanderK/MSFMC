#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int analyse()
{


	char buffer[50] = "output/sim.root";
	TChain* Singles = new TChain("Singles");
	TChain* Coincidences = new TChain("Coincidences");

	Singles->Add("output/sim.root");
	Coincidences->Add("output/sim.root");

	int n_singles = Singles->GetEntries();
	int n_coinc = Coincidences->GetEntries();

//
//Declaration of leaves types - TTree Coincidences
//  
   Char_t          comptVolName1[40];
   Char_t          comptVolName2[40];
   Int_t           comptonPhantom1, comptonPhantom2, comptonCrystal1, comptonCrystal2, 
   				   crystalID1, crystalID2, eventID1, eventID2, layerID1, layerID2, moduleID1, 
				   moduleID2, rsectorID1, rsectorID2, runID, sourceID1, sourceID2, submoduleID1, 
				   submoduleID2;

   Float_t         energy1, axialPos, energy2, globalPosX1,globalPosX2, globalPosY1, globalPosY2,
				   globalPosZ1, globalPosZ2, rotationAngle,sinogramS, sinogramTheta, sourcePosX1,
				   sourcePosX2, sourcePosY1, sourcePosY2, sourcePosZ1,sourcePosZ2;

   Double_t         time1, time2;
   
	//   
	//Set branch addresses - TTree Coincicences
	//  
   Coincidences->SetBranchAddress("axialPos",&axialPos);
   Coincidences->SetBranchAddress("comptVolName1",&comptVolName1);
   Coincidences->SetBranchAddress("comptVolName2",&comptVolName2);
   Coincidences->SetBranchAddress("comptonPhantom1",&comptonPhantom1);
   Coincidences->SetBranchAddress("comptonPhantom2",&comptonPhantom2);
   Coincidences->SetBranchAddress("comptonCrystal1",&comptonCrystal1);
   Coincidences->SetBranchAddress("comptonCrystal2",&comptonCrystal2);
   Coincidences->SetBranchAddress("crystalID1",&crystalID1);
   Coincidences->SetBranchAddress("crystalID2",&crystalID2);
   Coincidences->SetBranchAddress("energy1",&energy1);
   Coincidences->SetBranchAddress("energy2",&energy2);   
   Coincidences->SetBranchAddress("eventID1",&eventID1);
   Coincidences->SetBranchAddress("eventID2",&eventID2);
   Coincidences->SetBranchAddress("globalPosX1",&globalPosX1);
   Coincidences->SetBranchAddress("globalPosX2",&globalPosX2);
   Coincidences->SetBranchAddress("globalPosY1",&globalPosY1);
   Coincidences->SetBranchAddress("globalPosY2",&globalPosY2);      
   Coincidences->SetBranchAddress("globalPosZ1",&globalPosZ1);
   Coincidences->SetBranchAddress("globalPosZ2",&globalPosZ2);
   Coincidences->SetBranchAddress("layerID1",&layerID1);
   Coincidences->SetBranchAddress("layerID2",&layerID2);
   Coincidences->SetBranchAddress("moduleID1",&moduleID1);
   Coincidences->SetBranchAddress("moduleID2",&moduleID2);
   Coincidences->SetBranchAddress("rotationAngle",&rotationAngle);
   Coincidences->SetBranchAddress("rsectorID1",&rsectorID1);
   Coincidences->SetBranchAddress("rsectorID2",&rsectorID2);
   Coincidences->SetBranchAddress("runID",&runID);
   Coincidences->SetBranchAddress("sinogramS",&sinogramS);
   Coincidences->SetBranchAddress("sinogramTheta",&sinogramTheta);
   Coincidences->SetBranchAddress("sourceID1",&sourceID1);
   Coincidences->SetBranchAddress("sourceID2",&sourceID2);
   Coincidences->SetBranchAddress("sourcePosX1",&sourcePosX1);
   Coincidences->SetBranchAddress("sourcePosX2",&sourcePosX2);
   Coincidences->SetBranchAddress("sourcePosY1",&sourcePosY1);
   Coincidences->SetBranchAddress("sourcePosY2",&sourcePosY2);
   Coincidences->SetBranchAddress("sourcePosZ1",&sourcePosZ1);
   Coincidences->SetBranchAddress("sourcePosZ2",&sourcePosZ2);
   Coincidences->SetBranchAddress("submoduleID1",&submoduleID1);
   Coincidences->SetBranchAddress("submoduleID2",&submoduleID2);
   Coincidences->SetBranchAddress("time1",&time1);
   Coincidences->SetBranchAddress("time2",&time2);


	printf("Number of single events detected: %i.\n", n_singles); 
	printf("Number of coincidences: %i.\n", n_coinc);

	TH1F *ene = new TH1F("gamma1","",80,0.2,.8);  
//	TH3F *position = new TH3F("position","",200,-400,400,200,-400,400,200,-400,400);  
	TH2F *position = new TH2F("position","",200,-200,200,200,-200,200);  

	int nscat = 0;
	int nrand = 0;
	int ntrue = 0;

	for (int i = 0; i < n_coinc; i++)
	{
		Coincidences->GetEntry(i);

		ene->Fill(energy1);
		//position->Fill(sourcePosZ1,sourcePosX1,sourcePosY1);
		position->Fill(sourcePosX1,sourcePosY1);

		if (eventID1 != eventID2)
			nrand++;
		else if (comptonPhantom1 == 0 && comptonPhantom2 == 0)
			ntrue++;
		else
			nscat++;

	}

	printf("---Coincidences---\n");
	printf("True coincidences: %i\n", ntrue);
	printf("Random coincidences: %i\n", nrand);
	printf("Scattered coincidences: %i\n", nscat);
	printf("-------------------\n");


	gStyle->SetPalette(1);
   
   
   	TCanvas* c1 = new TCanvas("Reco","Reco",200,10,500,600);
   	c1->SetFillColor(0);
   	c1->SetBorderMode(0);   

	ene->Draw();
    ene->SetFillColor(2);

	c1->Update();

	TCanvas* c2 = new TCanvas("Reco_true","Reco_true",200,10,500,600);
	c2->SetFillColor(0);
	c2->SetGrid();
	c2->SetBorderMode(0); 

	position->Draw();
	
	c2->Update(); 

	return 0;

}

