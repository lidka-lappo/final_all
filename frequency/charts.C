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

void charts()
{

	//CHOOSE ISOTOP
	//which isotop is the goal, change ZZ and AA accordingly 
	//////////////////////////////////////////////////////////////////////////	
	//int ZZ = 13;
	//int AA = 24;
	int ZZ = 78;
	int AA = 170;
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
	hist = (TH2D*)file->Get("Z:N")->Clone();

	TH1D *f_Z = hist->ProjectionY();
	TH1D *f_N = hist->ProjectionX();
	TH1D *f_A=new TH1D("f_N", "f_N", 150, 0, 150);
	
		for(int Z=1; Z<150; Z++)
		{
			for(int N=0; N<150; N++)
			{
			int A = N+Z;
			int f = hist->GetBinContent(N, Z);
			f_A->Fill(A, f);
			//if(f!=0)
			//	cout<<N <<" : "<< f<<endl;
			}
		}

	stringstream tmpname1;
	if(OUT)
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<AA<<" dependent from target Z.root";
	else
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<AA<<" dependent from product Z.root";

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
	f_Z->SetTitle(name1);
	f_Z->Draw("HIST P");

	TFile *file1 = new TFile(name1, "RECREATE");
	file1->cd();
	f_Z->Write();
	file1->Write();


	if(OUT)
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<AA<<" dependent from target A.root";
	else
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<AA<<" dependent from product A.root";

	string tmp_name2 = tmpname2.str();
	const char *name2 =(char*) tmp_name2.c_str();		

	TCanvas *c2 = new TCanvas(name2,name2,1500,1100);
	gStyle->SetOptStat(11);
	c2->SetLogz();
	c2->SetGrid();
	if(OUT)
		f_A->GetXaxis()->SetTitle("A_in");
	else
		f_A->GetXaxis()->SetTitle("A_out");
	f_A->GetYaxis()->SetTitle("f");
	c2->SetLogy();
	f_A->GetXaxis()->SetNdivisions(150); 
	f_A->SetMarkerColor(6);
   	f_A->SetMarkerSize(1.5);
   	f_A->SetMarkerStyle(20);
	f_A->SetTitle(name2);
	f_A->Draw("HIST P");


	TFile *file2 = new TFile(name2, "RECREATE");
	file2->cd();
	f_A->Write();
	file2->Write();


	stringstream tmpname3;
	if(OUT)
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<AA<<" dependent from target N.root";
	else
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<AA<<" dependent from product N.root";

	string tmp_name3 = tmpname3.str();
	const char *name3 =(char*) tmp_name3.c_str();		

	TCanvas *c3 = new TCanvas(name3,name3,1500,1100);
	gStyle->SetOptStat(11);
	c3->SetLogz();
	c3->SetGrid();
	if(OUT)
		f_N->GetXaxis()->SetTitle("N_in");
	else
		f_N->GetXaxis()->SetTitle("N_out");
	f_N->GetYaxis()->SetTitle("f");
	c3->SetLogy();
	f_N->GetXaxis()->SetNdivisions(150); 
	f_N->SetMarkerColor(4);
   	f_N->SetMarkerSize(1.5);
   	f_N->SetMarkerStyle(20);
	f_N->SetTitle(name3);
	f_N->Draw("HIST P");

	TFile *file3= new TFile(name3, "RECREATE");
	file3->cd();
	f_N->Write();
	file3->Write();


}
