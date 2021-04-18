SDIR = src
IDIR = include
EDIR = include/exceptions
TDIR = tests
TDIR_SORT = tests/sort
TDIR_SEARCH = tests/search
TDIR_BASE = tests/base
CXX = g++
CXXFLAGS = -I$(IDIR) -std=c++17 -ggdb
ODIR = obj
SORT_EXEC = bubble selection insertion binary_insertion extern_merge #partition quicksort
SEARCH_EXEC = secuential binary intercalation
BASE_EXEC =	matrix tree
ALL_EXEC = $(SORT_EXEC) $(SEARCH_EXEC) $(BASE_EXEC)
#LDIR =../lib

#LIBS=-lm
_SRC = timer.cpp
_DEPS = sort.hpp helper.hpp search.hpp cast.hpp matrix.hpp timer.hpp tree.hpp
_EDEP = matrix.hpp # include/exceptions/*.hpp (exception head files)

EDEPS = $(patsubst %,$(EDIR)/%,$(_EDEPS))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

#_SORT_OBJ = bubble.o selection.o insertion.o binary_insertion.o #partition.o quicksort.o
_SORT_OBJ = $(patsubst %,%.o,$(SORT_EXEC))

#_SEARCH_OBJ = secuential.o
_SEARCH_OBJ = $(patsubst %,%.o,$(SEARCH_EXEC))

_OBJ = $(_SORT_OBJ) $(_SEARCH_OBJ)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(shell mkdir -p obj)

all: sort search

sort: $(SORT_EXEC)

search: $(SEARCH_EXEC)

$(ODIR)/%.o: $(TDIR_BASE)/%.cpp $(DEPS) $(EDEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) $(EDEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/%.o: $(TDIR_SORT)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/%.o: $(TDIR_SEARCH)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

##### base tests #####
matrix:	$(ODIR)/matrix.o $(ODIR)/timer.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

tree: $(ODIR)/tree.o
	$(CXX) -o $@ $^ $(CXXFLAGS)


##### sort algorithms #####
bubble:	$(ODIR)/bubble.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

extern_merge:	$(ODIR)/extern_merge.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

binary_insertion:	$(ODIR)/binary_insertion.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

insertion:	$(ODIR)/insertion.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

selection:	$(ODIR)/selection.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

intercalation:	$(ODIR)/intercalation.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

##### search algorithms #####
secuential:	$(ODIR)/secuential.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

binary:	$(ODIR)/binary.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

##### helper #####
# partition:	$(ODIR)/partition.o
# 	$(CXX) -o $@ $^ $(CXXFLAGS)

# $(EXEC): $(OBJ)
# 	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY:

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ $(ALL_EXEC)
