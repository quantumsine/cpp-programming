#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_INPUT 3
// Goal: create a 3x3 matrix determinant calculator

void matrix_init(int **matrixA){
    // Dynamically allocate memory for a 3x3 matrix
    matrixA = new int*[MAX_INPUT];
    // We need to allocate memory for each row of the matrix
    for (int i = 0; i < MAX_INPUT; i++){
      matrixA[i] = new int[MAX_INPUT];
    }
}

void determinantInput(int **matrixA){
  // Initialize the matrix
  matrix_init(matrixA);
  cout << "Please enter your matrix." << endl;

  int i, j;

  for (int i = 0; i < MAX_INPUT; i++){
    for (int j = 0; j < MAX_INPUT; j++){
    cout << "Enter element [" << i << "][" << j << "]: ";
    cin >> matrixA[i][j];
    }
  }
}

void determinantOutput(int** matrixA){
  cout << "Your matrix is:" << endl;
  
  for (int i = 0; i < MAX_INPUT; i++){
    for (int j = 0; j < MAX_INPUT; j++){
      cout << matrixA[i][j] << " ";
    }
    cout << endl;
  }
}

int matrixCalculation(int **matrixA){
  // Calculation of the matrix determinant using Sarrus' rule = aeg + bfi + cdh - ceg - bdi - afh
  // with a - h being the elements of the matrix:
  int determinant = 0;
  determinant= (matrixA[0][0] * matrixA[1][1] * matrixA[2][2]) + (matrixA[0][1] * matrixA[1][2] * matrixA[2][0]) + (matrixA[0][2] * matrixA[1][0] * matrixA[2][1])
              - (matrixA[0][2] * matrixA[1][1] * matrixA[2][0]) - (matrixA[0][1] * matrixA[1][0] * matrixA[2][2]) - (matrixA[0][0] * matrixA[1][2] * matrixA[2][1]);
  return determinant;
}


int main(){
  int **matrixA = new int*[MAX_INPUT];

  for (int i = 0; i < MAX_INPUT; i++){
    matrixA[i] = new int[MAX_INPUT];
  }

  cout << "Determinant Calculator" << endl;
  determinantInput(matrixA);
  determinantOutput(matrixA);

  // Calculate the determinant
  cout << "The determinant of the matrix is: " << matrixCalculation(matrixA) << endl;

  // Free the dynamically allocated memory
  for (int i = 0; i < MAX_INPUT; i++){
    delete[] matrixA[i];
  }
}