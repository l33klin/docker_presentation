newuts: newuts.c
	gcc -o newuts newuts.c

ns_exec: ns_exec.c
	gcc -o ns_exec ns_exec.c

all: newuts ns_exec

clean:
	rm newuts ns_exec
