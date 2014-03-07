
CC = gcc
CXX = g++
CC32 = gcc

CXXFLAGS = -D__STDC_LIMIT_MACROS -D_REENTRANT


INCLUDE = -I../common/

APP_SRC = main.cpp \
	container.cpp

APP_OBJ = $(APP_SRC:.cpp=.o)

.SUFFIXES: .o .cpp
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

PROGRAM = app_ring
all: app_ring

app_ring:  $(APP_OBJ) $@
	$(CXX) -o $@ $(LINK_CXXFLAG) $(INCLUDE) $(APP_OBJ)

clean:
	$(RM) -r $(PROGRAM) 
	rm -f *.o

