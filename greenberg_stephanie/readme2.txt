Compile program1, program2, and program3 all at the same time by typing "make".

PROGRAM 2
	- To run, type program2 <filex.txt> <filey.txt> <output2.txt> 
	where filex.txt and filey.txt are input files, with each file 
	containing one input string, and output2.txt is the file to 
	write the output of the program to. 
	- This program solves the Longest Common Subsequence problem
	by recursively computing the length of a longest common 
	subsequence (without memoization). This program outputs the
	length of the LCS and the running time of the algorithm in
	milliseconds.
	- The computation time of this program is 
	O(2^(x.length + y.length)) because it requires us to
	look at all subsequences of both sequences and find the
	longest matching one.

