#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <sstream>
#include <TF1.h>
#include <TTree.h>
#include <TStyle.h>
#include <TText.h>
#include <unistd.h>
#include <TGraphErrors.h>
#include <TROOT.h>
#include <TChain.h>

using namespace std;

void check_30ch(int filenum_i, int filenum_n) {

  TString name;
  name.Form("canv.pdf");
  TCanvas* c = new TCanvas(name.Data(),name.Data(), 900, 900);
  c->Print(name + "[", "pdf");

  for (int filenum=filenum_i; filenum<filenum_n; filenum++) {
    int i = filenum-filenum_i+1;
    TH1D* adc_hist = new TH1D("adc_hist", "adc_hist", 400, 700, 1100);

    TFile* f = TFile::Open(Form("./sc2018_data8.7/sc0%d.root", filenum));
    TTree* t = dynamic_cast<TTree*>(f->Get("tree"));
    int adc[32];
    t->SetBranchAddress("adc", &adc);
    int nevent = t->GetEntries();
  
    for (int event=0; event<nevent; event++) {
      t->GetEntry(event);
      adc_hist->Fill(adc[30]);
    }
    adc_hist->Draw();    
    c->Print(name, "pdf");
  }
  c->Print(name + "]", "pdf");
}
    
