//3d histogram NZE

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


Int_t lightisotop[100] = {0, 1, 3, 3, 5, 6, 8, 10, 11, 13, 15, 17, 19, 21, 22, 24, 26, 28, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 48, 52, 54, 56, 58, 60, 63, 65, 67, 71, 73, 75, 77, 79, 81, 83, 85, 88, 90, 92, 94, 96, 99, 102, 104, 106, 108, 111, 113, 116, 119, 121, 124, 126, 128, 130, 133, 135, 138, 140, 142, 144, 148, 150, 153, 155, 157, 159, 161, 163, 165, 168, 170, 176, 178, 184, 186, 191, 193, 197, 201, 205, 208, 211, 215, 219, 221, 223, 231, 233, 237, 239};
Int_t heavyisotop[100] = {0, 7, 10, 13, 16, 21, 23, 25, 28, 31, 34, 39, 41, 43, 45, 47, 49, 52, 54, 59, 61, 63, 65, 67, 70, 73, 76, 78, 82, 84, 86, 88, 90, 92, 95, 98, 101, 104, 107, 109, 113, 116, 119, 122, 125, 128, 131, 133, 135, 137, 140, 142, 145, 147, 150, 152, 154, 157, 159, 161, 163, 165, 168, 170, 172, 174, 176, 178, 180, 182, 185, 188, 190, 194, 197, 199, 203, 205, 208, 210, 216, 218, 220, 224, 227, 229, 231, 233, 235, 237, 239, 241, 243, 245, 247, 249, 252, 254, 256, 258};



