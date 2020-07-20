#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<chrono>

using namespace std;

/*Recursive function to compute the length of a longest common subsequence without memoization. 
Makes use of the LCS Theorem in Lecture 15-16.*/
int longestCommonSubsequence(string x, string y, unsigned int i, unsigned int j) {
	if (i >= x.length() || j >= y.length()) {
		return 0;
	}
	else if (x[i] == y[j]) {
		return 1 + longestCommonSubsequence(x, y, i+1, j+1);
	}
	else {
		return max(longestCommonSubsequence(x,y,i+1,j), longestCommonSubsequence(x, y, i, j+1));
	}
}

int main(int argc, char *argv[]) {
	//xstr and ystr are string variables to hold the two strings to find a LCS between
	string xstr, ystr;
	//open filex input file
	ifstream filex(argv[1]);
	//open filey input file
	ifstream filey(argv[2]);
	
	//use clock to keep track of algorithm running time
	auto begin = chrono::high_resolution_clock::now();	

	//save strings from input files into xstr and ystr variables
	getline(filex, xstr);
	getline(filey, ystr);
	
	//close both input files
	filex.close();
	filey.close();

	//output file to put results into
	ofstream output;
	output.open(argv[3]);
	
	//compute LCS
	int lcs = longestCommonSubsequence(xstr, ystr, 0, 0);

	//stop the clock	
	auto end = chrono::high_resolution_clock::now();

	//write results to the output file
	output << lcs << endl;
	output << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " milliseconds" << endl;

	//close the output file
	output.close();
	return 0;
}
