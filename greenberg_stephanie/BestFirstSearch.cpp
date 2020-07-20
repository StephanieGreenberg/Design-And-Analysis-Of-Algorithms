#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

/* node struct to keep track of each node's information including
 * level, profit, weight, bound, and the nodes that are included in
 * the current solution*/
struct node {
	int level;
	int profit;
	int weight;
	float bound;
	vector<int> included;

	//default node constructor
	node() {
		level = 0;
		profit = 0;
		weight = 0;
		bound = 0;
	}

	//constructor to set all values except vector
	node(int l, int p, int w, float b) {
		level = l;
		profit = p;
		weight = w;
		bound = b;
	}
};

/* custom comparator function to compare nodes in the priority queue, used
 * when declaring the priority queue */
struct compare_nodes {
	bool operator() (node& n1, node& n2) {
		return n1.bound < n2.bound;
	}
};

/* function to calculate the bound of a node given the weight limit of the knapsack,
 * the weight and profit of the current solution, and the remaining items that have not
 * yet been explored */
float bound(int weight_limit, int profit, int weight, vector<pair<int, int>> remaining_items) {
	float bound = profit;
	weight_limit -= weight;
	//loop through remaining items to get the bound
	for (auto item : remaining_items) {
		if (weight_limit > 0) {
			/*if an item in remaining items can fit in the knapsack, add it
			to the knapsack*/
			if (item.first <= weight_limit) {
				bound += item.second;
				weight_limit -= item.first;
			}
			/*otherwise, if the item's whole weight doesn't fit in the knapsack
			only add a fraction of it that will fit*/
			else {
				bound += (float)weight_limit * ((float)item.second / (float)item.first);
			}
		}
	}
	return bound;	
}

//function to sort the items from the input file by profit over weight
bool sort_profit_over_weight(pair <int, int> p1, pair<int, int> p2) {
	float pw1 = (float)p1.second / (float)p1.first;
	float pw2 = (float)p2.second / (float)p2.first;
	return pw1 > pw2;
}

int main(int argc, char *argv[]) {
	//get input file stream
	ifstream input(argv[1]);
	//get output file stream
	ofstream output(argv[2]);

	//just used to hold the comma in between values
	char comma;
	/*num_items and weight_limit are for the values in first line of input file,
	weight and limit are for parsing the items in the rest of the file*/
	int num_items, weight_limit, weight, profit;
	//vector to hold the items, which are represented by a pair of weight and profit
	vector<pair<int, int>> items;
	
	//get the values from the first line
	input >> num_items >> comma >> weight_limit;

	//go through the rest of the input file and add the items to the vector
	while (input >> weight >> comma >> profit) {
		items.push_back(pair<int, int>(weight, profit));
	}
	
	//close the input stream
	input.close();
	
	/* variables to keep track of total number of  nodes visited by the algorithm,
	 * total number of leaf nodes visited, the best node found so far, and a priority
	 * queue for the nodes as we traverse the tree */
	int nodes_visited = 0;
	int leaf_nodes_visited = 0;
	node best;

	/*sort the vector of items by profit/weight using custom comparator function
	called sort_profit_over_weight*/
	sort(items.begin(), items.end(), sort_profit_over_weight);
	
	//initialize the root node and add it to the priority queue
	node root(-1, 0, 0, bound(weight_limit, 0, 0, items));
	priority_queue<node, vector<node>, compare_nodes> pq;
	pq.push(root);
	
	//this is where most of the algorithm is implemented
	
	//while the priority queue is not empty, pop the next element off the top of the queue
	while (!pq.empty()) {
		node current = pq.top();
		pq.pop();
		nodes_visited++;
		
		//if the current node is promising
		if (current.weight < weight_limit && current.bound >= best.profit) {
			//if the current node's profit is better than the current best profit, set best to current
			if (current.profit > best.profit) {
				best = current;
			}
			//if there are still items remaining
			if (current.level + 1 < num_items) {
				//create a vector of remaining items in order to get the bound of the current node
				vector<pair<int,int>> remaining_items;
				for (int i = current.level + 2; i <  num_items; i++) {
					remaining_items.push_back(items[i]);
				}
				//node with the following item added to the solution
				node n1 = node(current.level+1, current.profit + items[current.level+1].second, current.weight + items[current.level+1].first, 0);
				//same as the current node but one level higher
				node n2 = node(current.level+1, current.profit, current.weight, 0);

				//for each of these nodes, get their bounds and for the first node, include
				//the next item in its included vector
				n1.bound = bound(weight_limit, n1.profit, n1.weight, remaining_items);
				n1.included = current.included;
				n1.included.push_back(current.level+1);
				n2.bound = bound(weight_limit, n2.profit, n2.weight, remaining_items);
				n2.included = current.included;

				pq.push(n1);
				pq.push(n2);
			}
			else {
				//no more items remaining to look at
				leaf_nodes_visited++;
			}
		}
		else {
			//node does not represent a solution
			leaf_nodes_visited++;
		}
	}
	
	//append the appropriate data to the output file specified in the command line
	output << num_items << "," << best.profit << "," << best.included.size() << endl;
	output << nodes_visited << "," << leaf_nodes_visited << endl;

	for (int num : best.included) {
		output << items[num].first << "," << items[num].second << endl;
	}

	output.close();
}
