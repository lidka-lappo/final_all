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
void few_same_element_charts()
{

	//CHOOSE ISOTOP
	//which isotop is the goal, change ZZ and AA accordingly 
	//////////////////////////////////////////////////////////////////////////	
	//int ZZ = 13;
	//int AA = 24;
	int n =68; //ile isotopow//41
	int ZZ = 53; 
	int OUT = 0;
	//change 0 if IN, 1 if OUT
	//////////////////////////////////////////////////////////////////////////
	
	int empty[n];
	int AA[n]; //= 99//-140; //41
	for(int i=0; i<n; i++)
	{
		AA[i]=106+i;
		empty[i]=0;
	}

	//AA[0] = 120;
	//AA[1] = 135;
	//AA[2] = 120;
	//AA[3] = 135;
	//////////////////////////////////////////////////////////////////////////

	TH1D *f_N[n];
	TH1D *f_Z[n];
	TH1D *f_A[n];
	cout<< "kup" <<AA[0]<<endl;	
	for(int i=0; i<n; i++)
	{
		stringstream tmpname;
		if(OUT)
			tmpname <<"../to_the_product/ZNproduct"<<names[ZZ]<<AA[i]<<".root";
		else
		{
			//tmpname <<"../from_the_source/target"<<names[ZZ]<<AA[i]<<".root";
			tmpname <<"../from_the_source/2Dfragments"<<names[ZZ]<<AA[i]<<".root";
		}
		string tmp_name = tmpname.str();
		const char *name =(char*) tmp_name.c_str();	
		TFile *file;
		cout<<"Reading File : "<<name<<endl;
		cout<<endl;
		file = TFile::Open(name);
		if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl; empty[i] =1; } //precaution
		else {
			cout <<"OK"<<endl;

			TH2D* hist;
			if(OUT)
				hist = (TH2D*)file->Get("Z:N")->Clone();
			else	
				hist = (TH2D*)file->Get("hist2D")->Clone();
			//hist->Draw("colz");	
			stringstream iso;
			iso<<names[ZZ]<<AA;
			string tmp_iso = iso.str();
			const char *isotop =(char*) tmp_iso.c_str();
			hist = (TH2D*)file->Get("Z:N")->Clone();
			if(OUT)
			{
				f_A[i]=new TH1D(isotop, isotop, 250, 0, 250);
				f_N[i]=new TH1D(isotop, isotop, 150, 0, 150);
				f_Z[i]=new TH1D(isotop, isotop, 150, 0, 150);
			}
			else
			{
				f_A[i]=new TH1D(isotop, isotop, 250, 0, 250);
				f_N[i]=new TH1D(isotop, isotop, 150, 0, 150);
				f_Z[i]=new TH1D(isotop, isotop, 150, 0, 150);
			}
			//f_N[i] = hist->ProjectionX();
			//f_Z[i] = hist->ProjectionY();
			//f_N[i]->Draw("colz");
			for(int N=0; N<150; N++)
			{
				for(int Z=1; Z<150; Z++)
				{
					
					int A = N+Z;
					int f = hist->GetBinContent(N, Z);
					f_A[i]->Fill(A, f);
					f_Z[i]->Fill(Z, f);
					f_N[i]->Fill(N, f);
					//if(f!=0)
					//	cout<<N <<" : "<< f<<endl;
				}
			}
			delete file;
			delete hist;

		}
	}
	
	stringstream tmpname1;
	if(OUT)
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<" dependent from target Z.root";
	else
		tmpname1<<"Frequency of formation: "<<names[ZZ]<<" dependent from product Z.root";

	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(0);
	c->SetLogz();
	c->SetGrid();
	
	f_Z[0]->GetXaxis()->SetTitle("Z_in");
	f_Z[0]->GetYaxis()->SetTitle("f");
	c->SetLogy();
	f_Z[0]->GetXaxis()->SetNdivisions(150); 
	f_Z[0]->SetMarkerColor(49);
	f_Z[0]->SetLineColor(49);
	f_Z[0]->SetMarkerSize(0.7);
	f_Z[0]->SetMarkerStyle(20);
	f_Z[0]->SetTitle(name1);
	f_Z[0]->Draw("HIST PL");

	stringstream iso;
	iso<<names[ZZ]<<AA[0];
	string tmp_iso = iso.str();
	const char *isotop =(char*) tmp_iso.c_str();

	auto legend1 = new TLegend(0.1,0.1,0.2,0.9);
    	legend1->SetHeader("Isotops: ","C"); // option "C" allows to center the header
    	legend1->AddEntry(f_Z[0],isotop,"p");
	for(int i=1; i<n; i++)
	{	
		if(empty[i]!=1)
		{
			f_Z[i]->SetMarkerColor(i%49);
			f_Z[i]->SetMarkerSize(0.7);
			f_Z[i]->SetLineColor(i%49);
			f_Z[i]->SetMarkerStyle(20);
			f_Z[i]->Draw("HIST SAME PL");

			stringstream iso1;
			iso1<<names[ZZ]<<AA[i];
			string tmp_iso1 = iso1.str();
			const char *isotop1 =(char*) tmp_iso1.c_str();
	
			legend1->AddEntry(f_Z[i],isotop1,"p");
		}
	}
	legend1->Draw();

	stringstream tmpname2;
	if(OUT)
		tmpname2<<"Frequency of formation: "<<names[ZZ]<<" dependent from target A.root";
	else
		tmpname2<<"Frequency of formation: "<<names[ZZ]<<" dependent from product A.root";


	string tmp_name2 = tmpname2.str();
	const char *name2 =(char*) tmp_name2.c_str();	
	

	TCanvas *c2 = new TCanvas(name2,name2,1500,1100);
	gStyle->SetOptStat(0);
	c2->SetLogz();
	c2->SetGrid();
	f_A[0]->GetXaxis()->SetTitle("A_in");
	f_A[0]->GetYaxis()->SetTitle("f");
	c2->SetLogy();
	f_A[0]->GetXaxis()->SetNdivisions(150); 
	f_A[0]->SetMarkerColor(49);
	f_A[0]->SetLineColor(49);
	f_A[0]->SetMarkerSize(0.7);
	f_A[0]->SetMarkerStyle(20);
	f_A[0]->SetTitle(name2);
	f_A[0]->Draw("HIST PL");

	auto legend2 = new TLegend(0.1,0.1,0.2,0.9);
  	legend2->SetHeader("Isotops: ","C"); // option "C" allows to center the header
  	legend2->AddEntry(f_A[0],isotop,"p");
	for(int i=1; i<n; i++)
	{
		if(empty[i]!=1)
		{
			f_A[i]->SetMarkerColor(i%49);
			f_A[i]->SetMarkerSize(0.7);
			f_A[i]->SetLineColor(i%49);
			f_A[i]->SetMarkerStyle(20);
			f_A[i]->Draw("HIST SAME PL");

			stringstream iso1;
			iso1<<names[ZZ]<<AA[i];
			string tmp_iso1 = iso1.str();
			const char *isotop1 =(char*) tmp_iso1.c_str();

			legend2->AddEntry(f_A[i],isotop1,"p");
		
		}	
	}	
	legend2->Draw();


	stringstream tmpname3;
	if(OUT)
		tmpname3<<"Frequency of formation: "<<names[ZZ]<<" dependent from target N.root";
	else
		tmpname3<<"Frequency of formation: "<<names[ZZ]<<" dependent from product N.root";

	string tmp_name3 = tmpname3.str();
	const char *name3 =(char*) tmp_name3.c_str();		
	

	TCanvas *c3 = new TCanvas(name3,name3,1500,1100);
	gStyle->SetOptStat(0);
	c3->SetLogz();
	c3->SetGrid();
	f_N[0]->GetXaxis()->SetTitle("N_in");
	f_N[0]->GetYaxis()->SetTitle("f");
	c3->SetLogy();
	f_N[0]->GetXaxis()->SetNdivisions(150); 
	f_N[0]->SetMarkerColor(49);
	f_N[0]->SetLineColor(49);
	f_N[0]->SetMarkerSize(0.7);
	f_N[0]->SetMarkerStyle(20);
	f_N[0]->SetTitle(name3);
	f_N[0]->Draw("HIST PL");
	auto legend3 = new TLegend(0.1,0.1,0.2,0.9);
    	legend3->SetHeader("Isotops: ","C"); // option "C" allows to center the header
    	legend3->AddEntry(f_N[0],isotop,"p");
	for(int i=1; i<n; i++)
	{
		if(empty[i]!=1)
		{
			f_N[i]->SetMarkerColor(i%49);
			f_N[i]->SetMarkerSize(0.7);
			f_N[i]->SetLineColor(i%49);
			f_N[i]->SetMarkerStyle(20);
			f_N[i]->Draw("HIST SAME PL");

			stringstream iso1;
			iso1<<names[ZZ]<<AA[i];
			string tmp_iso1 = iso1.str();
			const char *isotop1 =(char*) tmp_iso1.c_str();
			legend3->AddEntry(f_N[i],isotop1,"p");
		}
	}	
	legend3->Draw();


}
