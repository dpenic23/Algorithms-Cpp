/*
 * Domagoj Penić
 * 0036477119
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int num_of_nodes;
vector< vector<int> > adjacency_matrix;

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

int longest_cycle(){
	return 0;
}

/*
 * Main function, called once the program is run. The program takes
 * only one argument, absolute path to the file where the adjacency
 * matrix is stored.
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
