//
//  midus_tree_structs.h
//  MuSIC5_offline_analysis
//
//  Created by Sam Cook on 15/06/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
//
// This struct gives the general layout of data for a piece 
// of equipment (e.g. ADC, TDC) in a midus root file
// 

#ifndef MuSIC5_offline_analysis_midus_tree_structs_h
#define MuSIC5_offline_analysis_midus_tree_structs_h

static int const n_channels = 2;
// number of branches is n_channels + 3 (ADC, PHADC & T0)
static int const n_branches_in_trigger_tree = n_channels + 3;
static int const max_data_entries = 500;

struct midus_out_branch {
    int n_entries;
    int data[max_data_entries];
};

struct channel {
	int adc;
	int tdc0;
    int n_tdc_hits;
	int tdc[max_data_entries];
};

enum branch_ids {
    branch_adc   = 0,
    branch_phadc = 1,
    branch_T0    = 2,
    branch_TDC1  = 3
    // for other TDC branches just ad to TDC1
    };

enum adc_ch_names {
    adc_ch_U0 = 1 ,
    adc_ch_U1 = 2 ,
    adc_ch_U2 = 3 ,
    adc_ch_U3 = 4 ,
    adc_ch_U4 = 5 ,
    adc_ch_U5 = 6 ,
    adc_ch_U6 = 7 ,
    adc_ch_U7 = 8 ,
    adc_ch_D0 = 9 ,
    adc_ch_D1 = 10,
    adc_ch_D2 = 11,
    adc_ch_D3 = 12,
    adc_ch_D4 = 13
};

enum phadc_ch_names {
    phadc_ch_Ge0  = 0,
    phadc_ch_Ge1  = 1,
    phadc_ch_CdTe = 2
    };

enum tdc_ch_names {
    tdc_ch_t0  = 0,
    tdc_ch_U0  = 1 ,
    tdc_ch_U1  = 2 ,
    tdc_ch_U2  = 3 ,
    tdc_ch_U3  = 4 ,
    tdc_ch_U4  = 5 ,
    tdc_ch_U5  = 6 ,
    tdc_ch_U6  = 7 ,
    tdc_ch_U7  = 8 ,
    tdc_ch_D0  = 9 ,
    tdc_ch_D1  = 10,
    tdc_ch_D2  = 11,
    tdc_ch_D3  = 12,
    tdc_ch_D4  = 13,
    tdc_ch_Ge0 = 14,
    tdc_ch_Ge1 = 15
};

enum scaler_ch_names {
    scaler_ch_sec    = 0,
    scaler_ch_trig   = 1,
    scaler_ch_gdTrig = 2,
    scaler_ch_U      = 3,
    scaler_ch_D      = 4,
    scaler_ch_scint  = 5,
    scaler_ch_na     = 6,
    scaler_ch_clk    = 7
};
#endif
