# Best First Search

# Task

In this assignment, you need to implement the best-first-search branch and bound algorithm for the 0-1 knapsack problem introduced in the class. The algorithm needs to find one optimal solution as quickly as possible. Note: the input problem instance may not contain items in decreasing order of profit/weight, so your program needs to sort the items first before the search.

The program will have 2 command line arguments: input file, output file.

*Input file:*
The structure of the input file is as follows.
Line 1: n,c // n is the size of the problem (the total number of items) and C is the total weight limit 
Lines 2 to n+1: wi,pi // wi is the weight of item i and pi is the profit of item i

For example:
2,40
5,30
10,50 5,10

*Output file:*
The structure of the output file is as follows.

Line 1: the size of the problem (i.e., the total number of items),the optimal value (i.e., the maximum profit),the size (k) of the first optimal solution found (i.e., the size of the first optimal subset of items found to produce the maximum profit)
Line 2: the total number of nodes visited (by the algorithm from the start to the end of the search including the root and the last node visited in the binary search space tree),the total number of leaf nodes visited
Lines 3 to 3+(k-1): each line contains the weight and profit of an item selected in order for the first optimal solution found.

The solution for the above example in the output file format: 
4,90,2
11,6
2,40
10,50

# Compilation and Execution Instructions & Further Details

Compile BestFirstSearch program by typing "make"

To run, type BestFirstSearch <input.txt> <output.txt>

This program implements the best-first-search branch and bound algorithm for the 0-1 Knapsack problem. Data structures used include multiple vectors and a priority queue to store nodes.

The worst case computation time of this program is O(2^N) and best case computation time is O(N) where N is the number of items.
