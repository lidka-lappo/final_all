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

Int_t lightisotop[100] = {0, 1, 3, 4, 6, 7, 8, 10, 11, 14, 15, 17, 19, 21, 22, 25, 26, 29, 30, 33, 34, 38, 38, 42, 42, 44, 45, 50, 48, 53, 54, 59, 59, 63, 64, 69, 69, 73, 73, 76, 77, 81, 81, 85, 85, 89, 90, 92, 94, 96, 99, 103, 104, 108, 108, 112, 114, 117, 121, 121, 125, 128, 129, 130, 134, 135, 139, 140, 143, 144, 149, 150, 151, 155, 157, 159, 161, 164, 166, 170, 171, 176, 178, 184, 186, 191, 193, 197, 201, 205, 208, 211, 215, 219, 228, 223, 233, 233, 237, 240};
Int_t heavyisotop[100] = {0, 7, 10, 12, 16, 21, 22, 24, 26, 31, 34, 37, 40, 43, 44, 46, 48, 51, 53, 56, 58, 61, 64, 67, 70, 73, 75, 77, 82, 82, 85, 87, 90, 92, 95, 101, 102, 106, 108, 111, 114, 117, 119, 122, 125, 128, 131, 132, 134, 137, 140, 142, 145, 147, 150, 152, 154, 157, 158, 161, 163, 165, 168, 169, 172, 174, 176, 178, 180, 181, 185, 188, 190, 194, 197, 199, 203, 205, 208, 210, 216, 217, 220, 224, 227, 229, 229, 233, 234, 236, 238, 239, 243, 252, 252, 252, 252, 253, 256, 257};

struct NucleusData {
    int mass_number;
    int proton_number;
    std::string isotope_name;
    double mass_mev;
    double binding_energy_mev;
    double binding_energy_per_nucleus_mev;
};

double CalculateBindingEnergyPerNucleus(const std::vector<NucleusData>& data, int A, int Z) {
    double binding_energy_per_nucleus = 0.0;

    for (const NucleusData& nucleus : data) {
        if (nucleus.mass_number == A && nucleus.proton_number == Z) {
            binding_energy_per_nucleus = nucleus.binding_energy_per_nucleus_mev;
            break;
        }
    }

    if (binding_energy_per_nucleus > 0.0) {
        //std::cout << "Binding Energy per Nucleus for A = " << A << " and Z = " << Z << ": " << binding_energy_per_nucleus << " MeV" << std::endl;
    	return binding_energy_per_nucleus;
    } else {
       // std::cout << "Nucleus with A = " << A << " and Z = " << Z << " not found in the data." << std::endl;
    	return -1;
    }
}




void binding_energy()
{
	std::ifstream data_file("data.txt");
    if (!data_file.is_open()) {
        std::cerr << "Error: Unable to open data file." << std::endl;
        return 1;
    }

    std::vector<NucleusData> data;
    std::string line;
    while (std::getline(data_file, line)) {
        std::istringstream iss(line);
        NucleusData nucleus;
        iss >> nucleus.mass_number >> nucleus.proton_number >> nucleus.isotope_name >> nucleus.mass_mev >> nucleus.binding_energy_mev >> nucleus.binding_energy_per_nucleus_mev;
        data.push_back(nucleus);
    }
    data_file.close();

    //int A = 3;  // Set the desired mass number A
    //int Z = 2;  // Set the desired proton number Z

    //int x = CalculateBindingEnergyPerNucleus(data, A, Z);

	///CHOOSE ISOTOP
	//which isotop is the goal, change ZZ and AA accordingly 
	//////////////////////////////////////////////////////////////////////////	
	//int ZZ = 13;
	//int AA = 24;
	TH1D *f_A=new TH1D("Binding Energy", "Binding Energy", 1000, 7.5, 9.5);
	//int AA = 24;
	//int ZZ = 13;
	int OUT = 0;
	for(int ZZ=1; ZZ<25; ZZ++)
	{
		for(int AA=lightisotop[ZZ]; AA<=heavyisotop[ZZ]; AA++)
		{

			//change 0 if IN, 1 if OUT
			//////////////////////////////////////////////////////////////////////////
			

			stringstream tmpname;
			if(OUT)
				tmpname <<"../to_the_product/ZNproduct"<<names[ZZ]<<AA<<".root";
			else
				tmpname <<"../from_the_source/target"<<names[ZZ]<<AA<<".root";
			string tmp_name = tmpname.str();
			const char *name =(char*) tmp_name.c_str();	
			TFile *file;
			cout<<"Reading File : "<<name<<endl;
			cout<<endl;
			file = TFile::Open(name);
			if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl; } //precaution
			else 
			{
				cout <<"OK"<<endl;
				TH2D * hist;
				hist = (TH2D*)file->Get("Z:N")->Clone();

				for(int Z=1; Z<100; Z++)
				{
					for(int A=lightisotop[Z]; A<=heavyisotop[Z]; A++)
					{

						int N = A-Z;
						int f = hist->GetBinContent(N, Z);
						f_A->Fill(CalculateBindingEnergyPerNucleus(data, A, Z), f);
						
					}
				}
				delete hist;
			}

		}
	}

	stringstream tmpname1;
	if(OUT)
		tmpname1<<"Out:Freq(E(Z_in, A_in)).root";
	else
		tmpname1<<"In: Freq(E(Z_out, A_0ut)).root";

	string tmp_name1 = tmpname1.str();
	const char *name1 =(char*) tmp_name1.c_str();	

	TCanvas *c = new TCanvas(name1,name1,1500,1100);
	gStyle->SetOptStat(11);
	//c->SetLogz();
	c->SetGrid();
	if(OUT)
		f_A->GetXaxis()->SetTitle("E(A_in, Z_in)");
	else
		f_A->GetXaxis()->SetTitle("E(A_out, Z_out)");
	f_A->GetYaxis()->SetTitle("f");
	c->SetLogy();
	f_A->GetXaxis()->SetNdivisions(1000); 
	f_A->SetMarkerColor(2);
	f_A->SetMarkerSize(1.5);
	f_A->SetMarkerStyle(20);
	f_A->SetTitle(name1);
	f_A->Draw("HIST P");

	TFile *file1 = new TFile(name1, "RECREATE");
	file1->cd();
	f_A->Write();
	file1->Write();




}
