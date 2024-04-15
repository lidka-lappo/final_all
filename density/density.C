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

void divideHistogramByWeights(TH1D* histogram, const std::vector<double>& weights) {
    // Check if the histogram and weights vector have compatible sizes
    if (histogram->GetNbinsX() != (int)weights.size()) {
        std::cerr << "Error: Histogram and weights vector have different sizes." << std::endl;
        return;
    }

    // Loop over each bin of the histogram
    for (int i = 1; i <= histogram->GetNbinsX(); ++i) {
        // Retrieve the content of the bin
        double binContent = histogram->GetBinContent(i);
        
        // Retrieve the corresponding weight from the table
        double weight = weights[i-1]; // Assuming the table is 0-indexed

        // Divide the bin content by the weight, avoiding division by zero
        if (weight != 0) {
            histogram->SetBinContent(i, binContent / weight);
        } else {
            std::cerr << "Warning: Division by zero encountered for bin " << i << std::endl;
        }
    }
}


void density()
{
	//////////////////////////////////////////////////////////////////////////
	TH1D *f_AZ=new TH1D("f_AZ", "f_AZ", 256, 0, 256);
	TH1D *f_NZ=new TH1D("f_NZ", "f_NZ", 155, 0, 155);
	TH1D *f_ZZ=new TH1D("f_ZZ", "f_ZZ", 101, 0, 101);

	TH1D *f_AA=new TH1D("f_AA", "f_AA", 256, 0, 256);
	TH1D *f_NA=new TH1D("f_NA", "f_NA", 155, 0, 155);
	TH1D *f_ZA=new TH1D("f_ZA", "f_ZA", 101, 0, 101);

	TH1D *f_AN=new TH1D("f_AN", "f_AN", 256, 0, 256);
	TH1D *f_NN=new TH1D("f_NN", "f_NN", 155, 0, 155);
	TH1D *f_ZN=new TH1D("f_ZN", "f_ZN", 101, 0, 101);

  TH2D *f_ZN_N=new TH2D("f_ZN_N", "f_ZN_N", 160, 0, 160, 110, 0 , 110);
  TH2D *f_ZN_Z=new TH2D("f_ZN_Z", "f_ZN_Z", 160, 0, 160, 110, 0 , 110);
  TH2D *f_ZN_A=new TH2D("f_ZN_A", "f_ZN_A", 160, 0, 160, 110, 0 , 110);

	for(int ZZ=1; ZZ<100; ZZ++)
	{
		for(int AA=lightisotop[ZZ]; AA<=heavyisotop[ZZ]; AA++)
		{
			stringstream tmpname;
			tmpname <<"../from_the_source/2Dfragments"<<names[ZZ]<<AA<<".root";
			string tmp_name = tmpname.str();
			const char *name =(char*) tmp_name.c_str();	
			TFile *file;
			cout<<"Reading File : "<<name<<endl;
			cout<<endl;
			file = TFile::Open(name);
			if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl;} //precaution
			else {
				cout <<"OK"<<endl;
				TH2D *hist;
				hist = (TH2D*)file->Get("hist2D")->Clone();
				//TH2D *hist = new TH2D("hist2D", "hist", hist3D->GetNbinsX(), hist3D->GetXaxis()->GetXmin(), hist3D->GetXaxis()->GetXmax(), hist3D->GetNbinsY(), hist3D->GetYaxis()->GetXmin(), hist3D->GetYaxis()->GetXmax());


				//hist = ZNE->Project3DProfile("xy");
				int NN = AA-ZZ;
/*
				for (int zbin = 0; zbin < 150; zbin++) {
				    for (int nbin = 0; nbin < 150; nbin++) {
				        for (int ebin = 0; ebin < 800; ebin++) {
				            // Check if the energy value is less than 100
				            //if (hist3D->GetZaxis()->GetBinCenter(ebin) < 1) {
				                // Fill the 2D histogram with Z and N values
				                hist->Fill(zbin, nbin, hist3D->GetBinContent(zbin+1, nbin+1, ebin));
				            //}
				        }
				    }
				}
*/

				Double_t f1 = hist->GetBinContent(NN, ZZ-1);
				f1=f1/1000000.0;
				f_ZZ->Fill(ZZ, f1);
				f_AZ->Fill(AA, f1);
				f_NZ->Fill(NN, f1);

				Double_t f2 = hist->GetBinContent(NN-1, ZZ);
				f2=f2/1000000.0;
				f_NN->Fill(NN, f2);
				f_AN->Fill(AA, f2);
				f_ZN->Fill(ZZ, f2);

				f_AA->Fill(AA, f1+f2);
				f_ZA->Fill(ZZ, f1+f2);
				f_NA->Fill(NN, f1+f2);

				f_ZN_A->Fill(NN, ZZ, f1+f2);
				f_ZN_N->Fill(NN, ZZ, f2);
				f_ZN_Z->Fill(NN, ZZ, f1);
				//if(f!=0)
				//	cout<<N <<" : "<< f<<endl;


				//delete hist3D;
				delete hist;
				delete file;
			}
		}
	}

	std::vector<double> weights = {7, 8, 11, 12, 16, 16, 16, 18, 19, 20, 23, 23, 23, 24, 24, 24, 25, 26, 29, 29, 29, 29, 29, 30, 31, 32, 32, 35, 33, 33, 33, 33, 33, 33, 34, 35, 34, 35, 35, 37, 38, 39, 40, 41, 41, 42, 42, 42, 42, 42, 41, 42, 42, 43, 42, 42, 42, 41, 41, 40, 40, 41, 41, 40, 40, 39, 39, 39, 39, 38, 39, 38, 40, 41, 41, 43, 43, 44, 43, 47, 43, 43, 41, 42, 39, 39, 37, 35, 33, 32, 31, 29, 27, 27, 27, 22, 22, 20, 20};
    divideHistogramByWeights(f_ZZ, weights);
    divideHistogramByWeights(f_ZA, weights);
    divideHistogramByWeights(f_ZN, weights);
	stringstream tmpname1;
	tmpname1<<"DensityZ_Z-1.root";

	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(0);
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
	f_ZA ->Draw("HIST SAME P");
	f_ZN ->Draw("HIST SAME P");
	auto legend = new TLegend(0.1,0.9,0.2,1);
  legend->SetHeader("Frequencies:","C"); // option "C" allows to center the header
  legend->AddEntry(f_ZZ, "f(Z->Z-1)","p");
  legend->AddEntry(f_ZA,"f(A->A-1)","p");
  legend->AddEntry(f_ZN, "f(N->N-1)","p");
  legend->Draw();
	
	TFile *file1 = new TFile(name1, "RECREATE");
	file1->cd();
	f_ZZ->Write();
	f_ZA->Write();
	f_ZN->Write();
	file1->Write();

  

	stringstream tmpname2;
	tmpname2<<"DensityA_A-1.root";

	string tmp_name2 = tmpname2.str();
	const char *name2 =(char*) tmp_name2.c_str();		

	TCanvas *c2 = new TCanvas(name2,name2,3000,1100);
	gStyle->SetOptStat(0);
	c2->SetLogz();
	c2->SetGrid();
	f_AA->GetXaxis()->SetTitle("A");
	f_AA->GetYaxis()->SetTitle("f (A-1)");
	c2->SetLogy();
	f_AA->GetXaxis()->SetNdivisions(128); 
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
	f_AZ ->Draw("HIST SAME P");
	f_AN ->Draw("HIST SAME P");
	auto legend1 = new TLegend(0.1,0.9,0.2,1);
  legend1->SetHeader("Frequencies:","C"); // option "C" allows to center the header
  legend1->AddEntry(f_AZ, "f(Z->Z-1)","p");
  legend1->AddEntry(f_AA,"f(A->A-1)","p");
  legend1->AddEntry(f_AN, "f(N->N-1)","p");
  legend1->Draw();


	TFile *file2 = new TFile(name2, "RECREATE");
	file2->cd();
	f_AA->Write();
	f_AZ->Write();
	f_AN->Write();
	file2->Write();


	stringstream tmpname3;
	tmpname3<<"DensityN_N1.root";

	string tmp_name3 = tmpname3.str();
	const char *name3 =(char*) tmp_name3.c_str();		

	TCanvas *c3 = new TCanvas(name3,name3,1500,1100);
	gStyle->SetOptStat(0);
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
	f_NA ->Draw("HIST SAME P");
	f_NZ ->Draw("HIST SAME P");
	auto legend2 = new TLegend(0.1,0.9,0.2,1);
  legend2->SetHeader("Frequencies:","C"); // option "C" allows to center the header
  legend2->AddEntry(f_NZ, "f(Z->Z-1)","p");
  legend2->AddEntry(f_NA,"f(A->A-1)","p");
  legend2->AddEntry(f_NN, "f(N->N-1)","p");
  legend2->Draw();

	TFile *file3= new TFile(name3, "RECREATE");
	file3->cd();
	f_NN->Write();
	f_NZ->Write();
	f_NA->Write();
	file3->Write();

