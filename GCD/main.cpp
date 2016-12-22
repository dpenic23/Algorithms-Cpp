#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int gcd_recursive(int x, int y){
    
    if(y == 0){
        return x;
    }

    return gcd_recursive(y, x % y);

}

int gcd_iterative(int x, int y){

	while(y != 0){
		int tmp = x % y;
		x = y;
		y = tmp;
	}

    return x;
}

int main(){

    ifstream input("gcd.in");

	if(!input){
		printf("Error while reading from file.\n");
		return 0;
	}

	string str;
	while(getline(input, str)){
		istringstream ss(str);
		int x, y;
		ss >> x >> y;
		printf("%d\n", gcd_iterative(x, y));
	}


    return 0;

}
