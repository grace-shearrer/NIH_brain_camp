#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _alphasynapse1_reg(void);
extern void _alphasynapse2_reg(void);
extern void _kalpha_reg(void);
extern void _leak_reg(void);
extern void _naalpha_reg(void);

void modl_reg(){
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
