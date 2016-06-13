#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," AMPA_syn.mod");
fprintf(stderr," currentclamp.mod");
fprintf(stderr," kd_current.mod");
fprintf(stderr," leak_current.mod");
fprintf(stderr," na_current.mod");
fprintf(stderr, "\n");
    }
_AMPA_syn_reg();
_currentclamp_reg();
_kd_current_reg();
_leak_current_reg();
_na_current_reg();
}
