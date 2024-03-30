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


void open()
{
	//////////////////////////////////////////////////////////////////////////
	
			Int_t ZZ = 8;
			Int_t AA = 16;
			stringstream tmpname;
			tmpname <<"../from_the_source/target"<<names[ZZ]<<AA<<".root";
			string tmp_name = tmpname.str();
			const char *name =(char*) tmp_name.c_str();	
			TFile *file;
			cout<<"Reading File : "<<name<<endl;
			cout<<endl;
			file = TFile::Open(name);
			if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl;} //precaution
			else {
				cout <<"OK"<<endl;
				TH3D *ZNE;
				ZNE = (TH3D*)file->Get("Z:N")->Clone();
				TH2D * hist;
				hist = ZNE->Project3DProfile("xy");
				
				TCanvas *c4 = new TCanvas("test","test",1500,1100);
				hist->Draw("colz");
				c4->SaveAs("test.png");
				TFile *file1 = new TFile("test.root", "RECREATE");
				file1->cd();
				hist->Write();
				file1->Write();
			}


}
