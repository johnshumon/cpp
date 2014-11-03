# 12.10.2005 HJ - initial revision
# 27.10.2006 HJ - removed -O2 from eff and added rm in clean
# 24.06.2009 SK - added *~ in clean (removes now emacs' backup files)
# 26.04.2010 SK - added rule to run style with correct config
# 16.06.2011 SK - added -w in style and -Wextra for compiling with g++
# 17.06.2011 SK - allows only datastructure.cc, .hh and main.cc to be compiled

.PHONY: all 

SRC=main.cc sudokusolver.cc
HDR=sudokusolver.hh

all: prog eff

prog: $(SRC) $(HDR)
	tutg++ -o prog $(SRC)

eff: $(SRC) $(HDR)
	g++ -Wall -Wextra -pedantic -Werror $(SRC) -o eff

clean:
	rm -f prog eff *~

style:
	/home/style/style -c /home/boss/style/tiraka -w $(SRC)
