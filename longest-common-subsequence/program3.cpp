#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<chrono>

using namespace std;

//table to keep track of values generated from previous recursive calls
vector<vector<int>> lcs_table;

//Recursive function to calculate the LCS between two strings. 
//First we check if the recursive call has already been made. If it has,
//there will be a value in the table for it. If not, we calculate the value
//and store it in the table for future use.
int longestCommonSubsequence(unsigned int i, unsigned int j, string x, string y) {
	if (i == 0 || j == 0) {
		return 0;
	}

	//this means we already calculated a solution, return that solution
	if (lcs_table[i][j] >= 0) {
		return lcs_table[i][j];
	}
	//if we haven't calculated a solution for the current recursive call, calculate it
	//and store it in the table
	if (x[i-1] == y[j-1]) {
		lcs_table[i][j] = 1 + longestCommonSubsequence(i-1, j-1, x, y);
		return lcs_table[i][j];
	}
	else {
		lcs_table[i][j] = max(longestCommonSubsequence(i-1, j, x, y), longestCommonSubsequence(i, j-1, x, y));
		return lcs_table[i][j];	
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
	
	//initialize the memoization table with -1
	for (unsigned int i = 0; i <= xstr.length(); i++) {
		vector<int> temp;
		for (unsigned int j = 0; j <= ystr.length(); j++) {
			temp.push_back(-1);
		}
		lcs_table.push_back(temp);
	}
	
	//call recursive function
	int lcs = longestCommonSubsequence(xstr.length(), ystr.length(), xstr, ystr);

	//output file to put results into
	ofstream output;
	output.open(argv[3]);
	
	//stop the clock	
	auto end = chrono::high_resolution_clock::now();

	//write results to the output file
	output << lcs << endl;
	output << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " milliseconds" << endl;

	//close the output file
	output.close();

	return 0;
}

