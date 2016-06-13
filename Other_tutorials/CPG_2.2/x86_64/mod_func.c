#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _extsyn_reg(void);
extern void _inhsyn_reg(void);
extern void _k_reg(void);
extern void _leak_reg(void);
extern void _na_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," extsyn.mod");
    fprintf(stderr," inhsyn.mod");
    fprintf(stderr," k.mod");
    fprintf(stderr," leak.mod");
    fprintf(stderr," na.mod");
    fprintf(stderr, "\n");
  }
  _extsyn_reg();
  _inhsyn_reg();
  _k_reg();
  _leak_reg();
  _na_reg();
}
