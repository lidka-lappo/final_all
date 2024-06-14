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


void halo()
{
	//////////////////////////////////////////////////////////////////////////
/*	TH1D *f_AZ=new TH1D("f_AZ", "f_AZ", 256, 0, 256);
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
*/


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

				Double_t N_pp = hist->GetBinContent(NN, ZZ-1);
			/*f_ZZ->Fill(ZZ, f1);
				f_AZ->Fill(AA, f1);
				f_NZ->Fill(NN, f1);
*/
				Double_t N_pn = hist->GetBinContent(NN-1, ZZ);
				
				/*f_NN->Fill(NN, f2);
				f_AN->Fill(AA, f2);
				f_ZN->Fill(ZZ, f2);

				f_AA->Fill(AA, f1+f2);
				f_ZA->Fill(ZZ, f1+f2);
				f_NA->Fill(NN, f1+f2);*/
				Double_t f;
				if(N_pn!=0)
				{
				//f = (N_pn*ZZ)/(N_pp*NN);
				f = (N_pp*NN)/(N_pn*ZZ);
				f_ZN_A->Fill(NN, ZZ, f);
				f_ZN_N->Fill(NN, ZZ, N_pn);
				f_ZN_Z->Fill(NN, ZZ, N_pp);
				}
				//if(f!=0)
				//	cout<<N <<" : "<< f<<endl;


				//delete hist3D;
				delete hist;
				delete file;
			}
		}
	}

	/*std::vector<double> weightsZ = {7, 8, 11, 12, 16, 16, 16, 18, 19, 20, 23, 23, 23, 24, 24, 24, 25, 26, 29, 29, 29, 29, 29, 30, 31, 32, 32, 35, 33, 33, 33, 33, 33, 33, 34, 35, 34, 35, 35, 37, 38, 39, 40, 41, 41, 42, 42, 42, 42, 42, 41, 42, 42, 43, 42, 42, 42, 41, 41, 40, 40, 41, 41, 40, 40, 39, 39, 39, 39, 38, 39, 38, 40, 41, 41, 43, 43, 44, 43, 47, 43, 43, 41, 42, 39, 39, 37, 35, 33, 32, 31, 29, 27, 27, 27, 22, 22, 20, 20, 1, 1};
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
	const char *name1 =(char*) tmp_name1.c_str();	*/



	TCanvas *c4 = new TCanvas("density2D","density2D",1500,1100);
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
//  f_ZN_Z->Draw("colz");
  f_ZN_A->Draw("colz");
  //f_ZN_N->Draw("colz");

   

   //c->SaveAs("densityZevenodd.png");
   //c2->SaveAs("densityAevenodd.png");
   //c3->SaveAs("densityNevenodd.png");
   c4->SaveAs("phalo.png");

}
