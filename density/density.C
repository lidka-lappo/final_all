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
            cout<<histogram->GetNbinsX()<<endl;
    	    cout<<(int)weights.size()<<endl;	    
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

        TH1D *f_AZeven=new TH1D("f_AZ", "f_AZ", 256, 0, 256);
        TH1D *f_NZeven=new TH1D("f_NZ", "f_NZ", 155, 0, 155);
        TH1D *f_ZZeven=new TH1D("f_ZZ", "f_ZZ", 101, 0, 101);

        TH1D *f_AAeven=new TH1D("f_AA", "f_AA", 256, 0, 256);
        TH1D *f_NAeven=new TH1D("f_NA", "f_NA", 155, 0, 155);
        TH1D *f_ZAeven=new TH1D("f_ZA", "f_ZA", 101, 0, 101);

        TH1D *f_ANeven=new TH1D("f_AN", "f_AN", 256, 0, 256);
        TH1D *f_NNeven=new TH1D("f_NN", "f_NN", 155, 0, 155);
        TH1D *f_ZNeven=new TH1D("f_ZN", "f_ZN", 101, 0, 101);


        TH1D *f_AZodd=new TH1D("f_AZ", "f_AZ", 256, 0, 256);
        TH1D *f_NZodd=new TH1D("f_NZ", "f_NZ", 155, 0, 155);
        TH1D *f_ZZodd=new TH1D("f_ZZ", "f_ZZ", 101, 0, 101);

        TH1D *f_AAodd=new TH1D("f_AA", "f_AA", 256, 0, 256);
        TH1D *f_NAodd=new TH1D("f_NA", "f_NA", 155, 0, 155);
        TH1D *f_ZAodd=new TH1D("f_ZA", "f_ZA", 101, 0, 101);

        TH1D *f_ANodd=new TH1D("f_AN", "f_AN", 256, 0, 256);
        TH1D *f_NNodd=new TH1D("f_NN", "f_NN", 155, 0, 155);
        TH1D *f_ZNodd=new TH1D("f_ZN", "f_ZN", 101, 0, 101);



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

	std::vector<double> weightsZ = {7, 8, 11, 12, 16, 16, 16, 18, 19, 20, 23, 23, 23, 24, 24, 24, 25, 26, 29, 29, 29, 29, 29, 30, 31, 32, 32, 35, 33, 33, 33, 33, 33, 33, 34, 35, 34, 35, 35, 37, 38, 39, 40, 41, 41, 42, 42, 42, 42, 42, 41, 42, 42, 43, 42, 42, 42, 41, 41, 40, 40, 41, 41, 40, 40, 39, 39, 39, 39, 38, 39, 38, 40, 41, 41, 43, 43, 44, 43, 47, 43, 43, 41, 42, 39, 39, 37, 35, 33, 32, 31, 29, 27, 27, 27, 22, 22, 20, 20, 1, 1};
    std::vector<double> weightsA = {1, 1, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 6, 7, 7, 7, 7, 8, 8, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 11, 10, 11, 11, 11, 11, 12, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 13, 13, 12, 12, 13, 12, 13, 12, 13, 13, 14, 14, 14, 14, 13, 14, 13, 14, 13, 14, 13, 13, 13, 13, 13, 14, 13, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 14, 15, 14, 15, 14, 15, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 15, 16, 16, 16, 16, 15, 16, 16, 17, 16, 16, 17, 16, 16, 17, 16, 17, 17, 16, 17, 17, 17, 17, 18, 17, 18, 18, 17, 18, 17, 18, 17, 17, 17, 17, 18, 17, 18, 17, 18, 18, 17, 17, 17, 17, 18, 17, 17, 17, 17, 17, 17, 18, 17, 18, 17, 18, 17, 18, 17, 18, 17, 17, 18, 17, 18, 17, 17, 16, 16, 15, 16, 15, 16, 15, 15, 14, 14, 13, 14, 14, 14, 14, 14, 13, 13, 13, 13, 14, 14, 13, 13, 14, 13, 13, 12, 13, 13, 13, 12, 13, 12, 12, 13, 12, 12, 12, 12, 12, 12, 13, 13, 12, 12, 12, 12, 12, 12, 13, 13, 12, 12, 12, 11, 11, 10, 11, 10, 11, 10, 10, 9, 10, 9, 10, 9, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 4, 3, 3, 2, 2};
    
    
    std::vector<double> weightsN = {2, 5, 6, 8, 9, 10, 11, 11, 13, 13, 14, 15, 16, 16, 17, 18, 19, 19, 19, 19, 21, 20, 20, 20, 21, 21, 22, 23, 23, 23, 23, 23, 22, 21, 21, 22, 22, 22, 23, 24, 25, 25, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 26, 27, 26, 26, 26, 25, 25, 24, 25, 25, 25, 25, 26, 26, 27, 26, 27, 27, 26, 27, 28, 28, 29, 28, 28, 28, 29, 28, 29, 29, 30, 30, 31, 31, 31, 30, 30, 31, 30, 29, 29, 28, 28, 29, 28, 27, 26, 26, 26, 26, 25, 24, 23, 24, 24, 23, 22, 22, 21, 20, 20, 19, 19, 19, 19, 19, 18, 19, 19, 18, 19, 18, 17, 18, 19, 19, 18, 18, 17, 16, 16, 16, 17, 18, 17, 16, 16, 17, 17, 16, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5}; 
 divideHistogramByWeights(f_ZZ, weightsZ);
    divideHistogramByWeights(f_ZA, weightsZ);
    divideHistogramByWeights(f_ZN, weightsZ);
    divideHistogramByWeights(f_AZ, weightsA);
    divideHistogramByWeights(f_AA, weightsA);
    divideHistogramByWeights(f_AN, weightsA);
    divideHistogramByWeights(f_NZ, weightsN);
    divideHistogramByWeights(f_NA, weightsN);
    divideHistogramByWeights(f_NN, weightsN);
	stringstream tmpname1;
	tmpname1<<"DensityZ_Z-1.root";

	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(0);
	//c->SetLogz();
	c->SetGrid();
	f_ZA->GetXaxis()->SetTitle("Z");
	f_ZA->GetYaxis()->SetTitle("f");
	f_ZAeven->GetXaxis()->SetTitle("Z");
	f_ZAeven->GetYaxis()->SetTitle("f");
	//c->SetLogy();
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

	f_ZZeven->SetMarkerColor(2);
	f_ZZeven->SetMarkerSize(1.5);
	f_ZZeven->SetMarkerStyle(20);
	f_ZAeven->SetMarkerColor(6);
  	f_ZAeven->SetMarkerSize(1.5);
  	f_ZAeven->SetMarkerStyle(20);
	f_ZNeven->SetMarkerColor(4);
  	f_ZNeven->SetMarkerSize(1.5);
  	f_ZNeven->SetMarkerStyle(20);
            
	f_ZZodd->SetMarkerColor(2);
	f_ZZodd->SetMarkerSize(1.5);
	f_ZZodd->SetMarkerStyle(20);
	f_ZAodd->SetMarkerColor(6);
  	f_ZAodd->SetMarkerSize(1.5);
  	f_ZAodd->SetMarkerStyle(20);
	f_ZNodd->SetMarkerColor(4);
  	f_ZNodd->SetMarkerSize(1.5);
  	f_ZNodd->SetMarkerStyle(20);
	
	
	f_ZAeven->SetMarkerStyle(34);
        f_ZAodd->SetMarkerStyle(23); 
	f_ZZeven->SetMarkerStyle(34);
        f_ZZodd->SetMarkerStyle(23); 
	f_ZNeven->SetMarkerStyle(34);
        f_ZNodd->SetMarkerStyle(23); 


    for (int i = 1; i <= f_ZA->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_ZAeven->SetBinContent(i, f_ZA->GetBinContent(i)); 
        } else { // odd bins
            f_ZAodd->SetBinContent(i, f_ZA->GetBinContent(i)); 
	}
    }
    for (int i = 1; i <= f_ZZ->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_ZZeven->SetBinContent(i, f_ZZ->GetBinContent(i)); 
        } else { // odd bins
            f_ZZodd->SetBinContent(i, f_ZZ->GetBinContent(i)); 
	}
    }
    for (int i = 1; i <= f_ZN->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_ZNeven->SetBinContent(i, f_ZN->GetBinContent(i)); 
        } else { // odd bins
            f_ZNodd->SetBinContent(i, f_ZN->GetBinContent(i)); 
	}
    }


	//f_ZA->SetTitle("Rate of single annihilation to Z ");
	//f_ZA ->Draw("HIST P");
	f_ZAeven->SetTitle("Rate of single annihilation to Z ");
	f_ZAeven ->Draw("HIST  P");
	f_ZAodd ->Draw("HIST SAME P");
	f_ZZeven ->Draw("HIST SAME P");
	f_ZZodd ->Draw("HIST SAME P");
	f_ZNeven ->Draw("HIST SAME P");
	f_ZNodd ->Draw("HIST SAME P");
	
	//_ZZ->Draw("HIST SAME P");
	//f_ZN ->Draw("HIST SAME P");
	auto legend = new TLegend(0.1,0.9,0.2,1);
  legend->SetHeader("Frequencies ODD and EVEN:","C"); // option "C" allows to center the header
  //legend->AddEntry(f_ZZ, "f(Z->Z-1)","p");
  //legend->AddEntry(f_ZA,"f(A->A-1)","p");
  //legend->AddEntry(f_ZN, "f(N->N-1)","p");
  legend->AddEntry(f_ZZeven, "E: f(Z->Z-1)","p");
  legend->AddEntry(f_ZAeven,"E: f(A->A-1)","p");
  legend->AddEntry(f_ZNeven, "E: f(N->N-1)","p");
  legend->AddEntry(f_ZZodd, "O: f(Z->Z-1)","p");
  legend->AddEntry(f_ZAodd,"O: f(A->A-1)","p");
  legend->AddEntry(f_ZNodd, "O: f(N->N-1)","p");
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
	//c2->SetLogz();
	c2->SetGrid();
	f_AA->GetXaxis()->SetTitle("A");
	f_AA->GetYaxis()->SetTitle("f");
	f_AAeven->GetXaxis()->SetTitle("A");
	f_AAeven->GetYaxis()->SetTitle("f");
	//c2->SetLogy();
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


          f_AZeven->SetMarkerColor(2);
        f_AZeven->SetMarkerSize(1.5);
        f_AZeven->SetMarkerStyle(20);
        f_AAeven->SetMarkerColor(6);
        f_AAeven->SetMarkerSize(1.5);
        f_AAeven->SetMarkerStyle(20);
        f_ANeven->SetMarkerColor(4);
        f_ANeven->SetMarkerSize(1.5);
        f_ANeven->SetMarkerStyle(20);

        f_AZodd->SetMarkerColor(2);
        f_AZodd->SetMarkerSize(1.5);
        f_AZodd->SetMarkerStyle(20);
        f_AAodd->SetMarkerColor(6);
        f_AAodd->SetMarkerSize(1.5);
        f_AAodd->SetMarkerStyle(20);
        f_ANodd->SetMarkerColor(4);
        f_ANodd->SetMarkerSize(1.5);
        f_ANodd->SetMarkerStyle(20);


        f_AAeven->SetMarkerStyle(34);
        f_AAodd->SetMarkerStyle(23);
        f_AZeven->SetMarkerStyle(34);
        f_AZodd->SetMarkerStyle(23);
        f_ANeven->SetMarkerStyle(34);
        f_ANodd->SetMarkerStyle(23);


    for (int i = 1; i <= f_AA->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_AAeven->SetBinContent(i, f_AA->GetBinContent(i));
        } else { // odd bins
            f_AAodd->SetBinContent(i, f_AA->GetBinContent(i));
        }
    }
    for (int i = 1; i <= f_AZ->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_AZeven->SetBinContent(i, f_AZ->GetBinContent(i));
        } else { // odd bins
            f_AZodd->SetBinContent(i, f_AZ->GetBinContent(i));
        }
    }
    for (int i = 1; i <= f_AN->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_ANeven->SetBinContent(i, f_AN->GetBinContent(i));
        } else { // odd bins
            f_ANodd->SetBinContent(i, f_AN->GetBinContent(i));
        }
    }


	//f_AA->SetTitle("Rate of single annihilation to A ");
	//f_AA->Draw("HIST P");
	//f_AZ ->Draw("HIST SAME P");
	//f_AN ->Draw("HIST SAME P");
        f_AAeven->SetTitle("Rate of single annihilation to A ");
        f_AAeven ->Draw("HIST  P");
        f_AAodd ->Draw("HIST SAME P");
        f_AZeven ->Draw("HIST SAME P");
        f_AZodd ->Draw("HIST SAME P");
        f_ANeven ->Draw("HIST SAME P");
        f_ANodd ->Draw("HIST SAME P");


	auto legend1 = new TLegend(0.1,0.9,0.2,1);
	  legend1->SetHeader("Frequencies ODD and EVEN:","C"); // option "C" allows to center the header
  //legend1->AddEntry(f_AZ, "f(Z->Z-1)","p");
  //legend1->AddEntry(f_AA,"f(A->A-1)","p");
  //legend1->AddEntry(f_AN, "f(N->N-1)","p");
  legend1->AddEntry(f_AZeven, "E: f(Z->Z-1)","p");
  legend1->AddEntry(f_AAeven,"E: f(A->A-1)","p");
  legend1->AddEntry(f_ANeven, "E: f(N->N-1)","p");
  legend1->AddEntry(f_AZodd, "O: f(Z->Z-1)","p");
  legend1->AddEntry(f_AAodd,"O: f(A->A-1)","p");
  legend1->AddEntry(f_ANodd, "O: f(N->N-1)","p");

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
	//c3->SetLogz();
	c3->SetGrid();
	f_NA->GetXaxis()->SetTitle("N");
	f_NA->GetYaxis()->SetTitle("f");
	f_NAeven->GetXaxis()->SetTitle("N");
	f_NAeven->GetYaxis()->SetTitle("f");
	//c3->SetLogy();
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


          f_NZeven->SetMarkerColor(2);
        f_NZeven->SetMarkerSize(1.5);
        f_NZeven->SetMarkerStyle(20);
        f_NAeven->SetMarkerColor(6);
        f_NAeven->SetMarkerSize(1.5);
        f_NAeven->SetMarkerStyle(20);
        f_NNeven->SetMarkerColor(4);
        f_NNeven->SetMarkerSize(1.5);
        f_NNeven->SetMarkerStyle(20);

        f_NZodd->SetMarkerColor(2);
        f_NZodd->SetMarkerSize(1.5);
        f_NZodd->SetMarkerStyle(20);
        f_NAodd->SetMarkerColor(6);
        f_NAodd->SetMarkerSize(1.5);
        f_NAodd->SetMarkerStyle(20);
        f_NNodd->SetMarkerColor(4);
        f_NNodd->SetMarkerSize(1.5);
        f_NNodd->SetMarkerStyle(20);


        f_NAeven->SetMarkerStyle(34);
        f_NAodd->SetMarkerStyle(23);
        f_NZeven->SetMarkerStyle(34);
        f_NZodd->SetMarkerStyle(23);
        f_NNeven->SetMarkerStyle(34);
        f_NNodd->SetMarkerStyle(23);


    for (int i = 1; i <= f_NA->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_NAeven->SetBinContent(i, f_NA->GetBinContent(i));
        } else { // odd bins
            f_NAodd->SetBinContent(i, f_NA->GetBinContent(i));
        }
    }
    for (int i = 1; i <= f_NZ->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_NZeven->SetBinContent(i, f_NZ->GetBinContent(i));
        } else { // odd bins
            f_NZodd->SetBinContent(i, f_NZ->GetBinContent(i));
        }
    }
    for (int i = 1; i <= f_NN->GetNbinsX(); ++i) {
        if (i % 2 == 0) { // even bins
            f_NNeven->SetBinContent(i, f_NN->GetBinContent(i));
        } else { // odd bins
            f_NNodd->SetBinContent(i, f_NN->GetBinContent(i));
        }
    }


	//f_NA->SetTitle("Rate of single annihilation to N ");
	//f_NA ->Draw("HIST P");
	//f_NN->Draw("HIST SAME P");
	//f_NZ ->Draw("HIST SAME P");

        f_NAeven->SetTitle("Rate of single annihilation to N ");
        f_NAeven ->Draw("HIST  P");
        f_NAodd ->Draw("HIST SAME P");
        f_NZeven ->Draw("HIST SAME P");
        f_NZodd ->Draw("HIST SAME P");
        f_NNeven ->Draw("HIST SAME P");
        f_NNodd ->Draw("HIST SAME P");


	auto legend2 = new TLegend(0.1,0.9,0.2,1);
          legend2->SetHeader("Frequencies ODD and EVEN:","C"); // option "C" allows to center the header
  //legend2->AddEntry(f_NZ, "f(Z->Z-1)","p");
  //legend2->AddEntry(f_NA,"f(A->A-1)","p");
  //legend2->AddEntry(f_NN, "f(N->N-1)","p");
  legend2->AddEntry(f_NZeven, "E: f(Z->Z-1)","p");
  legend2->AddEntry(f_NAeven,"E: f(A->A-1)","p");
  legend2->AddEntry(f_NNeven, "E: f(N->N-1)","p");
  legend2->AddEntry(f_NZodd, "O: f(Z->Z-1)","p");
  legend2->AddEntry(f_NAodd,"O: f(A->A-1)","p");
  legend2->AddEntry(f_NNodd, "O: f(N->N-1)","p");
  legend2->Draw();

	TFile *file3= new TFile(name3, "RECREATE");
	file3->cd();
	f_NN->Write();
	f_NZ->Write();
	f_NA->Write();
	file3->Write();


/*	TCanvas *c4 = new TCanvas("density2D","density2D",1500,1100);
	gStyle->SetOptStat(0);
	c4->SetLogz();
	//c4->SetGrid();
	f_ZN_N->GetXaxis()->SetTitle("N");
	f_ZN_N->GetYaxis()->SetTitle("Z");
	f_ZN_A->GetXaxis()->SetTitle("N");
	f_ZN_A->GetYaxis()->SetTitle("Z");
	f_ZN_Z->GetXaxis()->SetTitle("N");
	f_ZN_Z->GetYaxis()->SetTitle("Z");
	//c3->SetLogy();
	//f_ZN_N->GetXaxis()->SetNdivisions(160); 
	//f_ZN_N->GetYaxis()->SetNdivisions(110);

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
    //f_ZN_N->Add(f_ZN_Z, -1);
 // f_ZN_Z->Draw("colz");
 // f_ZN_A->Draw("colz");
 // f_ZN_N->Draw("colz");
*/
   

   c->SaveAs("densityZevenodd.png");
   c2->SaveAs("densityAevenodd.png");
   c3->SaveAs("densityNevenodd.png");
   //c4->SaveAs("3DdensityAlog.png");

}
