Compile program1, program2, and program3 all at the same time by typing "make".

PROGRAM 3
	- To run, type program3 <filex.txt> <filey.txt> <output3.txt> 
	where filex.txt and filey.txt are input files, with each file 
	containing one input string, and output3.txt is the file to 
	write the output of the program to. 
	- This program solves the Longest Common Subsequence problem
	by recursively computing the length of a longest common 
	subsequence with memoization. It initializes a 2-dimensional
	array of integers to -1 and keeps track of previously calculated
	results in the table so that recursion is not repeated on the same
	subproblem, minimizing overlap and decreasing computation time.
	This program outputs the length of the LCS and the running time
	of the algorithm in milliseconds.
	- The computation time of this program is 
	O(x.length + y.length) or O(m*n) because whenever the same values
	for m and n are passed into the recursive function, we do not perform
	the recursive call and instead look at the table to see the value
	that was calculated when those values were passed in previously. This
	reduces the computation time.
