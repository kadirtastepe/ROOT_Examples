#include "TStyle.h"


void allinoneplot(){

gStyle->SetTextFont(132);
TCanvas *c1 = new TCanvas("c1","",1600,1200);


const int n_points = 15;

double R[n_points] = {0.00E+00, 3.25E-01, 9.74E-01, 1.95E+00, 
2.60E+00, 3.57E+00, 7.47E+00, 1.23E+01, 1.72E+01, 2.21E+01, 2.70E+01, 
3.18E+01, 3.67E+01, 4.16E+01, 4.65E+01};

double V_obs[n_points] = {0.00E+00, 9.00E+01, 1.25E+02, 1.48E+02, 1.80E+02, 2.01E+02, 2.06E+02, 2.14E+02, 
2.12E+02, 2.13E+02, 2.14E+02, 2.13E+02, 2.13E+02, 2.03E+02, 1.98E+02};
double y_err[n_points] = {0.00E+00, 2.00E+01, 1.50E+01, 1.50E+01, 1.70E+01, 1.50E+01, 1.00E+01, 5.00E+00, 
5.00E+00, 2.00E+00, 2.00E+00, 2.00E+00, 3.00E+00, 3.00E+00, 5.00E+00};


double V_disk[n_points] = {0.00E+00, 2.27E+01, 2.76E+01, 2.60E+01, 5.48E+01, 8.93E+01, 1.15E+02, 1.24E+02, 
1.25E+02, 1.13E+02, 1.05E+02, 9.06E+01, 8.24E+01, 7.65E+01, 7.18E+01};

double V_gas[n_points]={0.00E+00, 0.00E+00, 6.53E-01, 2.64E+00, 4.00E+00, 6.17E+00, 1.67E+01, 3.18E+01, 
4.44E+01, 5.20E+01, 5.79E+01, 6.34E+01, 6.55E+01, 6.39E+01, 6.25E+01};

double V_bulge[n_points] = {0.00E+00, 5.71E+01, 1.26E+02, 1.61E+02, 1.67E+02, 1.64E+02, 1.29E+02, 1.01E+02, 
8.56E+01, 7.55E+01, 6.84E+01, 6.29E+01, 5.86E+01, 5.51E+01, 5.21E+01};


auto graph = new TGraphErrors(n_points, R, V_obs, nullptr, y_err);
//auto graph1 = new TGraph(n_points, x_val, y_val);
graph->Draw("ACP");
//graph->Draw("AC*");
graph->SetMarkerColor(kRed);
graph->SetLineColor(kRed);
graph->SetMarkerStyle(20);
graph->SetLineWidth(3.);
graph->GetXaxis()->SetTitle("Radius[kpc]");
graph->GetYaxis()->SetTitle("Velocity[km/s]");
graph->SetTitle("NGC2998");
///////////////////////////////////////////////////////////////////////

auto graph1 = new TGraph(n_points, R, V_disk);
//auto graph1 = new TGraph(n_points, x_val, y_val);
graph1->Draw("SameCP");
//graph->Draw("sameAC*");
graph1->SetMarkerColor(kBlue);
graph1->SetLineColor(kBlue);
graph1->SetLineWidth(3.);
graph1->SetMarkerStyle(21);



////////////////////////////////////////////////////////////////////////

auto graph2 = new TGraph(n_points, R, V_gas);
//auto graph1 = new TGraph(n_points, x_val, y_val);
graph2->Draw("SameCP");
//graph->Draw("AC*");
graph2->SetMarkerColor(kGreen+1);
graph2->SetLineColor(kGreen+1);
graph2->SetMarkerStyle(22);
graph2->SetLineWidth(3.);



////////////////////////////////////////////////////////////////////////

auto graph3 = new TGraph(n_points, R, V_bulge);
//auto graph1 = new TGraph(n_points, x_val, y_val);
graph3->Draw("SameCP");  
//graph->Draw("AC*");
graph3->SetMarkerColor(kOrange+1); 
graph3->SetLineColor(kOrange+1);
graph3->SetMarkerStyle(23);
graph3->SetLineWidth(3.);


graph->GetYaxis()->SetRangeUser(-20., 240.);


auto legend = new TLegend(0.84,0.45,0.90,0.6);

legend->AddEntry(graph, "V_{obs}");
legend->AddEntry(graph1, "V_{disk}");
legend->AddEntry(graph2, "V_{gas}");
legend->AddEntry(graph3, "V_{bulge}");



legend->Draw();


double size = 1.5;
graph->SetMarkerSize(size);
graph1->SetMarkerSize(size);
graph2->SetMarkerSize(size);
graph3->SetMarkerSize(size);









c1->Draw();
c1->SaveAs("oneplot.png");


}

