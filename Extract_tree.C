void Extract_tree()
{

        TChain tr1("Events");
        tr1.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_1000_20K_12.root");
        cout<<tr1.GetEntries()<<endl;
        tr1.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_2000_20K_12.root");
        cout<<tr1.GetEntries()<<endl;
        tr1.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_3000_20K_12.root");
        cout<<tr1.GetEntries()<<endl;
        tr1.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_9000_20K_12.root");
        cout<<tr1.GetEntries()<<endl;
        //tr1.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_10000_20K_12.root");
        //cout<<tr1.GetEntries()<<endl;

        TChain tr2("Events");
        tr2.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_1000_20K_8.root");
        cout<<tr2.GetEntries()<<endl;
        tr2.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_2000_20K_8.root");
        cout<<tr2.GetEntries()<<endl;
        tr2.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_3000_20K_8.root");
        cout<<tr2.GetEntries()<<endl;
        tr2.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_9000_20K_8.root");
        cout<<tr2.GetEntries()<<endl;
        //tr2.Add("RECO_RAW2DIGI_L1Reco_RECO_EI_DQM_10000_20K_8.root");


	tr1.SetBranchStatus("*",0);
	tr1.SetBranchStatus("recoCaloMETs_caloMet__reRECO.obj.m_state.p4Polar_.fCoordinates.fPt",1);

	tr2.SetBranchStatus("*",0);
	tr2.SetBranchStatus("recoCaloMETs_caloMet__reRECO.obj.m_state.p4Polar_.fCoordinates.fPt",1);


	Double_t METPt_read=0,METPt_from2;
	tr2.SetBranchAddress("recoCaloMETs_caloMet__reRECO.obj.m_state.p4Polar_.fCoordinates.fPt",&METPt_read);
	TFile *f1=new TFile("METPt_8.root","RECREATE");
	TTree *newTree = tr2.CloneTree(0);
	TBranch *b_METPt_from2=newTree->Branch("METPt_from2",&METPt_from2,"METPt_from2/F");                        


for(Int_t i=0;i<tr2.GetEntries();i++)
{
	tr2.GetEntry(i);
	//tr2.GetEntry(i);
        //METPt_from2=METPt_read;
	newTree->Fill();
}
f1->Write();
newTree->Clear();
delete f1;
}
