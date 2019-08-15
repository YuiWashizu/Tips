#ifndef _APPGRAPH_H_
#define _APPGRAPH_H_

#include "TTree.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TPaveStats.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class AppGraph {
 private:
  TFile f;
  TFile fout;
  TTree t;
  int linewd;
  int fontid;
 public:
  TTree* ReadFile(std::string fname, std::string tree);
  TFile* OutputFile(std::string fname);
  void Style();
  void AddLegend(TH1* hist1d1);
  TCanvas* Hist1d(TH1* hist1d, int x, int y);
  void AddHist1d(TCanvas* c1, TH1* hist1d);
  void AddStats(TCanvas* c1, TH1* hist1d, int i);
  void AddText(std::string text, int color);
  void SaveAs(TCanvas* c1, std::string fname, std::string format);
  TCanvas* Hist2d(TH2* hist2d, int x, int y);
  void Histo1Dx3(TH1* hist1d1, TH1* hist1d2, TH1* hist1d3, int x, int y, std::string fname, std::string format);
};

#endif //_APPGRAPH_H_
	      
