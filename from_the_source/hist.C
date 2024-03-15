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
	int ZZ = 50;
	int AA = 100;
	//////////////////////////////////////////////////////////////////////////
	//which isotop is the goal, change ZZ and AA accordingly 
	stringstream tmpname;
	tmpname <<"target"<<names[ZZ]<<AA<<".root";
	string tmp_name = tmpname.str();
	const char *name =(char*) tmp_name.c_str();  
	TFile *file;
	file = TFile::Open(name);
	if (!file || file->IsZombie()) { delete file; 
		cout <<"There is no such isotop "<<names[ZZ]<<AA<<endl;} //precaution
	else {
		cout<<"This isotop "<<names[ZZ]<<AA<<"produces this isotops: "<<endl;

		TH3D *hist3D;
		hist3D = (TH3D*)file->Get("Z:N")->Clone();
		//TH2D * hist;
		TH2D *hist = new TH2D("hist2D", "Z vs N for Energy < 100", hist3D->GetNbinsX(), hist3D->GetXaxis()->GetXmin(), hist3D->GetXaxis()->GetXmax(), hist3D->GetNbinsY(), hist3D->GetYaxis()->GetXmin(), hist3D->GetYaxis()->GetXmax());

		//hist = hist3D->Project3DProfile("xy");

		for (int zbin = 0; zbin < 150; zbin++) {
		    for (int nbin = 0; nbin < 150; nbin++) {
		        for (int ebin = 0; ebin < 800; ebin++) {
		            // Check if the energy value is less than 100
		            if (hist3D->GetZaxis()->GetBinCenter(ebin) < 1) {
		                // Fill the 2D histogram with Z and N values
		                hist->Fill(zbin-1, nbin-1, hist3D->GetBinContent(zbin+1, nbin+1, ebin));
		            }
		        }
		    }
		}



		TCanvas *c = new TCanvas(name,name,1500,1100);
		gStyle->SetOptStat(11);
		c->SetLogz();
		c->SetGrid();
		hist->GetXaxis()->SetTitle("N.");
		hist->GetYaxis()->SetTitle("Z.");
		hist->GetXaxis()->SetNdivisions(150); 
		hist->GetYaxis()->SetNdivisions(150); 
		hist->SetTitle(name);
		hist->Draw("colz");
		gPad->Update();
		//TPaveStats *st = (TPaveStats*)hist->FindObject("stats");
	}
}
