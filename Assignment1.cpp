#include <iostream>
using namespace std;

int main(){
    
    int n =2;

    int matrixA[2][2] = {{1, 2}, {3, 4}}; // Initialize the 2 matricies
    int matrixB[2][2] = {{5, 6}, {7, 8}};

    int result[2][2] = {{0}}; // Initialize result matrix
    
    //Perform matrix multiplication
    for (int i=0; i<n; i++){
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    //printing out the result
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
    
    
    /*
    cout << "hello world" << endl;
    return 0;
    */
}