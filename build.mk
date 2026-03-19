.PHONY: all

all: ferris_sweep_tbreslein_rp2040_ce.uf2

ferris_sweep_tbreslein_rp2040_ce.uf2: keyboards/ferris/keymaps/tbreslein/*
	qmk lint -kb ferris/sweep -km tbreslein
	qmk compile -c -j0 -kb ferris/sweep -km tbreslein -e CONVERT_TO=rp2040_ce
