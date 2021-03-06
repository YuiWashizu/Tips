#include "AppGraph.h"

TTree* AppGraph::ReadFile(std::string fname, std::string tree) { 
  TFile* f = TFile::Open(fname.c_str(), "READ");
  TTree* t = dynamic_cast<TTree*>(f->Get(tree.c_str()));
  return t;
}

TFile* AppGraph::OutputFile(std::string fname) {
  std::string fout_name = fname + "out.root";
  TFile* fout = TFile::Open(fout_name.c_str(), "RECREATE");
  return fout;
  //need fout->Write() at End
}


void AppGraph::Style() {
  int linewd = 2;
  int fontid = 42;
 
  gStyle->SetPalette(55);
  gStyle->SetLineWidth(linewd);
  gStyle->SetGridWidth(linewd);
  gStyle->SetHistLineWidth(linewd);

  gStyle->SetTitleSize(10);
  gStyle->SetStatFont(fontid);
  gStyle->SetLabelFont(fontid, "XYZ");
  gStyle->SetTitleFont(fontid, "XYZ");
  gStyle->SetTextFont(fontid);
  gStyle->SetLegendFont(fontid);
}

void AppGraph::AddLegend(TH1* hist1d1) {
    TLegend *legend = new TLegend(0.8, 0.68, 0.99, 0.78);
    legend->AddEntry(hist1d1, "", "l");
    legend->SetFillColor(4);
    legend->Draw();
}  

TCanvas* AppGraph::Hist1d(TH1* hist1d, int x, int y) {
  TCanvas* c1 = new TCanvas("c1", "c1", x, y);
  c1->SetFrameLineWidth(2);
  hist1d->SetLabelSize(0.035, "XY");
  hist1d->SetTitleSize(0.040, "XY");
  hist1d->Draw();
  c1->Update();
  return c1;
}


void AppGraph::AddHist1d(TCanvas* c1, TH1* hist1d) {
  hist1d->Draw("sames");
  c1->Update();
}

void AppGraph::AddStats(TCanvas* c1, TH1* hist1d, int i) {
  // i is which number of stats.
  TPaveStats *st1 = (TPaveStats*)hist1d->FindObject("stats");
  if (i == 1) {
    hist1d->SetLineColor(kBlue+1);
    st1->SetTextColor(kBlue+1);
  } if (i == 2) {
    hist1d->SetLineColor(kRed+1);
    st1->SetTextColor(kRed+1);
  } if (i == 3) {
    hist1d->SetLineColor(kGreen+1);
    st1->SetTextColor(kGreen+1);
  }
  st1->SetY1NDC(0.80-0.18*(i-1));
  st1->SetY2NDC(0.95-0.18*(i-1));
  c1->Modified();
}

void AppGraph::AddText(std::string text, int color) {
  TLegend* leg = new TLegend(0.78, 0.10, 0.95, 0.20);
  leg->AddEntry((TObject*)0, text.c_str(), "");
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);
  leg->SetTextColor(color);
  leg->Draw("same");
}


void AppGraph::SaveAs(TCanvas* c1, std::string fname, std::string format) {
  if(format == "") format = ".png";
  std::string fpng = fname + format;
  c1->SaveAs(fpng.c_str());
}
  
TCanvas* AppGraph::Hist2d(TH2* hist2d, int x, int y){
  TCanvas* c1 = new TCanvas("c1", "c1", x, y);
  c1->SetFrameLineWidth(2);
  hist2d->SetLabelSize(0.040, "XY");
  hist2d->SetTitleSize(0.040, "XY");
  hist2d->Draw("colz");
  return c1;
}

void AppGraph::Histo1Dx3(TH1* hist1d1, TH1* hist1d2, TH1* hist1d3, int x, int y, std::string fname, std::string format) {
  TCanvas* c1 = new TCanvas("c1", "c1", x, y);
  c1->SetFrameLineWidth(2);
  hist1d1->Draw();
  hist1d2->Draw("sames");
  hist1d3->Draw("sames");
  c1->Update();

  TPaveStats *st1 = (TPaveStats*)hist1d1->FindObject("stats");
  hist1d1->SetLineColor(kBlue+1);
  st1->SetTextColor(kBlue+1);
  st1->SetY1NDC(0.80-0.18*(1-1));
  st1->SetY2NDC(0.95-0.18*(1-1));
  TPaveStats *st2 = (TPaveStats*)hist1d2->FindObject("stats");
  hist1d2->SetLineColor(kRed+1);
  st2->SetTextColor(kRed+1);
  st2->SetY1NDC(0.80-0.18*(2-1));
  st2->SetY2NDC(0.95-0.18*(2-1));
  TPaveStats *st3 = (TPaveStats*)hist1d3->FindObject("stats");
  hist1d3->SetLineColor(kGreen+1);
  st3->SetTextColor(kGreen+1);
  st3->SetY1NDC(0.80-0.18*(3-1));
  st3->SetY2NDC(0.95-0.18*(3-1));

  hist1d1->SetLabelSize(0.035, "XY");
  hist1d1->SetTitleSize(0.040, "XY");

  c1->Modified();
  if(format == "") format = ".png";
  std::string fpng = fname + format;
  c1->SaveAs(fpng.c_str());
}
