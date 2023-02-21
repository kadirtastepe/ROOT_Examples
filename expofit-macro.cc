// This program fits data to exponential function and writes the fitted equation on the plot with variables.
#include "TStyle.h"
#include "TLatex.h"

{
gStyle->SetOptStat(0);
TFile f("file.root");
gStyle->SetTextFont(132);

TCanvas c1("c1","Histograms" ,1200,1200);
TH1F *mmass = (TH1F*)f.Get("muon_mass");

//mmass->Scale(1.0 / mmass->Integral()); //Normalize

mmass->SetMinimum(0.1); //Necessary for log-scale

//TF1 *fit = new TF1("fit", "TMath::Exp([0]+[1]*x)", 0, 120); //User defined function
TF1 *fit = new TF1("fit", "expo", 0, 120); //Predefined function

mmass-> Fit("fit","R"); // R->Range (Fits on defined range)

//GETPARAMETERS
double A = fit->GetParameter(0);
double B = fit->GetParameter(1);
std::cout <<"Check Parameters ->"<< A  << "     "<< B  <<  std::endl;


mmass->SetTitle("Exponential Fit");


c1.SetLogy(); //Log-Scale

c1.SetFrameLineColor(0);
c1.SetBottomMargin(0.16);c1.SetRightMargin(0.16); 
c1.SetLeftMargin(0.16);

mmass->Draw();
Double_t lambda = 0.5;


char eq[100];
sprintf(eq, "f(x) = e^{%2.2f + %2.2f x}",A,B);

   TLatex *text = new TLatex();
   text->SetNDC();
   text->SetTextSize(0.055);
   text->DrawLatex(0.4, 0.7, eq);

   text->SetTextSize(0.050);
   c1.Modified(); c1.Update();

c1.SaveAs("Expo-Fit.png");

} 

