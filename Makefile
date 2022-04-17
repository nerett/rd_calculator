DEPENDENCIES =
PACKAGEDEPENDENCIES = build-essential

DEBUGFLAGS = -Wall -Wextra -g -fsanitize=address
EXECDIR = Debug/

CC = g++ -std=c++11
CFLAGS = -c $(DEBUGFLAGS) $(RELEASEFLAGS)
LDFLAGS = $(DEBUGFLAGS)
BUILDDIR = Build/

EXECNAME = rdcalc


#----------------------------------BUILDING--------------------------------------------------
all: mkdir main
	$(CC) $(LDFLAGS) $(BUILDDIR)main.o $(BUILDDIR)librd_calculator.o -o $(EXECDIR)$(EXECNAME)
	
mkdir:
	mkdir -p Debug/ Release/ Build/
	
main: librd_calculator
	$(CC) $(CFLAGS) main.cpp -o $(BUILDDIR)main.o


#----------------------------------librd_calculator------------------------------------------
librd_calculator:
	$(CC) $(CFLAGS) rd_calculator.cpp -o $(BUILDDIR)librd_calculator.o


#----------------------------------INSTALLING DEPENDENCIES-----------------------------------
install-dependencies:
	cd .. && git clone $(DEPENDENCIES)

install-dependencies-all: install-dependencies
	sudo $(PACKAGEMANAGER) install $(PACKAGEDEPENDENCIES)


#----------------------------------RUNNING---------------------------------------------------
run:
	./$(EXECDIR)$(EXECNAME) 2> /dev/null

rund:
	./$(EXECDIR)$(EXECNAME)


#-----------------------------------CLEANING-------------------------------------------------
clean:
	rm -rf Debug/ Release/ Build/
