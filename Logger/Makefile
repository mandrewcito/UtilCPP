TESTFILE=defaultLog.log
EXEC=test.out

all: clean compile test

compile:
	@g++ -c -std=gnu++11 logger.cpp
	@g++ -c -std=gnu++11 test.cpp
	@g++ -o $(EXEC) test.o logger.o
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


