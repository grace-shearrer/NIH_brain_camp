#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _alphasynapse1_reg();
extern void _alphasynapse2_reg();
extern void _kalpha_reg();
extern void _leak_reg();
extern void _naalpha_reg();

modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," alphasynapse1.mod");
fprintf(stderr," alphasynapse2.mod");
fprintf(stderr," kalpha.mod");
fprintf(stderr," leak.mod");
fprintf(stderr," naalpha.mod");
fprintf(stderr, "\n");
    }
_alphasynapse1_reg();
_alphasynapse2_reg();
_kalpha_reg();
_leak_reg();
_naalpha_reg();
}
