#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _capool_reg(void);
extern void _currentclamp_reg(void);
extern void _ia_reg(void);
extern void _icas_reg(void);
extern void _icat_reg(void);
extern void _ikca_reg(void);
extern void _ina_reg(void);
extern void _kdr_reg(void);
extern void _leak_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," capool.mod");
    fprintf(stderr," currentclamp.mod");
    fprintf(stderr," ia.mod");
    fprintf(stderr," icas.mod");
    fprintf(stderr," icat.mod");
    fprintf(stderr," ikca.mod");
    fprintf(stderr," ina.mod");
    fprintf(stderr," kdr.mod");
    fprintf(stderr," leak.mod");
    fprintf(stderr, "\n");
  }
  _capool_reg();
  _currentclamp_reg();
  _ia_reg();
  _icas_reg();
  _icat_reg();
  _ikca_reg();
  _ina_reg();
  _kdr_reg();
  _leak_reg();
}
