# Sample makefile for OHJ-1406 

# object file definitions, insert your own to the end of the list
# remeber to run "gmake depend" after making changes to includes
# or adding new object files
OBJS =	julkinen/chopper.o julkinen/utility.o julkinen/boarddrawer.o julkinen/die.o julkinen/initreader.o dipoly.o game.o player.o createplayer.o square.o
SRC = *.cc

# definitions of compilers etc.
CXX = tutg++
CXXFLAGS =
DEPXX = g++ -MM
DEPFILE = dependencyfile.make

# name of the executable change this to dipoly...
EXE = dipoly

# definition of a linking command, $^ refers to all the
# files in dependency list (e.g. OBJS)
XXLNK = $(CXX) -o $@ $(CXXFLAGS) $^

# this first rule is done as default (if only command "gmake" without 
# parameters is given (does not necessarily have to be named default...
default: $(EXE)

# rule to make the executable
$(EXE): $(OBJS)
	$(XXLNK)

# cleans the folder by removing the executable, object files and dep-file
clean:
	-rm $(OBJS) $(EXE) $(DEPFILE)

# Finds out the file dependencies and saves the information into a 
# depfile
$(DEPFILE):
	$(DEPXX) $(SRC) > $(DEPFILE)

# rule for refreshing the dependencies in depfile
depend:
	@echo "Updating $(DEPFILE)"
	$(DEPXX) $(SRC) > $(DEPFILE)

# includes the depfile into end of this makefile
include $(DEPFILE)
