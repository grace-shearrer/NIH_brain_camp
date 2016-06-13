: Ca2+ pool for IKCa

NEURON {
        SUFFIX capool
	USEION ca READ ica,cai,cao WRITE cai
	RANGE fca, tauca, cainf
}

UNITS {
        (mM) = (milli/liter)
        (mA) = (milliamp)
	(mV) = (millivolt)
	FARADAY = 96485.309 (coul)
}

PARAMETER {
        tauca= 200 (ms)       	: decay time constant
	fca = 1.0:.91		:ca influx factor that goes to ca pool
}

ASSIGNED {
	v (mV)
	ica (mA/cm2)
	cainf (mM)	: equilibrium ca2+ concentration
	w (micrometer)	: thickness of shell for ca2+ diffusion
	z		: valence
	cao (mM)
}

STATE { cai(mM)  }

BREAKPOINT { 
	SOLVE states METHOD cnexp
}

INITIAL {
	cainf = 50e-6
	w = 1
	z = 2
	:cai = cainf
}

DERIVATIVE states {
		cai'= -fca*ica/(z*FARADAY*w*1e-4) + (cainf - cai)/tauca
}



