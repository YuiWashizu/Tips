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
 public:
  TTree* ReadFile(std::string fname);
  TFile* OutputFile(std::string fname);
  void Style();
  void LegendStyle(TH1* hist1d1, TH1* hist1d2, TH1* hist1d3);
  void Histo1D(TH1* hist1d, int x, int y, std::string fname, std::string format);
  void Histo2D(TH2* hist2d, int x, int y, std::string fname, std::string format);
  void Histo1Dx2(TH1* hist1d1, TH1* hist1d2, int x, int y, std::string fname, std::string format);
  void Histo1Dx3(TH1* hist1d1, TH1* hist1d2, TH1* hist1d3, int x, int y, std::string fname, std::string format);
 private:
  TFile f;
  TFile fout;
  TTree t;
  int linewd;
  int fontid;
};

#endif //_APPGRAPH_H_
	      
