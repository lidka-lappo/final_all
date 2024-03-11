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
void hist()
{
	//CHOOSE ISOTOP
	//////////////////////////////////////////////////////////////////////////	
	int ZZ = 38;
	int AA = 105;
	//////////////////////////////////////////////////////////////////////////
	//which isotop is the goal, change ZZ and AA accordingly 
	stringstream tmpname;
	tmpname <<"../from_the_target/target"<<names[ZZ]<<AA<<".root";
	string tmp_name = tmpname.str();
	const char *name =(char*) tmp_name.c_str();  
	TFile *file;
	file = TFile::Open(name);
	if (!file || file->IsZombie()) { delete file; 
		cout <<"There is no such isotop "<<names[ZZ]<<AA<<endl;} //precaution
	else {
		cout<<"This isotop "<<names[ZZ]<<AA<<"produces this isotops: "<<endl;
	    TH2D* hist;
	    hist = (TH2D*)file->Get("N:Z")->Clone();;


		TCanvas *c = new TCanvas(name,name,1500,1100);
		gStyle->SetOptStat(11);
		c->SetLogz();
		c->SetGrid();
		hist->GetXaxis()->SetTitle("Z.");
		hist->GetYaxis()->SetTitle("N.");
		hist->GetXaxis()->SetNdivisions(150); 
		hist->GetYaxis()->SetNdivisions(150); 
		hist->SetTitle(name);
		hist->Draw("colz");
		gPad->Update();
		//TPaveStats *st = (TPaveStats*)hist->FindObject("stats");
	}
}
