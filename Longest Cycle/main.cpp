/*
 * Domagoj Penić
 * 0036477119
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int num_of_nodes;
vector< vector<int> > adjacency_matrix;

vector<int> cycle_lengths;

/*
 * Function takes absolute path to the file where the adjacency matrix
 * is stored and reads the data into the previously allocated memory.
 * Function returns 1 if the reading went successfully, 0 otherwise.
 */
int read_matrix(char* path){

	ifstream input(path);

	if(!input){
		return 0;
	}
	
	// Read the total number of nodes
	input >> num_of_nodes;

	// Read the adjacency matrix
	for(int i = 0; i < num_of_nodes; i++){
		vector<int> adjacency_vector;

		int is_neighbour;
		for(int j = 0; j < num_of_nodes; j++){
			input >> is_neighbour;
			
			if(is_neighbour){
				adjacency_vector.push_back(j);
			}
		}

		adjacency_matrix.push_back(adjacency_vector);
	}

	return 1;
}

/*
 * Recursive function which finds all the cycle lengths for which
 * v_0 = v_n = node_index.
 */
 void cycle_rec(int start_node, int current_node, set<int>& visited, int length){

	if(start_node == current_node && length > 0){
		cycle_lengths.push_back(length);
		return;
	}

	visited.insert(current_node);
	vector<int> neighbours = adjacency_matrix[current_node];

	for(int i = 0; i < neighbours.size(); i++){
		bool is_visited = visited.find(neighbours[i]) != visited.end();
		if(!is_visited || neighbours[i] == start_node){
			cycle_rec(start_node, neighbours[i], visited, length + 1);
		}
	}
}

/*
 * Function which calculates the longest cycle in a simple graph.
 */
int longest_cycle(){

	// Find the lengths of all the cycles
	for(int i = 0; i < num_of_nodes; i++){
		set<int> visited;
		cycle_rec(i, i, visited, 0);
	}
	
	// Find the longest cycle
	int longest = 0;
	for(int i = 0; i < cycle_lengths.size(); i++){
		if(cycle_lengths[i] > longest){
			longest = cycle_lengths[i];
		}
	}

	return longest;
}

/*
 * Main function, called once the program is run. The program takes
 * only one argument, absolute path to the file where the adjacency
 * matrix is stored and prints the length of the longest cycle in the
 * specified graph.
 */
int main(int argc, char* argv[]){

	if(argc != 2){
		printf("Invalid number of command line arguments.\n");
		return 0;
	}

	if(!read_matrix(argv[1])){
		printf("Error occurred while reading from file.\n");
		return 0;
	}

	int result = longest_cycle();
	cout << result << endl;

    return 0;

}
