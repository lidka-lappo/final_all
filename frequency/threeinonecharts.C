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

void threecharts()
{

	//CHOOSE ISOTOP
	//which isotop is the goal, change ZZ and AA accordingly 
	//////////////////////////////////////////////////////////////////////////	
	//int ZZ = 13;
	//int AA = 24;
	int ZZ = 50; //50
	int AA = 99; //99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137
	int OUT = 1;
	//change 0 if IN, 1 if OUT
	//////////////////////////////////////////////////////////////////////////
	

	stringstream tmpname;
	if(OUT)
		tmpname <<"../to_the_product/ZNproduct"<<names[ZZ]<<AA<<".root";
	else
		tmpname <<"../from_the_target/target"<<names[ZZ]<<AA<<".root";
	string tmp_name = tmpname.str();
	const char *name =(char*) tmp_name.c_str();	
	TFile *file;
	cout<<"Reading File : "<<name<<endl;
	cout<<endl;
	file = TFile::Open(name);
	if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl; return; } //precaution
	else {
		cout <<"OK"<<endl;
		}

	TH2D * hist;
	hist = (TH2D*)file->Get("N:Z")->Clone();

// relsult from initial
	TH1D *f_Z = hist->ProjectionY();
	TH1D *f_A = hist->ProjectionX();
	TH1D *f_N=new TH1D("f_N", "f_N", 150, 0, 150);
	for(int A=1; A<150; A++)
	{
		for(int Z=1; Z<150; Z++)
		{
			
			int N = A-Z;
			int f = hist->GetBinContent(Z, (A-Z));
			f_N->Fill(N, f);
			//if(f!=0)
			//	cout<<N <<" : "<< f<<endl;
		}


	}

	stringstream tmpname1;
	if(OUT)
		tmpname1<<"Out: "<<names[ZZ]<<AA<<"Freq(Z_in/A_in/N_in).root";
	else
		tmpname1<<"In: "<<names[ZZ]<<AA<<"Freq(Z_out/A_out/N_out).root";

	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(11);
	c->SetLogz();
	c->SetGrid();
	if(OUT)
		f_Z->GetXaxis()->SetTitle("Z_in");
	else
		f_Z->GetXaxis()->SetTitle("Z_out");
	f_Z->GetYaxis()->SetTitle("f");
	c->SetLogy();
	f_Z->GetXaxis()->SetNdivisions(150); 
	f_Z->SetMarkerColor(2);
	f_Z->SetMarkerSize(1.5);
	f_Z->SetMarkerStyle(20);
	f_Z->SetTitle("Z");
	f_Z->Draw("HIST P");

	f_A->SetMarkerColor(6);
	f_A->SetMarkerSize(1.5);
	f_A->SetMarkerStyle(20);
	f_A->SetTitle("A");
	f_A->Draw("SAME");
	
	f_N->SetMarkerColor(4);
	f_N->SetMarkerSize(1.5);
	f_N->SetMarkerStyle(20);
	f_N->SetTitle("N");
	f_N->Draw("SAME");


}