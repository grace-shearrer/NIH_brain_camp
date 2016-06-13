: Inhibitory synapse

NEURON {
	POINT_PROCESS inhsyn2
	NONSPECIFIC_CURRENT isyn
	RANGE tau, esyn, isyn, gmax, gsyn, w
}

PARAMETER {
	esyn = -80		(millivolt)
	tau  = 20		(ms)
	gmax 			(microsiemens)
}

ASSIGNED {
	v	(millivolt)
	isyn	(nanoamp)
	gsyn	(microsiemens)
	w
}

STATE { a  b}

INITIAL {
	a = 0 
	b = 0
}

BREAKPOINT {
	SOLVE state METHOD cnexp
	gsyn = w*gmax*a*b
	isyn = gsyn*(v-esyn)
}

DERIVATIVE state {
	a' = 1/tau
	b' = -b/tau
}

NET_RECEIVE(weight) {
	state_discontinuity(a,(a*b/(b+1*exp(1))))
	state_discontinuity(b,b+1*exp(1))
	w = weight
}
