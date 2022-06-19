#pragma once
#include <iostream>

class Matrix {
    private:
        int rows, columns;
        double *MxN = new double[rows*columns];
    public:
        // CONSTRUCTORS
        Matrix(int nRows, int nColumns);
        Matrix(int nRows);
        // COPY CONSTRUCTOR
        Matrix(const Matrix & rhs);
        
        // OVERLOADING
        Matrix& operator=(Matrix rhs);
        Matrix& operator+=(const Matrix& rhs);
        Matrix operator+(const Matrix& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Matrix& d);
        
        // GET FUNCTIONS
        double get(int row, int col) const;
        int getRows() const;
        // SET FUNCTIONS
        void set(int row, int col, double value);
        int getColumns() const;

        // DESTRUCTOR
        ~Matrix();
};

