TESTFILE=defaultLog.log
EXEC=test.out

all: clean compile test

compile:
	@g++ -c config.cpp
	@g++ -c test.cpp
	@g++ -o $(EXEC) test.o config.o
	@echo "Compilado"

clean: 
	@-rm -f $(EXEC)	
	@-rm -f $(TESTFILE)
	@-rm -f *.o
	@-rm -f *~
	@echo "Borramos temporales y ejecutables"
test: 
	@echo "Ejecutamos "$(EXEC) 
	@./$(EXEC)


