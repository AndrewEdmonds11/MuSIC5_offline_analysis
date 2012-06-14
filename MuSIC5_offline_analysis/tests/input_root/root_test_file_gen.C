//
//  root_test_file_gen.C
//  MuSIC5_offline_analysis
//
//  Created by Sam Cook on 14/06/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

// This is a root macro for generating a basic tfile with
// simple ttree inside of it

{ 
    // example of macro to read data from an ascii file and 
    // create a root file with an histogram and a TTree 
    gROOT->Reset(); 
    // the structure to hold the variables for the branch 
    
    struct branch { 
        Int_t some_num;
    }; 
    branch branch; 
    // create a new ROOT file 
    TFile *f = new TFile("test.root","RECREATE"); 
    // create a TTree 
    TTree *tree = new TTree("T","staff data from ascii file"); 
    // create one branch with all information from the stucture 
    tree->Branch("numbers",&branch.some_num,"number/I"); 
    
    for (int i = 0; i < 500; ++i)
    {
        branch.some_num = i;
        tree->Fill(); 
    }
                 // check what the tree looks like 
    tree->Print(); 
    f->Write();
}