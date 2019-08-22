void scanTree()
{
TFile *f = new TFile("METPt_8.root");
TTree *t = (TTree*)f->Get("Events");
        t->SetBranchStatus("*",0);
        t->SetBranchStatus("recoCaloMETs_caloMet__reRECO.obj.m_state.p4Polar_.fCoordinates.fPt",1);

t->SetScanField(0);     
t->Scan("recoCaloMETs_caloMet__reRECO.obj.m_state.p4Polar_.fCoordinates.fPt");


}
