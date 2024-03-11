typedef std::basic_string < char, std::char_traits < char >, std::allocator < char >> MojString;


TString names[100] = {"empty",
           "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", 
           "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", 
           "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
           "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", 
           "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", 
           "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", 
           "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", 
           "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", 
           "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", 
           "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es"};

Int_t lightisotop[100] = {0, 1, 3, 3, 5, 6, 8, 10, 11, 13, 15, 17, 19, 21, 22, 24, 26, 28, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 48, 52, 54, 56, 58, 60, 63, 65, 67, 71, 73, 75, 77, 79, 81, 83, 85, 88, 90, 92, 94, 96, 99, 102, 104, 106, 108, 111, 113, 116, 119, 121, 124, 126, 128, 130, 133, 135, 138, 140, 142, 144, 148, 150, 153, 155, 157, 159, 161, 163, 165, 168, 170, 176, 178, 184, 186, 191, 193, 197, 201, 205, 208, 211, 215, 219, 221, 223, 231, 233, 237, 239};
Int_t heavyisotop[100] = {0, 7, 10, 13, 16, 21, 23, 25, 28, 31, 34, 39, 41, 43, 45, 47, 49, 52, 54, 59, 61, 63, 65, 67, 70, 73, 76, 78, 82, 84, 86, 88, 90, 92, 95, 98, 101, 104, 107, 109, 113, 116, 119, 122, 125, 128, 131, 133, 135, 137, 140, 142, 145, 147, 150, 152, 154, 157, 159, 161, 163, 165, 168, 170, 172, 174, 176, 178, 180, 182, 185, 188, 190, 194, 197, 199, 203, 205, 208, 210, 216, 218, 220, 224, 227, 229, 231, 233, 235, 237, 239, 241, 243, 245, 247, 249, 252, 254, 256, 258};


void density()
{
	//////////////////////////////////////////////////////////////////////////
	TH1D *f_AZ=new TH1D("f_AZ", "f_AZ", 260, 0, 260);
	TH1D *f_NZ=new TH1D("f_NZ", "f_NZ", 160, 0, 160);
	TH1D *f_ZZ=new TH1D("f_ZZ", "f_ZZ", 110, 0, 110);

	TH1D *f_AA=new TH1D("f_AA", "f_AA", 260, 0, 260);
	TH1D *f_NA=new TH1D("f_NA", "f_NA", 160, 0, 160);
	TH1D *f_ZA=new TH1D("f_ZA", "f_ZA", 110, 0, 110);

	TH1D *f_AN=new TH1D("f_AN", "f_AN", 260, 0, 260);
	TH1D *f_NN=new TH1D("f_NN", "f_NN", 160, 0, 160);
	TH1D *f_ZN=new TH1D("f_ZN", "f_ZN", 110, 0, 110);

	TH2D *f_ZN_N=new TH2D("f_ZN_N", "f_ZN_N", 110, 0, 110, 160, 0 , 160);
  TH2D *f_ZN_Z=new TH2D("f_ZN_Z", "f_ZN_Z", 110, 0, 110, 160, 0 , 160);
  TH2D *f_ZN_A=new TH2D("f_ZN_A", "f_ZN_A", 110, 0, 110, 160, 0 , 160);

	for(int ZZ=1; ZZ<100; ZZ++)
	{
		for(int AA=lightisotop[ZZ]; AA<=heavyisotop[ZZ]; AA++)
		{
			stringstream tmpname;
			tmpname <<"../from_the_target/target"<<names[ZZ]<<AA<<".root";
			string tmp_name = tmpname.str();
			const char *name =(char*) tmp_name.c_str();	
			TFile *file;
			cout<<"Reading File : "<<name<<endl;
			cout<<endl;
			file = TFile::Open(name);
			if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl;} //precaution
			else {
				cout <<"OK"<<endl;
				TH2D * hist;
				hist = (TH2D*)file->Get("N:Z")->Clone();
				int NN = AA-ZZ;
				int f1 = hist->GetBinContent(NN, ZZ-1);
				f_ZZ->Fill(ZZ, f1);
				f_AZ->Fill(AA, f1);
				f_NZ->Fill(NN, f1);

				int f2 = hist->GetBinContent(NN-1, ZZ);
				f_NN->Fill(NN, f2);
				f_AN->Fill(AA, f2);
				f_ZN->Fill(ZZ, f2);

				f_AA->Fill(AA, f1+f2);
				f_ZA->Fill(ZZ, f1+f2);
				f_NA->Fill(NN, f1+f2);

				//if(f!=0)
				//	cout<<N <<" : "<< f<<endl;
			}
		}
	}

	stringstream tmpname1;
	tmpname1<<"DensityZ_Z-1.root";

	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(11);
	c->SetLogz();
	c->SetGrid();
	f_ZZ->GetXaxis()->SetTitle("Z");
	f_ZZ->GetYaxis()->SetTitle("f (Z-1)");
	c->SetLogy();
	f_ZZ->GetXaxis()->SetNdivisions(150); 

	f_ZZ->SetMarkerColor(2);
	f_ZZ->SetMarkerSize(1.5);
	f_ZZ->SetMarkerStyle(20);
	f_ZA->SetMarkerColor(6);
  f_ZA->SetMarkerSize(1.5);
  f_ZA->SetMarkerStyle(20);
	f_ZN->SetMarkerColor(4);
  f_ZN->SetMarkerSize(1.5);
  f_ZN->SetMarkerStyle(20);

	f_ZZ->SetTitle(name1);
	f_ZZ->Draw("HIST P");
	f_ZA ->Draw("SAME");
	f_ZN ->Draw("SAME");
	auto legend = new TLegend(0.1,0.1,0.2,0.9);
  legend->SetHeader("Frequencies:","C"); // option "C" allows to center the header
  legend->AddEntry(f_ZZ, "f(Z->Z-1)","p");
  legend->AddEntry(f_ZA,"f(A->A-1)","p");
  legend->AddEntry(f_ZN, "f(N->N-1)","p");
  legend->Draw();
	
	/*TFile *file1 = new TFile(name1, "RECREATE");
	file1->cd();
	f_ZZ->Write();
	file1->Write();
*/
  

	stringstream tmpname2;
	tmpname2<<"DensityA_A-1.root";

	string tmp_name2 = tmpname2.str();
	const char *name2 =(char*) tmp_name2.c_str();		

	TCanvas *c2 = new TCanvas(name2,name2,1500,1100);
	gStyle->SetOptStat(11);
	c2->SetLogz();
	c2->SetGrid();
	f_AA->GetXaxis()->SetTitle("A");
	f_AA->GetYaxis()->SetTitle("f (A-1)");
	c2->SetLogy();
	f_AA->GetXaxis()->SetNdivisions(260); 


	f_AZ->SetMarkerColor(2);
	f_AZ->SetMarkerSize(1.5);
	f_AZ->SetMarkerStyle(20);
	f_AA->SetMarkerColor(6);
  f_AA->SetMarkerSize(1.5);
  f_AA->SetMarkerStyle(20);
	f_AN->SetMarkerColor(4);
  f_AN->SetMarkerSize(1.5);
  f_AN->SetMarkerStyle(20);

	f_AA->SetTitle(name2);
	f_AA->Draw("HIST P");
	f_AZ ->Draw("SAME");
	f_AN ->Draw("SAME");
	auto legend1 = new TLegend(0.1,0.1,0.2,0.9);
  legend1->SetHeader("Frequencies:","C"); // option "C" allows to center the header
  legend1->AddEntry(f_AZ, "f(Z->Z-1)","p");
  legend1->AddEntry(f_AA,"f(A->A-1)","p");
  legend1->AddEntry(f_AN, "f(N->N-1)","p");
  legend1->Draw();


