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
void evenfewisotopscharts()
{

	//CHOOSE ISOTOP
	//which isotop is the goal, change ZZ and AA accordingly 
	//////////////////////////////////////////////////////////////////////////	
	//int ZZ = 13;
	//int AA = 24;
	int n =30; //ile isotopow//41
	int ZZ = 50; 
	
	int empty[n];
	int AA[n]; //= 99//-140; //41
	for(int i=0; i<n; i++)
	{
		AA[i]=i+104;
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
	
	for(int i=0; i<n; i++)
	{
		if(AA[i]% 2 == 0)
		{
			stringstream tmpfoldername;
			tmpfoldername <<"../to_the_product/ZNproduct"<<names[ZZ]<<AA[i]<<".root";
			string tmp_folder_name = tmpfoldername.str();
			const char *folder_name =(char*) tmp_folder_name.c_str();	
			TFile *file;
			cout<<"Reading File : "<<folder_name<<endl;
			cout<<endl;
			file = TFile::Open(folder_name);
			if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl; empty[i]=1;} //precaution
			else {
				cout <<"OK"<<endl;

				TH2D* hist;
				hist = (TH2D*)file->Get("Z:N")->Clone();
				//hist->Draw("colz");	
				stringstream iso;
				iso<<names[ZZ]<<AA;
				string tmp_iso = iso.str();
				const char *isotop =(char*) tmp_iso.c_str();

				f_A[i]=new TH1D(isotop, isotop, 180,80, 260);
				f_N[i] = hist->ProjectionX();
				f_Z[i] = hist->ProjectionY();
				//f_N[i]->Draw("colz");
				for(int N=0; N<150; N++)
				{
					for(int Z=1; Z<150; Z++)
					{
						
						int A = N+Z;
						int f = hist->GetBinContent(N, Z);
						f_A[i]->Fill(A, f);
						//if(f!=0)
						//	cout<<N <<" : "<< f<<endl;
					}
				}

			}
		}
		else
		{
			empty[i]=1;
		}
	}
	
	stringstream tmpname1;
	tmpname1<<names[ZZ]<<"even :f(Z_in)";
	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(11);
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
	tmpname2<<names[ZZ]<<"even :f(A_in)";
	string tmp_name2 = tmpname2.str();
	const char *name2 =(char*) tmp_name2.c_str();		

	TCanvas *c2 = new TCanvas(name2,name2,1500,1100);
	gStyle->SetOptStat(11);
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
	tmpname3<<names[ZZ]<<"even f(N_in)";

	string tmp_name3 = tmpname3.str();
	const char *name3 =(char*) tmp_name3.c_str();		

	TCanvas *c3 = new TCanvas(name3,name3,1500,1100);
	gStyle->SetOptStat(11);
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
