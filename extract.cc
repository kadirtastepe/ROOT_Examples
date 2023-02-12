// Extracts trees under a directory in a root file and saves it as a PDF.
{
TFile f("file.root");
TTree*tree=(TTree*)f.Get("alignment/sensors");
TCanvas c1("c1","Histograms" ,1600,1200);
c1.SaveAs("plots.pdf[");

tree->Draw("vx >> avx");

TFile *fout = new TFile("my.root" , "recreate");
fout->cd();
//vx
avx->Print();
avx->Write();
c1.SaveAs("plots.pdf");


c1.SaveAs("plots.pdf]");
fout->Close();

}
