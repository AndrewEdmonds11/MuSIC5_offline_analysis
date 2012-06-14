//
//  entry.h
//  MuSIC5_offline_analysis
//
//  Created by Sam Cook on 14/06/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
//  An empty abstract base class to represent entries in input files

#ifndef MuSIC5_offline_analysis_entry_h
#define MuSIC5_offline_analysis_entry_h

class input_file;

class entry {
public:
    explicit entry(input_file const*);
    virtual ~entry() = 0;
    inline input_file const* get_source()const {return my_source_file_m;};
    
private:
    entry();
    input_file const* my_source_file_m;
};

inline entry::~entry() {}

#endif