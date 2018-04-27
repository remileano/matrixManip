#include <iostream>
#include <vector>
#include "matrix.h"
#include <iomanip>
#include <sstream> 
#include <fstream>

////////////////////////////////////////////////////////////////////////////////
//                                GLOBAL CONST                                //
////////////////////////////////////////////////////////////////////////////////

const std::vector<double> EMPTYROW = {1.0, 2.0}; // empty row vector

const std::vector< std::vector<double> > EMPTYCOL = {EMPTYROW, EMPTYROW}; // empty col vector
const std::vector< std::vector<double> > ACTUALLY_EMPTY; // actually empty

////////////////////////////////////////////////////////////////////////////////
//                             MEMBER FUNCTION DEFINITIONS                    //
////////////////////////////////////////////////////////////////////////////////
    
Matrix::Matrix() {
    _name = "unnamed";
    _size = 2;
    _vect = ACTUALLY_EMPTY;
}

Matrix::Matrix(std::string name, int size, std::vector< std::vector<double> > vect) {
    _name = name;
    _size = size;
    _vect = vect;
}

void Matrix::read(std::vector<Matrix> whichDatabase) {
    bool sizeError = true;
    bool nameError = true;
    std::string tempName = "";
    double temp = 0.0;
    int max = whichDatabase.size();
    while (nameError){
        std::cout << "Enter the name for the matrix: ";
        std::cin >> std::ws;
        std::getline(std::cin, tempName);
        if (max == 0){
            _name = tempName;
            nameError = false;
        } else {
            for (int i = 0; i < max; i++){
                if (tempName == whichDatabase[i].getName()){
                    std::cout << "A matrix already exists in your current database with that name. Please choose another." << std::endl;
                } else {
                    _name = tempName;
                    nameError = false;
                }
            }
        }
    }
    
    while (sizeError){
        std::cout << "Enter the size of the matrix: ";
        std::cin >> _size;
        if (_size == 0){
            std::cout << "Matrix dimension cannot be zero." << std::endl;
        } else if (_size > 2){
            std::cout << "The current program cannot handle matrices greater than 2." << std::endl;
        } else {
            sizeError = false;
        }
    }
    
    std::vector<double> newrow;
    for (int i = 1; i < _size + 1; i++) {
    std::cout << "Enter the #" << i << " row of the matrix, separated by spaces: ";
        for (int i = 0; i < _size; i++) {
            std::cin >> temp;
            newrow.push_back(temp);
        }
        _vect.push_back(newrow);
        for (int i = 0; i < _size; i++) {
            newrow.pop_back();
        }
    }
}

void Matrix::load(std::ifstream& fin){
    std::string tempName = "";
    double tempDouble = 0.0;
    std::vector<double> tempRow;
    std::vector< std::vector<double> > tempCol;
    std::getline(fin, tempName);
    _name = tempName;
    fin >> _size;
    //reading the vectors
    while (fin.good()){
        for (int j = 0; j < (int) _size; j++){
            for (int i = 0; i < (int) _size; i++){
                fin >> tempDouble;
                //std::cout << tempDouble;
                tempRow.push_back(tempDouble);
            }
            tempCol.push_back(tempRow);
            //reset tempRow
            while (tempRow.size() > 0){
                tempRow.pop_back();
            }
        }  
        _vect = tempCol;
    }
    fin.close();
}
    

void Matrix::printM() const {
// we need to make it print out a consistent size so that it looks nice
    std::cout << "[ " << std::fixed << std::setprecision(5) << _vect[0][0] << "  " << _vect[0][1] << " ]" << std::endl << "[ " << _vect[1][0] << "  " << _vect[1][1] << " ]" << std::endl;
}

std::string Matrix::getName() const {
    return _name;
}

int Matrix::getSize() const {
    return _size;
}

std::vector< std::vector<double> > Matrix::getVect() const {
    return _vect;
}

void Matrix::setName(std::string newName) {
    _name = newName;
}

void Matrix::setVect(std::vector< std::vector<double> > newVect) {
    _vect = newVect;
}
