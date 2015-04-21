# Makefile - tiraka, uds
# 12.10.2005 HJ - initial revision
# 27.10.2006 HJ - removed -O2 from eff and added rm in clean
# 24.06.2009 SK - added *~ in clean (removes now emacs' backup files)

.PHONY: all

SRC=binomial-coefficient.cpp
# HDR=datastructure.hh

all: prog eff

prog: $(SRC) 
	g++ -o prog $(SRC)

eff: $(SRC) 
	g++ $(SRC) -o eff

clean:
	rm -f prog eff *~

#style:
#	/home/style/style -c /home/boss/style/tiraka -w $(SRC)
