//
//  scaler_entry.h
//  MuSIC5_offline_analysis
//
//  Created by Sam Cook on 17/06/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MuSIC5_offline_analysis_scaler_entry_h
#define MuSIC5_offline_analysis_scaler_entry_h

#include "midus_structure.h"
#include <string>

class scaler_algorithm;

class scaler_entry {
public:
    scaler_entry(int const [midus_structure::n_scaler_ch]);
    ~scaler_entry(){;}
    
    void accept (scaler_algorithm *const) const;
    
    inline int const get_value(int const ch) const { return data[ch]; };
    inline static int const get_n_channels() {return midus_structure::n_scaler_ch;};
    
    inline static std::string const get_channel_name(int const ch) {
        static std::string names [midus_structure::n_scaler_ch] = {"Sec", "trigger"," UnotD"
            "U", "D","scint", "-", "clk"};
        return names[ch];
    };
    
private:
    scaler_entry();
    int data [midus_structure::n_scaler_ch];
};

#endif
