//TGraph data entry by hand
#include "TStyle.h"


void TGraph(){

gStyle->SetTextFont(132);
TCanvas *c1 = new TCanvas("c1","",1600,1200);

const int n_points = 15;

double data_x[n_points] = {};
double data_y[n_points] = {};

auto graph = new TGraphErrors(n_points, data_x, data_y, nullptr, nullptr);
//auto graph1 = new TGraph(n_points, x_val, y_val);
graph->Draw("ACP");
//graph->Draw("AC*");
graph->SetMarkerColor(kRed);
graph->SetLineColor(kRed);
graph->SetMarkerStyle(20);
graph->SetLineWidth(3.);
graph->GetXaxis()->SetTitle("X_label");
graph->GetYaxis()->SetTitle("Y_label");
graph->SetTitle("Title");


graph->GetYaxis()->SetRangeUser(-20., 240.);


auto legend = new TLegend(0.84,0.45,0.90,0.6);

legend->AddEntry(graph, "data");
legend->Draw();


double size = 1.5;
graph->SetMarkerSize(size);

c1->Draw();
c1->SaveAs("plot.png");


}

