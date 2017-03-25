#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector< vector<int> > adjacency_matrix;

int main(int argc, char* argv[]){

	// First argument is the program name and second one is a file path
	if(argc != 2){
		printf("Invalid number of command line arguments.\n");
		return 0;
	}

	// Path to the input file
    ifstream input(argv[1]);

	if(!input){
		printf("Error while reading from file.\n");
		return 0;
	}

	int num_of_nodes;
	input >> num_of_nodes;

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

	for(int i = 0; i < num_of_nodes; i++){
		for(int j = 0; j < adjacency_matrix[i].size(); j++){
			cout << adjacency_matrix[i][j];
		}
		cout << endl;
	}

    return 0;

}
