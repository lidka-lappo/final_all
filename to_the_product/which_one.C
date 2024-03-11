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

int check(int Z, int A)
{
    std::vector<TString> isotops;
	fstream myfile;
	//myfile.open("isotopes.txt", ios::in);
	myfile.open("../stable_longlivedisotopes.txt", ios::in);
	TString element;
	int is_stable =0;
	while(!myfile.eof())
	{
		//TString isotop;
		TString tmp;
		myfile>>tmp;
		
		if(!strcmp(tmp, names[Z]))
		{
			myfile>>tmp;
			while((tmp.IsFloat()))
			{
				//cout <<tmp <<endl;
				if(atoi(tmp) == A )
					{ is_stable =1;}
				myfile>>tmp;
			}
		}


	}
	myfile.close();	
	return is_stable;
}



int to_stable(	int ZZ, int AA, vector<vector<Int_t>> &listZ, vector<vector<Int_t>> &listA, vector<vector<Double_t>> &listFreq)
{

	std::vector<Int_t> tmplistZ;
	std::vector<Int_t> tmplistA;
	std::vector<Double_t> tmplistFreq;
    stringstream tmpname;
	tmpname <<"ZNproduct"<<names[ZZ]<<AA<<".root";
	string tmp_name = tmpname.str();
	const char *name =(char*) tmp_name.c_str();  
	TFile *file;
	file = TFile::Open(name);
	if (!file || file->IsZombie()) { delete file; 
		cout <<"There is no such isotop "<<names[ZZ]<<AA<<endl;
		return 0; } //precaution
	else {
		//cout<<"This isotop "<<names[ZZ]<<AA<<" is producet from isotop: "<<endl;
	    TH2D* hist;
	    hist = (TH2D*)file->Get("N:Z")->Clone();;
	    Int_t MaxBin;
   		Int_t N,Z,x;
   		Double_t f;
   		MaxBin = hist->GetMaximumBin();
   		hist->GetBinXYZ(MaxBin, Z, N, x);
   		f = hist->GetBinContent(MaxBin);
   		f = f/1000000.0;
   		//cout<<f<<endl;
   		
   		//cout<<i<<") "<<names[Z]<<(N+Z)<<" with frequency "<<f<<endl;
   		tmplistZ.push_back(Z);
   		tmplistA.push_back(Z+N);
   		tmplistFreq.push_back(1.0*f);
		hist->SetBinContent( Z,N,0);
   		while(!check(Z,(Z+N)))
   		{
	   		MaxBin = hist->GetMaximumBin();
	   		hist->GetBinXYZ(MaxBin, Z, N, x);
	   		f = hist->GetBinContent(MaxBin);
	   		if(f==0)
	   		{
	   			cout<<"No production from stable isotop"<<endl;
	   			break;
	   		}
	   		//cout<<i<<") "<<names[Z]<<(N+Z)<<" with frequency "<<f<<endl;
			tmplistZ.push_back(Z);
			tmplistA.push_back(Z+N);
			f = f/1000000.0;
   			//cout<<f<<endl;
			tmplistFreq.push_back(f);
   			hist->SetBinContent( Z,N,0);
   		}

   		//cout<<names[Z]<<(N+Z)<<" is stable isotop" <<endl;
	    listZ.push_back(tmplistZ);
   		listA.push_back(tmplistA);
   		listFreq.push_back(tmplistFreq);
	    delete hist;    
	    delete file;
	    
	    return 1;
	 }


}


void which_one()
{

	/*215At,216At,217At 85
	216Rn, 217Rn 218Rn 86
	217Fr,218Fr,219Fr 87
	217Ra, 218Ra, 219Ra 220Ra 225Ra 88
	221Pa, 222Pa, 223Pa 229Pa 91
	222U, 223U, 224U  225U 92
	50Co,51Co or 52Co 27
	229Th 90*/

	int ZZ =30; 
	int AA=69; 
    stringstream tmpname1;
    tmpname1 <<names[ZZ]<<AA<<"chains_of_production.txt";
    string tmp_name1 = tmpname1.str();
    const char *name1 =(char*) tmp_name1.c_str(); 

    fstream myfile;
	myfile.open(name1, ios::out);
	myfile<<"Direct production: "<<endl;
	myfile<<names[ZZ]<<AA;

	cout<<"Direct production: "<<endl;
	cout<<names[ZZ]<<AA;

	myfile<<names[ZZ]<<AA;
	cout<<names[ZZ]<<AA;
	std::vector<vector<Int_t>> listZ;
	std::vector<vector<Int_t>> listA;
	std::vector<vector<Double_t>> listFreq;


	Double_t f =1;
	int i=0;
	int j=0;
	int no_route =0;
	int effective =1;

	if(to_stable(ZZ, AA, listZ, listA, listFreq))
	{
		int s =listFreq.at(0).size()-1;
		int f_direct=listFreq.at(0).at(s);

		myfile<<" <- "<<names[listZ.at(0).at(s)]<<listA.at(0).at(s)<<" with frequency "<<f_direct<<endl;
		cout<<" <- "<<names[listZ.at(0).at(s)]<<listA.at(0).at(s)<<" with frequency "<<f_direct<<endl;

		myfile<<"Other possible routes: "<<endl;
		myfile<<names[ZZ]<<AA;

		cout<<"Other possible routes: "<<endl;
		cout<<names[ZZ]<<AA;

		f=f*listFreq.at(0).at(0);	
		ZZ = listZ.at(0).at(0);
		AA = listA.at(0).at(0);

		myfile<<" <- "<<names[ZZ]<<AA;

		cout<<" <- "<<names[ZZ]<<AA;
		
		while(!check(ZZ, AA))
		{

			if(to_stable(ZZ, AA, listZ, listA, listFreq))
			{

				i++;
				f=f*listFreq.at(i+no_route).at(j);	
				if(f<f_direct)
				{
					myfile<<" with frequency: "<<f<<endl;
					myfile<<"Not efective chain"<<endl;

					cout<<" with frequency: "<<f<<endl;
					cout<<"Not efective chain"<<endl;
					no_route +=1;
					continue;
				}	
				ZZ = listZ.at(i+no_route).at(j);
				AA = listA.at(i+no_route).at(j);
				myfile<<" <- "<<names[ZZ]<<AA;
				cout<<" <- "<<names[ZZ]<<AA;
				j=0;


			}
			else
			{
				j++;
				if(j<listZ.at(i+no_route).size())
				{
					ZZ = listZ.at(i+no_route).at(j);
	    			AA = listA.at(i+no_route).at(j);
	    			cout<<"j= "<<j<<endl;
	    		}
	    		else
	    		{
	   				j=1;
	   				myfile<<endl;
	    			myfile<<"This isotop is imposible to produce"<<endl;
	    			break;

	    		}	

			}
			
		
		}
		if(f!=1){
			myfile<<" with frequency: "<<f<<endl;
			cout<<" with frequency: "<<f<<endl;
			int s =listFreq.at(0).size()-1;
			if(f<listFreq.at(0).at(s))
			{
				myfile<<"Not efective chain"<<endl;
				cout<<"Not efective chain"<<endl;
			}
			else
			{
				myfile<<"effective chain"<<endl;
				cout<<"effective chain"<<endl;
			}
		}
		else
		{
			myfile<<" is stable isotop "<<endl;
			cout<<" is stable isotop "<<endl;

		}

		myfile.close();
	}
	else
	{
		cout<<"Isotop "<<names[ZZ]<<AA<<" isn't produced"<<endl;
	}

}
