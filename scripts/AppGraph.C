#include "AppGraph.h"

TTree* AppGraph::ReadFile(std::string fname) { 
  TFile* f = TFile::Open(fname.c_str(), "READ");
  TTree* t = dynamic_cast<TTree*>(f->Get("t"));
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

void AppGraph::LegendStyle(TH1* hist1d1, TH1* hist1d2, TH1* hist1d3) {
  if(hist1d2 == NULL && hist1d3 == NULL) {
    TLegend *legend = new TLegend(0.8, 0.68, 0.99, 0.78);
    legend->AddEntry(hist1d1, "", "l");
    legend->SetFillColor(4);
    legend->Draw();
  } else if (hist1d3 == NULL) {
    TLegend *legend1 = new TLegend(0.8, 0.68, 0.99, 0.78);
    legend1->AddEntry(hist1d1, "", "l");
    legend1->SetFillColor(4);
    TLegend *legend2 = new TLegend(0.8, 0.55, 0.99, 0.65);
    legend2->AddEntry(hist1d2, "","l");
    legend2->SetFillColor(2);
    legend1->Draw();
    legend2->Draw("same");
  } else {
    TLegend *legend1 = new TLegend(0.8, 0.68, 0.99, 0.78);
    legend1->AddEntry(hist1d1, "", "l");
    legend1->SetFillColor(4);
    TLegend *legend2 = new TLegend(0.8, 0.55, 0.99, 0.65);
    legend2->AddEntry(hist1d2, "", "l");
    legend2->SetFillColor(2);
    TLegend *legend3 = new TLegend(0.8, 0.42, 0.99, 0.52);
    legend3->AddEntry(hist1d3, "", "l");
    legend3->SetFillColor(kGreen+1);
    legend1->Draw();
    legend2->Draw("same");
    legend3->Draw("same");
  }
}
  

void AppGraph::Histo1D(TH1* hist1d, int x, int y, std::string fname, std::string format) {
  TCanvas* c1 = new TCanvas("c1", "c1", x, y);
  c1->SetFrameLineWidth(2);
  hist1d->Draw();
  c1->Update();

  TPaveStats *st1 = (TPaveStats*)hist1d->FindObject("stats");
  hist1d->SetLineColor(kBlue+1);
  st1->SetTextColor(kBlue+1);
  st1->SetY1NDC(0.80-0.18*(1-1));
  st1->SetY2NDC(0.95-0.18*(1-1));

  hist1d->SetLabelSize(0.035, "XY");
  hist1d->SetTitleSize(0.040, "XY");

  c1->Modified();
  if(format == "") format = ".png";
  std::string fpng = fname + format;
  c1->SaveAs(fpng.c_str());
}
  
void AppGraph::Histo2D(TH2* hist2d, int x, int y, std::string fname, std::string format) {
  if(format == "") format = ".png";
  TCanvas* c1 = new TCanvas("c1", "c1", x, y);
  c1->SetFrameLineWidth(2);
  hist2d->Draw("colz");
  hist2d->SetLabelSize(0.040, "XY");
  hist2d->SetTitleSize(0.040, "XY");
  std::string fpng = fname + format;
  c1->SaveAs(fpng.c_str());
}

void AppGraph::Histo1Dx2(TH1* hist1d1, TH1* hist1d2, int x, int y, std::string fname, std::string format) {
  TCanvas* c1 = new TCanvas("c1", "c1", x, y);
  c1->SetFrameLineWidth(2);
  hist1d1->Draw();
  hist1d2->Draw("sames");
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

  hist1d1->SetLabelSize(0.035, "XY");
  hist1d1->SetTitleSize(0.040, "XY");

  c1->Modified();
  if(format == "") format = ".png";
  std::string fpng = fname + format;
  c1->SaveAs(fpng.c_str());
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
