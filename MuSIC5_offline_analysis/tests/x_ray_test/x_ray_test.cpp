// To test the hist_x_ray class

#include <iostream>

#include "../../include/hist_x_ray.h"
#include "../../include/midus_entry.h"
#include "../../include/midus_tree_structs.h"
#include "../../include/smart_tfile.h"

#include "TFile.h"

int main() {
	smart_tfile* file = smart_tfile::getTFile("test.root", "RECREATE");
	
	// Create a mu_lifetime histogram
	hist_x_ray* hist = new hist_x_ray(file, "x_ray", 200, 0, 100); 
	
	// Create some mock events
	midus_out_branch tr1 [n_branches_in_trigger_tree]; // 0 = ADC, 1 = PHADC, 2 = T0, 3 = TDC1, 4 = TDC2
	tr1[branch_adc].n_entries = 0; // ADC
	tr1[branch_phadc].n_entries = 3; // PHADC (3 channels Ge0, Ge1, CdTe)
	tr1[branch_T0].n_entries = 1; // TDC0 (T0 - 1 entry (time when event triggered))
	tr1[branch_TDC1].n_entries = 5; // TDC1 (channel U1)
	tr1[branch_TDC2].n_entries = 10; // TDC2 (channel U2)
	tr1[branch_TDC3].n_entries = 20; // TDC3
	for (int i = 0; i < tr1[branch_phadc].n_entries; i++) {
		tr1[branch_phadc].data[i] = 20*(i+1);
	}
	tr1[branch_T0].data[0] = 1000;
	for (int i = 0; i < tr1[branch_TDC1].n_entries; i++) {
		tr1[branch_TDC1].data[i] = 1040 + i;
	}
	for (int i = 0; i < tr1[branch_TDC2].n_entries; i++) {
		tr1[branch_TDC2].data[i] = i + 1050;
	}
	for (int i = 0; i < tr1[branch_TDC3].n_entries; i++) {
		tr1[branch_TDC3].data[i] = i + 1060;
	}
	
	midus_out_branch tr2 [n_branches_in_trigger_tree]; // 0 = ADC, 1 = PHADC, 2 = T0, 3 = TDC1, 4 = TDC2
	tr2[branch_adc].n_entries = 0; // ADC
	tr2[branch_phadc].n_entries = 3; // PHADC (3 channels Ge1, Ge2, CdTe)
	tr2[branch_T0].n_entries = 2000; // TDC0 (T0)
	tr2[branch_TDC1].n_entries = 15; // TDC1 (channel U1)
	tr2[branch_TDC2].n_entries = 20; // TDC2 (channel U2)
	tr2[branch_TDC3].n_entries = 40; // TDC3
	for (int i = 0; i < tr2[branch_phadc].n_entries; i++) {
		tr2[branch_phadc].data[i] = 5*(i+1);
	}
	tr2[branch_T0].data[0] = 2000;
	for (int i = 0; i < tr2[branch_TDC1].n_entries; i++) {
		tr2[branch_TDC1].data[i] = i + 2030;
	}
	for (int i = 0; i < tr2[branch_TDC2].n_entries; i++) {
		tr2[branch_TDC2].data[i] = i + 2020;
	}
	for (int i = 0; i < tr2[branch_TDC3].n_entries; i++) {
		tr2[branch_TDC3].data[i] = i + 2005;
	}
	
	int n_events = 2;
	midus_entry* event[n_events];
	event[0] = new midus_entry(tr1);
	event[1] = new midus_entry(tr2);
	
	for (int i = 0; i < n_events; i++) {
		hist->process(event[i]);
	}
	
	file->close();
	return 0;
}
