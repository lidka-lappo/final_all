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


void pions_freq()
{
	//////////////////////////////////////////////////////////////////////////

Double_t f1;
  TH2D *f_pion=new TH2D("f_pion", "f_pion", 160, 0, 160, 110, 0 , 110);;

	for(int ZZ=1; ZZ<100; ZZ++)
	{
		for(int AA=lightisotop[ZZ]; AA<=heavyisotop[ZZ]; AA++)
		{
			stringstream tmpname;
			tmpname <<"../pionseyal/pions"<<names[ZZ]<<AA<<".root";
			//tmpname <<"pions"<<names[ZZ]<<AA<<".root";
			string tmp_name = tmpname.str();
			const char *name =(char*) tmp_name.c_str();	
			TFile *file;
			cout<<"Reading File : "<<name<<endl;
			cout<<endl;
			file = TFile::Open(name);
			if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl;} //precaution
			else {
				cout <<"OK"<<endl;
				TH3D *hist3D;
				
				hist3D = (TH3D*)file->Get("Z:N:P0")->Clone();
				TH2D *hist = new TH2D("hist2D", "hist", hist3D->GetNbinsX(), hist3D->GetXaxis()->GetXmin(), hist3D->GetXaxis()->GetXmax(), hist3D->GetNbinsY(), hist3D->GetYaxis()->GetXmin(), hist3D->GetYaxis()->GetXmax());


				//hist = ZNE->Project3DProfile("xy");
				int NN = AA-ZZ;

				for (int zbin = 0; zbin < 150; zbin++) {
				    for (int nbin = 0; nbin < 150; nbin++) {
				        for (int ebin = 0; ebin < 10; ebin++) {
				            // Check if the energy value is less than 100
				            if (hist3D->GetZaxis()->GetBinCenter(ebin) < 1) {
				                // Fill the 2D histogram with Z and N values
				               f1 += hist3D->GetBinContent(nbin+1, zbin+1, ebin);
				            } 
				        }
				    }
				}


				 //f1=f1/1000000.0;

				//Double_t f2 = hist->GetBinContent(NN-1, ZZ);
				//f2=f2/1000000.0;

				f_pion->Fill(NN, ZZ, f1);
				f1=0;
				//f_ZN_N->Fill(NN, ZZ, f2);
				//f_ZN_Z->Fill(NN, ZZ, f1);
				//if(f!=0)
				//	cout<<N <<" : "<< f<<endl;


				delete hist3D;
				delete hist;
				delete file;
			}
		}
	}
	cout<<f1<<endl;

	TCanvas *c4 = new TCanvas("npions","npions",1500,1100);
	gStyle->SetOptStat(0);
	c4->SetLogz();
	//c4->SetGrid();
	f_pion->GetXaxis()->SetTitle("N");
	f_pion->GetYaxis()->SetTitle("Z");

	//c3->SetLogy();
	//f_ZN_N->GetXaxis()->SetNdivisions(160); 
	//f_ZN_N->GetYaxis()->SetNdivisions(110);

	f_pion->SetMarkerColor(2);
	f_pion->SetLineColor(2);
	f_pion->SetMarkerSize(1.5);
	f_pion->SetMarkerStyle(20);


    //f_ZN_N->Add(f_ZN_Z, -1);
  f_pion->Draw("colz");
 // f_ZN_A->Draw("colz");
 // f_ZN_N->Draw("colz");

   


   c4->SaveAs("pion0_1.png");

}
