// tfile_export_algorithm.h
// -- A class to export tfiles (will have derived classes)
// Created: 15/06/2012 Andrew Edmonds

#ifndef TFILE_EXPORT_ALGORITHM_H_
#define TFILE_EXPORT_ALGORITHM_H_

#include "algorithm.h"
#include "midus_entry.h"

#include "smart_tfile.h"
#include "TFile.h"

class tfile_export_algorithm : public algorithm {
public:
	tfile_export_algorithm(smart_tfile *const);
	virtual ~tfile_export_algorithm();
	
	void process(line_entry const *) {};
	virtual void process(midus_entry const *);
    
private:
	smart_tfile *const out_file_m;
};

#endif