/*
	TCanvas *c4 = new TCanvas("density2D","density2D",1500,1100);
	gStyle->SetOptStat(11);
	c4->SetLogz();
	//c4->SetGrid();
	f_ZN_N->GetXaxis()->SetTitle("Z");
	f_ZN_N->GetYaxis()->SetTitle("N");
	//c3->SetLogy();
	f_ZN_N->GetXaxis()->SetNdivisions(110); 
	f_ZN_N->GetYaxis()->SetNdivisions(160);

	f_ZN_Z->SetMarkerColor(2);
	f_ZN_Z->SetLineColor(2);
	f_ZN_Z->SetMarkerSize(1.5);
	f_ZN_Z->SetMarkerStyle(20);
	f_ZN_A->SetMarkerColor(6);
	f_ZN_A->SetLineColor(6);
  f_ZN_A->SetMarkerSize(1.5);
  f_ZN_A->SetMarkerStyle(20);
	f_ZN_N->SetMarkerColor(4);
	f_ZN_N->SetLineColor(4);
  f_ZN_N->SetMarkerSize(1.5);
  f_ZN_N->SetMarkerStyle(20);

  f_ZN_Z->Draw("LEGO2Z ");
  //f_ZN_A->Draw("same surf");
  f_ZN_N->Draw("same surf");
*/
   

   c->SaveAs("densityZ.png");
   c2->SaveAs("densityA.png");
   c3->SaveAs("densityN.png");
   //c4->SaveAs("3Ddensity.png");

}
