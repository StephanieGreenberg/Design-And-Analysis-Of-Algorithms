Compile program1, program2, and program3 all at the same time by typing "make".

PROGRAM 1
	- To run, type program1 <filex.txt> <filey.txt> <output1.txt> 
	where filex.txt and filey.txt are input files, with each file 
	containing one input string, and output1.txt is the file to 
	write the output of the program to. 
	- This program solves the Longest Common Subsequence problem
	by the bottom-up dynamic programming approach, and uses a 
	matrix of integers to keep track of the length of the longest 
	common sequence and a matrix of strings to keep track of the 
	direction from which the integers are entered in the table.
	- If both of the input strings are less than 10 characters, 
	the program will print the LCS matrix followed by a longest 
	common subsequence and the running time of the algorithm in
	milliseconds. If one or both of the input strings are greater
	than 10 characters, the program will print the length of the 
	LCS followed by the running time of the algorithm in milliseconds.
	- The computation time of this program is Theta(x.length * y.length)
	as each table entry takes Theta(1) time to compute, and the time
	taken to construct the LCS is slower so we don't count it.
