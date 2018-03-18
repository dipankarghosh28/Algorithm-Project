all: brute dynamic

brute: 
	gcc -o brute.out Q1-1_brute_force_knapsack.c

dynamic:
	gcc -o dynamic.out Q1-3_dynamic_programming_knapsack.c
clean: 
	rm -rf brute.out dynamic.out