/*	TFile *file2 = new TFile(name2, "RECREATE");
	file2->cd();
	f_AA->Write();
	file2->Write();
*/

	stringstream tmpname3;
	tmpname3<<"DensityN_N1.root";

	string tmp_name3 = tmpname3.str();
	const char *name3 =(char*) tmp_name3.c_str();		

	TCanvas *c3 = new TCanvas(name3,name3,1500,1100);
	gStyle->SetOptStat(11);
	c3->SetLogz();
	c3->SetGrid();
	f_NN->GetXaxis()->SetTitle("N");
	f_NN->GetYaxis()->SetTitle("f (N-1)");
	c3->SetLogy();
	f_NN->GetXaxis()->SetNdivisions(110); 

  f_NZ->SetMarkerColor(2);
	f_NZ->SetMarkerSize(1.5);
	f_NZ->SetMarkerStyle(20);
	f_NA->SetMarkerColor(6);
  f_NA->SetMarkerSize(1.5);
  f_NA->SetMarkerStyle(20);
	f_NN->SetMarkerColor(4);
  f_NN->SetMarkerSize(1.5);
  f_NN->SetMarkerStyle(20);

	f_NN->SetTitle(name3);
	f_NN->Draw("HIST P");
	f_NA ->Draw("SAME");
	f_NZ ->Draw("SAME");
	auto legend2 = new TLegend(0.1,0.1,0.2,0.9);
  legend2->SetHeader("Frequencies:","C"); // option "C" allows to center the header
  legend2->AddEntry(f_NZ, "f(Z->Z-1)","p");
  legend2->AddEntry(f_NA,"f(A->A-1)","p");
  legend2->AddEntry(f_NN, "f(N->N-1)","p");
  legend2->Draw();

	/*TFile *file3= new TFile(name3, "RECREATE");
	file3->cd();
	f_NN->Write();
	file3->Write();
*/

	TCanvas *c4 = new TCanvas("density2D","density2D",1500,1100);
	gStyle->SetOptStat(11);
	c3->SetLogz();
	c3->SetGrid();
	f_ZN_N->GetXaxis()->SetTitle("Z");
	f_ZN_N->GetYaxis()->SetTitle("N");
	//c3->SetLogy();
	f_ZN_N->GetXaxis()->SetNdivisions(110); 
	f_ZN_N->GetYaxis()->SetNdivisions(160);

	f_ZN_Z->SetMarkerColor(2);
	f_ZN_Z->SetMarkerSize(1.5);
	f_ZN_Z->SetMarkerStyle(20);
	f_ZN_A->SetMarkerColor(6);
  f_ZN_A->SetMarkerSize(1.5);
  f_ZN_A->SetMarkerStyle(20);
	f_ZN_N->SetMarkerColor(4);
  f_ZN_N->SetMarkerSize(1.5);
  f_ZN_N->SetMarkerStyle(20);

  f_ZN_Z->Draw("SURF");
  f_ZN_Z->Draw("SAME");
  f_ZN_Z->Draw("SAME");

   

   /*c->SaveAs("densityZ.png");
	 c2->SaveAs("densityA.png");
	 c3->SaveAs("densityN.png");
   c4->SaveAs("3Ddensity.png");*/

}
