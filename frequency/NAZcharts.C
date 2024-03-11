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

void NAZcharts()
{

	//CHOOSE ISOTOP
	//which isotop is the goal, change ZZ and AA accordingly 
	//////////////////////////////////////////////////////////////////////////	
	//int ZZ = 13;
	//int AA = 24;
	int ZZ = 50; //50
	int AA = 100; //99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137
	//change 0 if IN, 1 if OUT
	//////////////////////////////////////////////////////////////////////////
	

	stringstream tmpfoldername;
	tmpfoldername <<"../tmp_product/ZNproduct"<<names[ZZ]<<AA<<".root";
	string tmp_folder_name = tmpfoldername.str();
	const char *folder_name =(char*) tmp_folder_name.c_str();	
	TFile *file;
	cout<<"Reading File : "<<folder_name<<endl;
	cout<<endl;
	file = TFile::Open(folder_name);
	if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl; return; } //precaution
	else {
		cout <<"OK"<<endl;
		}


	stringstream tmpname;
	tmpname <<"map_"<<names[ZZ]<<AA<<".root";
	string tmp_name = tmpname.str();
	const char *name =(char*) tmp_name.c_str();	
	TH2D * hist;
	hist = (TH2D*)file->Get("N:Z")->Clone();

// relsult from initial
	TH1D *f_Z = hist->ProjectionY();
	TH1D *f_N = hist->ProjectionX();
	TH1D *f_A=new TH1D("f_N", "f_N", 150, 0, 150);
	for(int N=0; N<150; N++)
	{
		for(int Z=1; Z<150; Z++)
		{
			int A = N+Z;
			int f = hist->GetBinContent(N, Z);
			f_A->Fill(A, f);
			//if(f!=0)
			//	cout<<N <<" : "<< f<<endl;
		}
	}

	stringstream tmpname1;
	tmpname1<<"Out: "<<names[ZZ]<<AA<<"Freq(Z_in).root";
	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(11);
	c->SetLogz();
	c->SetGrid();
	f_A->GetXaxis()->SetTitle("Z_in");
	f_A->GetYaxis()->SetTitle("f");
	c->SetLogy();
	f_A->GetXaxis()->SetNdivisions(150); 
	/*f_Z->SetMarkerColor(2);
	f_Z->SetMarkerSize(1.5);
	f_Z->SetMarkerStyle(20);
	f_Z->SetTitle("Z");
	f_Z->Draw("HIST P");
*/
	f_A->SetMarkerColor(6);
	f_A->SetMarkerSize(1.5);
	f_A->SetMarkerStyle(20);
	f_A->SetTitle("A");
	f_A->Draw("HIST P");
/*	
	f_N->SetMarkerColor(4);
	f_N->SetMarkerSize(1.5);
	f_N->SetMarkerStyle(20);
	f_N->SetTitle("N");
	f_N->Draw("SAME");
*/
 /*  auto legend = new TLegend(0.1,0.7,0.2,0.9);
   legend->SetHeader("N, Z, A","C"); // option "C" allows to center the header
   legend->AddEntry(f_N,"f(N_in)","p");
   legend->AddEntry(f_Z,"f(Z_in)","p");
   legend->AddEntry(f_A,"f(A_in)","p");
   legend->Draw();
*/
}
