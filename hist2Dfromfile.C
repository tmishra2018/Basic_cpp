void hist2Dfromfile()
{
	FILE *fp_12, *fp_8;
	int i,n;
	int numChars = 0; // number of all symbols
	int numLines = 0; // number of all lines
	char buff[512];//array for symbols input
	size_t num;


	char filename_12[15] = "METPt_12.txt";
	char filename_8[15] = "METPt_8.txt";


	fp_12 = fopen(filename_12,"r");
	fp_8 = fopen(filename_8,"r");

	if (fp_8 == 0) 
	{
		printf("Unable to open file. Terminating...\n");
		exit(1);
	}
	while ((num = fread(buff,1,512,fp_8)) > 0) 
	{
		for (i=0;i<num;++i)
		{
			if (buff[i] == '\n')
			{
				++numLines;
			}
		}
	}
	fclose(fp_8);

        cout<<"No. of lines"<<numLines<<endl;
	const int numL = numLines;
	float x[numL];
	float y[numL];

	float a[numL];
	float b[numL];

	fp_8 = fopen(filename_8,"r");
	for(i=0;i<numL;i++)
	{
		fscanf(fp_8,"%f %f",&a[i],&b[i]);

	}
	fclose(fp_8);

	
	fp_12 = fopen(filename_12,"r");
	for(i=0;i<numL;i++)
	{
		fscanf(fp_12,"%f %f",&x[i],&y[i]);
	}
	fclose(fp_12);


	printf("Done! Checking:\n");


	TH2F* h = new TH2F("",";METPt with severityLevel=12;METPt with severityLevel=8",100,0.,600,100,0.,600);
	TH1F* h1D_12 = new TH1F("",";METPt ;# of events",100,0.,600);
	TH1F* h1D_8 = new TH1F("",";METPt ;# of events",100,0.,600);

        
	int count ;	
	for (i=0;i<numL;i++) 
	{
                if(y[i] != b[i]){
		//printf("Attempting to fill x=%f, y=%f from line #%i\n",y[i],b[i],i);
		count++;
		}
		h1D_12->Fill(y[i]);
		h1D_8->Fill(b[i]);
		h->Fill(y[i],b[i]);
	}

	cout<<"count is"<<count<<"\n"; 
	
        TCanvas c;
	c.cd();
	h->Draw("colz"); //drawing histo
        c.SetLogz();
	c.SaveAs("Th2D_MetPt.pdf");

        TCanvas c1D;
	c1D.cd();
	h1D_12->SetLineColor(kRed);
	h1D_8->SetLineColor(kBlue);
	h1D_12->Draw("hist"); //drawing histo
	h1D_8->Draw("hist same"); //drawing histo
        c1D.SetLogy();
	c1D.SaveAs("Th1D_MetPt.pdf");
	return 0;
}

