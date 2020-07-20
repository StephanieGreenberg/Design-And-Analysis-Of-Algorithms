#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
#include<chrono>

using namespace std;

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

	//matrix to hold the values of length of LCS
	int c_table[xstr.length()+1][ystr.length()+1];
	//matrix to hold arrows telling the direction which the numbers move. "D" indicates diagonal, "L" indicates left, and "U" indicates up
	string b_table[xstr.length()+1][ystr.length()+1];

	//output file to put results into
	ofstream output;
	output.open(argv[3]);

	for (unsigned int row = 0; row <= xstr.length(); row++) {
		for (unsigned int col = 0; col <= ystr.length(); col++) {
			//initialization: make all c_table[i,0] = c_table[0,j] = 0
			if (row == 0 || col == 0) {
				c_table[row][col] = 0;
			}
			else {
				if (xstr[row-1] == ystr[col-1]) {
					c_table[row][col] = (c_table[row-1][col-1])+1;
					//indicates Xi = Yj is an element of LCS
					b_table[row][col] = "D";
				}
				else {
					if (c_table[row-1][col] >= c_table[row][col-1]) {
						c_table[row][col] = c_table[row-1][col];
						b_table[row][col] = "U";
					}
					else {
						c_table[row][col] = c_table[row][col-1];
						b_table[row][col] = "L";
					}
				}
			}
		}

	}

	//integers to keep track of x and y positions in matrix
	unsigned int xlen = xstr.length(), ylen = ystr.length();
	if (xstr.length() <= 10 && ystr.length() <= 10) {
		//string variable to store a longest common subsequence in
		string lcs;
		for (unsigned int xline = 0; xline <= xstr.length(); xline++) {
			for (unsigned int yline = 0; yline <= ystr.length(); yline++) {
				output << c_table[xline][yline] << " ";
			}
			output << endl;
		}

		while (true) {
			if (b_table[xlen][ylen] == "D") {
				lcs = xstr[xlen-1] + lcs;
				xlen--;
				ylen--;
			}
			else if (b_table[xlen][ylen] == "U") {
				xlen--;
			}
			else if (b_table[xlen][ylen] == "L") {
				ylen--;
			}
			else {
				break;
			}
		}
		
		output << lcs << endl;
		//stop the clock
		auto end = chrono::high_resolution_clock::now();
		output << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " milliseconds" << endl;

	}

	else {
		//bottom right entry in table is the length of the longest common sequence
		output << c_table[xlen][ylen] << endl;
		//stop the clock
		auto end = chrono::high_resolution_clock::now();
		output << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " milliseconds" << endl;
	}

	output.close();
	return 0;
}
