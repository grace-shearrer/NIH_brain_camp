:Shock to Interneuron Cells AMPA+NMDA with local Ca2+ pool

NEURON {
	POINT_PROCESS inhsyntest
	NONSPECIFIC_CURRENT igaba
	RANGE taug1, taug2, factorg, normconstg
	RANGE ggaba, ggabas, gGABAmax, egaba
	RANGE initW, W
}

UNITS {
	(mV) = (millivolt)
        (nA) = (nanoamp)
	(uS) = (microsiemens)
}

PARAMETER {

	:W
	initW = 10

	:GABA
	taug1 = 10 (ms)
	taug2 = 20 (ms)
	gGABAmax = 40e-3 (uS)
	egaba = -80.0 (mV)

}

ASSIGNED {
	v (mV)
	eca (mV)

	W	

	:GABA
	igaba (nA)
	ggaba
	ggabas
	factorg
	normconstg
}

STATE {

	:GABA
	Ag
	Bg
}

INITIAL {

	:GABA Weight
	W = initW

	Ag=0
	Bg=0

	factorg = taug1*taug2/(taug2-taug1)
	normconstg = -1/(factorg*(1/exp(log(taug2/taug1)/(taug1*(1/taug1-1/taug2)))-1/exp(log(taug2/taug1)/(taug2*(1/taug1-1/taug2)))))
	:gives maximum syn activation value of 1

}

BREAKPOINT {
	SOLVE states METHOD cnexp
}

DERIVATIVE states {

	:GABA
	Ag' = -Ag/taug1
	Bg' = -Bg/taug2
	ggaba = normconstg*factorg*(Bg-Ag)
	ggabas = ggaba
	if (ggabas > 1) {ggabas = 1}
	igaba = W*gGABAmax*ggabas*(v-egaba)
}

NET_RECEIVE(wgt) {
        LOCAL x
	x = wgt
	state_discontinuity(Ag,Ag+x)
	state_discontinuity(Bg,Bg+x)
}
