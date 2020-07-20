# Longest Common Subsequence

# Tasks

1. Write a program that solves the Longest Common Subsequence (LCS) problem by the bottom-up dynamic programming approach. The inputs to the program are two files filex.txt and filey.txt. The output is written into output1.txt.
**The input files:**
Each filex.txt contains one line with a sequence of characters (without space). For example: abacabbcdeaa
Similarly each filey.txt contains a sequence of characters (without space). For example: aaabbccddadeee
**The output file:**
For input strings of size less or equal to 10:
Each line i, for i = 0 to m (m = length of the string in filex.txt) of the output file will contain a row of the matrix lenLCS (as shown in the examples in Lecture 15). It will contain the lenLCS[i, j] for columns j = 0, 1, ..., n (n = length of the string in filey.txt).
Line m+1 will contain a longest common subsequence.
Line m+2 will contain the running time of the algorithm.
For inputs of size greater than 10 the output file will contain: 
Line 1: The length of the LCS
Line 2: The running time of the algorithm

2. Write a program that solves the LCS problem by recursively computing the length of a longest common subsequence (without memoization). The input as before are the files filex and filey. The output is written into output2.txt containing:
Line 1: The length of the LCS
Line 2: The running time of the algorithm
Note: this program does not compute and store matrices and you are not required to find a longest common sequence.

3. Write a program that solves the LCS problem by the top-down dynamic programming approach - recursively computing the length of a longest common subsequence with memoization. The input as before are the files filex and filey. The output is written into output3.txt containing:
Line 1: The length of the LCS
Line 2: The running time of the algorithm


