#include "Matrix.h"
#include <assert.h>
#include <utility>
#include <iostream>

Matrix::Matrix(int nRows, int nColumns) 
    : rows(nRows), columns(nColumns) {
    assert(nRows >= 0 || nColumns <= 0);    
    for (int i = 0; i < nRows*nColumns; i++) {
        MxN[i] = 0;
    }
    // for (int k = 0; k < nRows*nColumns; k++) { //DEBUG
    //     std::cout << MxN[k] + k << std::endl;    
    // } 
}

Matrix::Matrix(int nRows) 
    : rows(nRows), columns(nRows) {
    assert(nRows >= 0);
    // double *MxN = new double[nRows*nRows]; // WARNING not used?
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nRows; j++) {
            if (i == j) {
                // std::cout << "i == j" << std::endl; // DEBUG
                MxN[j + nRows*i] = 1;
            } else {
                // std::cout << "i != j" << std::endl; // DEBUG
                MxN[j + nRows*i] = 0;
            }
        }
    }
    // for (int k = 0; k < nRows*nRows; k++) { //DEBUG
    //     std::cout << MxN[k] << std::endl;    
    // } 
}

Matrix::Matrix(const Matrix &rhs) : rows(rhs.rows), columns(rhs.columns) {
    this->MxN = new double[rows*columns];
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            MxN[count] = rhs.get(i, j);
            count++;
            // std::cout << i << " " << j;
        }
    }
}

// Matrix &Matrix::operator=(const Matrix rhs) {
//     int count = 0;
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < columns; j++) {
//             MxN[count] += rhs.get(i, j);
//             count++;
//         }
//     }
//     std::cout << "j";
//     return *this;
// }

Matrix& Matrix::operator+=(const Matrix& rhs) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
             MxN[i*rows+j] += rhs.get(i, j);
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) {
    Matrix temp{rows,columns};
    double tempValue = 0; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
             tempValue = rhs.get(i, j) + MxN[i*rows+j];
             temp.set(i,j,tempValue);
        }
    }
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Matrix& d) {
    for (int i = 0; i < d.getRows(); i++) {
        for (int j = 0; j < d.getColumns(); j++) {
            std::cout << d.get(i, j) << " ";
        }
        os << std::endl;
    }    
    return os;
}

double Matrix::get(int row, int col) const {
    return Matrix::MxN[Matrix::rows*row + col];
}

void Matrix::set(int row, int col, double value) {
    Matrix::MxN[row*(Matrix::rows) + col] = value;
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

Matrix::~Matrix() {
    delete[] MxN;
}



