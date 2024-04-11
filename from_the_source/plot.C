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
void plot()
{
	//CHOOSE ISOTOP
	//////////////////////////////////////////////////////////////////////////	
	int ZZ = 90;
	int AA = 229;
	//////////////////////////////////////////////////////////////////////////
	//which isotop is the goal, change ZZ and AA accordingly 
	stringstream tmpname;
	tmpname <<"2Dfragments"<<names[ZZ]<<AA<<".root";
	string tmp_name = tmpname.str();
	const char *name =(char*) tmp_name.c_str();  
	TFile *file;
	file = TFile::Open(name);
	if (!file || file->IsZombie()) { delete file; 
		cout <<"There is no such isotop "<<names[ZZ]<<AA<<endl;} //precaution
	else {
		cout<<"This isotop "<<names[ZZ]<<AA<<"produces this isotops: "<<endl;

		TH2D *hist;
		hist = (TH2D*)file->Get("hist2D")->Clone();
		//TH2D * hist;
		//TH2D *hist = new TH2D("hist2D", "Z vs N for Energy < 100", hist3D->GetNbinsX(), hist3D->GetXaxis()->GetXmin(), hist3D->GetXaxis()->GetXmax(), hist3D->GetNbinsY(), hist3D->GetYaxis()->GetXmin(), hist3D->GetYaxis()->GetXmax());

		stringstream tmpname1;
       tmpname1 <<"Fragments from " <<names[ZZ]<<AA<<" target";

       string tmp_name1 = tmpname1.str();
       const char *name1 =(char*) tmp_name1.c_str();

		TCanvas *c = new TCanvas(name1,name1,1500,1100);
		gStyle->SetOptStat(0);
		c->SetLogz();
		c->SetGrid();
		hist->GetXaxis()->SetTitle("N.");
		hist->GetYaxis()->SetTitle("Z.");

		int bottomX = 110;
		int bottomY = 76;

		hist->GetXaxis()->SetRangeUser(bottomX, AA-ZZ+1);
		hist->GetYaxis()->SetRangeUser(bottomY, ZZ+1);

		hist->GetXaxis()->SetNdivisions(AA-ZZ+1-bottomX); 
		hist->GetYaxis()->SetNdivisions(ZZ+1-bottomY); 
		hist->SetTitle(name1);
		hist->Draw("colz");
		gPad->Update();
		TPaveStats *st = (TPaveStats*)hist->FindObject("stats");
	}
}
