#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

// Represents a single polynomial's item which is
// in form: c*X^p, where c is the coefficient and p is the power
struct poly_item{

    int coefficient;
    int power;

    poly_item (int coefficient, int power) : coefficient(coefficient), power(power) {}

};

// A polynomial is represented as a collection of items
typedef vector<poly_item> polynomial;

polynomial polynomials_add(polynomial& p1, polynomial& p2){

    polynomial result;
    int index1 = 0;
    int index2 = 0;

    while(index1 < p1.size() && index2 < p2.size()){
        
        if(p1[index1].power == p2[index2].power){
           int new_coeff = p1[index1].coefficient + p2[index2].coefficient;
           if(new_coeff != 0){
               poly_item item(new_coeff, p1[index1].power);
               result.push_back(item);
           }
           index1++;
           index2++;
        }else if(p1[index1].power > p2[index2].power){
            poly_item item(p2[index2].coefficient, p2[index2].power);
            result.push_back(item);
            index2++;
        }else if(p2[index2].power > p1[index1].power){
            poly_item item(p1[index1].coefficient, p1[index1].power);
            result.push_back(item);
            index1++;
        }

    }

    while(index1 < p1.size()){
        poly_item item(p1[index1].coefficient, p1[index1].power);
        result.push_back(item);
        index1++;
    }

    while(index2 < p2.size()){
        poly_item item(p2[index2].coefficient, p2[index2].power);
        result.push_back(item);
        index2++;
    }

    return result;

}

void polynomial_write(polynomial &p){
    
    for(int i = 0; i < p.size(); i++){
        int coeff = p[i].coefficient;
        int power = p[i].power;

        printf("%d*X^%d", coeff, power);
        if(i < p.size() - 1 && p[i + 1].coefficient > 0){
            printf("+");
        }
    }

    printf("\n");

}

int main(){

    ifstream input("polynomials_add.in");

	if(!input){
		printf("Error while reading from file.\n");
		return 0;
	}

    polynomial p1, p2;

    string str;
    int length, coefficient, power;

    for(int i = 0; i < 2; i++){
        getline(input, str);
        istringstream ss1(str);
        ss1 >> length;

        for(int j = 0; j < length; j++){
            getline(input, str);
            istringstream ss2(str);
            ss2 >> coefficient >> power;
            poly_item item(coefficient, power);

            if(i == 0){
                p1.push_back(item);
            }else{
                p2.push_back(item);
            }
        }
    }

    polynomial result = polynomials_add(p1, p2);
    polynomial_write(result);
    
    return 0;

}
