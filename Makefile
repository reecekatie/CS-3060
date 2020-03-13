assn3: assn3.c Makefile
	gcc -pthread -o assn3 assn3.c
assn1.tar.gz: assn3.c Makefile
	indent -linux assn3.c
	tar -czf assn3.tar.gz assn3.c Makefile

# Erases the binary as needed. Will execute when 'make clean' is run
clean:
	if [ -f assn3 ]; then rm assn3; fi