void single_pion()
{

  // for(int ZS=1; ZS<100; ZS++)
  // {
   // for(int AS=lightisotop[ZS]; AS<=heavyisotop[ZS]; AS++)
    //  {
         stringstream tmpname;
         tmpname <<"../B2.root";
         string tmp_name = tmpname.str();
         const char *name =(char*) tmp_name.c_str();  
         TFile *file;
         cout<<"Reading File : "<<name<<endl;
         cout<<endl;
         file = TFile::Open(name);

         if (!file || file->IsZombie()) { delete file; cout <<"There is no such isotop"<<endl; } //precaution
         else {

             TTree *tC = (TTree*)file->Get("Counter");
             Int_t fragments, electrons, pion0, pionm, pionp, kaon0, kaonp, kaonm, neutron, proton, alpha, triton, deuteron, He3, gammas, other;
             Int_t notempty =0; 
             tC->SetBranchAddress("fragments",&fragments);
             tC->SetBranchAddress("electrons",&electrons);
             tC->SetBranchAddress("pion0",&pion0);
             tC->SetBranchAddress("pion+",&pionp);
             tC->SetBranchAddress("pion-",&pionm);
             tC->SetBranchAddress("kaon0",&kaon0);
             tC->SetBranchAddress("kaon+",&kaonp);
             tC->SetBranchAddress("kaon-",&kaonm);
             tC->SetBranchAddress("gammas",&gammas);
             tC->SetBranchAddress("proton",&proton);
             tC->SetBranchAddress("neutron",&neutron);
             tC->SetBranchAddress("alpha",&alpha);
             tC->SetBranchAddress("deuteron",&deuteron);
             tC->SetBranchAddress("triton",&triton);
             tC->SetBranchAddress("He3",&He3);
             tC->SetBranchAddress("other",&other);
            
               TTree *t = (TTree*)file->Get("fNtuple");
               //creating histogram
               TH1* ZNP = new TH1D("Z:N:P", "Z:N:P", 10, 0, 10);
               TH1* ZNP0 = new TH1D("Z:N:P0", "Z:N:P0", 7, 0, 7);
               TH1* ZNPM = new TH1D("Z:N:P-", "Z:N:P-", 7, 0, 7);
               TH1* ZNPP = new TH1D("Z:N:P+", "Z:N:P+", 7, 0, 7);
               TH1* ZNK0 = new TH1D("Z:N:K0", "Z:N:K0", 10, 0, 10);
               TH1* ZNKM = new TH1D("Z:N:K-", "Z:N:K-", 10, 0, 10);
               TH1* ZNKP = new TH1D("Z:N:K+", "Z:N:K+", 10, 0, 10);
               TH1* ZNel = new TH1D("Z:N:el", "Z:N:el", 100, 0, 100);
               TH1* ZNgamma = new TH1D("Z:N:gamma", "Z:N:gamma", 100, 0, 100);
               
               TH1* ZNn = new TH1D("Z:N:n", "Z:N:n", 20, 0, 20);
               TH1* ZNp = new TH1D("Z:N:p", "Z:N:p", 20, 0, 20);
               TH1* ZNdeut = new TH1D("Z:N:deut", "Z:N:deut", 10, 0, 10);
               TH1* ZNtryt = new TH1D("Z:N:tryt", "Z:N:tryt", 10, 0, 10);
               TH1* ZNHe3 = new TH1D("Z:N:He3", "Z:N:He3", 10, 0, 10);
               TH1* ZNalpha = new TH1D("Z:N:alpha", "Z:N:alpha",20, 0, 20);
               TH1* ZNfrag = new TH1D("Z:N:frag", "Z:N:frag", 20, 0, 20);
               


               Double_t ID, Z,A, N, E, Q, T;
               Char_t name[10];
               Char_t type[10];
               t->SetBranchAddress("ID",&ID);
               t->SetBranchAddress("Z",&Z);
               t->SetBranchAddress("A",&A);
               t->SetBranchAddress("N",&N);
               t->SetBranchAddress("E",&E);
               t->SetBranchAddress("Q",&Q);
               t->SetBranchAddress("T",&T);
               t->SetBranchAddress("name",&name);
               t->SetBranchAddress("type",&type);

               Int_t nC = (Int_t)t->GetEntries();
               Int_t offset = 0;
               Int_t tmp_offset =0;

               for (Int_t i=0; i<nC; i++) 
               {
                  tC->GetEntry(i);
                  tmp_offset = electrons + fragments + proton + neutron + deuteron + triton + He3 +alpha+ other + gammas + pionm +pionp + pion0 + kaonm +kaonp + kaon0 ;

                  for(Int_t j = 0; j < tmp_offset; j++)
                  {
                     t->GetEntry(j+offset);
                     if(A>4 && Z>2 && N>=0)
                     { 
                     //if(E<100)
                      ZNP0->Fill(pionp+kaonp-pionm-kaonm);
                      ZNPP->Fill( kaonp);
                      ZNPM->Fill(kaonm);
                      ZNP->Fill(kaonm+kaon0+kaonp);


                      ZNK0->Fill( kaon0);
                      ZNKM->Fill( kaonm);
                      ZNKP->Fill( kaonp);
                      ZNgamma->Fill(gammas);
                      ZNel->Fill(electrons);
                      ZNp->Fill(proton);
                      ZNn->Fill(neutron);
                      ZNdeut->Fill(deuteron);
                      ZNtryt->Fill(triton);
                      ZNHe3->Fill(He3);
                      ZNalpha->Fill(alpha);
                      ZNfrag->Fill(fragments);
                     }

                  }
                  offset += tmp_offset;


               }
TCanvas *c2 = new TCanvas("c","c",3000,1100);
   gStyle->SetOptStat(0);
  // c2->SetLogy();
   c2->SetGrid();

              /* stringstream tmpname1;
               tmpname1 <<"I125.root";

               string tmp_name1 = tmpname1.str();
               const char *name1 =(char*) tmp_name1.c_str();

               TFile *file2 = new TFile(name1, "RECREATE");
               file2->cd();*/
               //ZNP->Draw("");
          /*     ZNp->SetLineColor(40);
               ZNp->SetFillColor(40);
               ZNp->SetBarWidth(0.14);
               ZNp->SetBarOffset(0);
               
               ZNn->SetLineColor(41);
               ZNn->SetFillColor(41);
               ZNn->SetBarWidth(0.14);
               ZNn->SetBarOffset(0.14);

               ZNdeut->SetLineColor(42);
               ZNdeut->SetFillColor(42);
               ZNdeut->SetBarWidth(0.14);
               ZNdeut->SetBarOffset(0.28);


               ZNtryt->SetLineColor(43);
               ZNtryt->SetFillColor(43);
               ZNtryt->SetBarWidth(0.14);
               ZNtryt->SetBarOffset(0.42);


               ZNHe3->SetLineColor(44);
               ZNHe3->SetFillColor(44);
               ZNHe3->SetBarWidth(0.14);
               ZNHe3->SetBarOffset(0.56);

               ZNalpha->SetLineColor(45);
               ZNalpha->SetFillColor(45);
               ZNalpha->SetBarWidth(0.14);
               ZNalpha->SetBarOffset(0.70);


               ZNfrag->SetLineColor(46);
               ZNfrag->SetFillColor(46);
               ZNfrag->SetBarWidth(0.14);
               ZNfrag->SetBarOffset(0.84);


*/
               
               //ZNgamma->Draw("b");
           /*     //ZNel->Fill(electrons);
               ZNHe3->Draw("b ");
               ZNdeut->Draw("b same");
                ZNalpha->Draw("b same");
                ZNp->Draw("b same");
                ZNn->Draw("b same");
                ZNdeut->Draw("b same");
                ZNtryt->Draw("b same");
                ZNHe3->Draw("b same");
                
                ZNfrag->Draw("b same");
               
               auto legend2 = new TLegend(0.8,0.5,0.9,0.8);
          legend2->SetHeader("Legend","C"); 
          legend2->AddEntry(ZNp, "protons","f");
          legend2->AddEntry(ZNn, "neutrons","f");
          legend2->AddEntry(ZNdeut, "deuters","f");
          legend2->AddEntry(ZNtryt, "tryts","f");
          legend2->AddEntry(ZNHe3, "He3","f");
          legend2->AddEntry(ZNalpha, "alpha","f");
          legend2->AddEntry(ZNfrag, "nuclear fragments","f");
         
          legend2->Draw();
*/

               /*               ZNP0->Write();
               ZNPP->Write();
               ZNPM->Write();
               ZNK0->Write();
               ZNKP->Write();
               ZNKM->Write();
               ZNel->Write();
               ZNgamma->Write();
               ZNn->Write();
               ZNp->Write();
               ZNdeut->Write();
               ZNtryt->Write();
               ZNHe3->Write();
               ZNalpha->Write();
               ZNfrag->Write();
               file2->Write();*/

            }



      }
   //}

//}
