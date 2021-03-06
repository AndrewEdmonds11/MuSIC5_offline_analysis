// hist_branch_channel.cpp
// -- Simply plots a histogram all the values in a branch (ADC, TDC0 etc.) for a single channel 
// -- An example of how to use hist_maker_algorithm
// Created: 16/06/2012 Andrew Edmonds

#include <iostream>
#include "hist_branch_channel.h"

hist_branch_channel::hist_branch_channel(smart_tfile *const out_file, std::string histname, int channel, int branch, int n_bins, double x_low, double x_high):
 hist_maker_algorithm(out_file, histname, n_bins, x_low, x_high), channel_m(channel), branch_m(branch) {

	// if this is an adc branch - check that the channel number is valid (i.e between 1 and 13 - see adc_channel_names)
	if (branch_m == midus_structure::eMEB_qdc) {
		if (channel_m < midus_structure::eQDC_U1 || channel_m > midus_structure::eQDC_D5) {
			std::cout << "Invalid channel number for ADC branch" << std::endl;
		}
	}
	else if (branch_m == midus_structure::eMEB_adc0 || branch_m == midus_structure::eMEB_adc1) {
		// channel number must be between 0 and 1
		if (channel_m < 0 || channel_m > 1) {
			std::cout << "Invalid channel number for PHADC branch" << std::endl;
		}
	}
	else if (branch_m >= midus_structure::eMEB_tdc0)
		channel_m = -1; // don't need channel number for TDCs
}

hist_branch_channel::~hist_branch_channel() {
}

void hist_branch_channel::process(line_entry const * in_entry) {
	hist_maker_algorithm::process(in_entry);
}

void hist_branch_channel::process(midus_entry const * in_entry) {
	
	// Fill the histogram
	if (branch_m == midus_structure::eMEB_qdc) {
		hist_maker_algorithm::fill_hist(in_entry->get_value_in_branch(branch_m, channel_m));
	}
	else if (branch_m ==midus_structure::eMEB_adc0 || branch_m == midus_structure::eMEB_adc1) { 
		hist_maker_algorithm::fill_hist(in_entry->get_value_in_branch(branch_m, 0)); // channel name will be the same as the index
	}
	else if (branch_m == midus_structure::eMEB_tdc0) {
		hist_maker_algorithm::fill_hist(in_entry->get_value_in_branch(branch_m, 0)); 
	}
	else if (branch_m > midus_structure::eMEB_tdc0) {
		for (int i = 0; i < in_entry->get_entries_in_branch(branch_m); i++) {
			hist_maker_algorithm::fill_hist(in_entry->get_value_in_branch(branch_m, i)); 
		}
	}
}
