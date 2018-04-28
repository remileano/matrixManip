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

bool Matrix::load(std::ifstream& fin, std::vector<Matrix> whichDatabase){
    std::string tempName = "";
    double tempDouble = 0.0;
    std::vector<double> tempRow;
    std::vector< std::vector<double> > tempCol;
    bool nameError = false;
    
    if (fin.fail()){
        std::cout << "fin error!" << std::endl;
        return false;
    }
    
    std::getline(fin, tempName);
    while (tempName == "" || tempName == " "){
        std::getline(fin, tempName);
    }
    _name = tempName;
        for (int i = 0; i < (int) whichDatabase.size(); i++){
            if (tempName == whichDatabase[i].getName()){
                std::cout << std::endl;
                std::cout << "Could not load matrix \"" << tempName << "\". A matrix with that name already exists." << std::endl;
                nameError = true;
            }
        }
    fin >> _size;
    while (fin.good()){
    //reading the vectors
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
    }
        _vect = tempCol;
    fin.close();
    return nameError;
}

std::string Matrix::getName() const {
    return _name;
}

int Matrix::getSize() const {
    return _size;
}

void Matrix::printM() const {
    //print a column
    for (int j = 0; j < _size; j++){
        std::cout << "[ ";
        //print a row
        for (int i = 0; i < _size; i++){
            std::cout << std::scientific << std::setprecision(5);
            std::cout << std::left << std::setw(12) << _vect[j][i] << std::setw(4) << " ";
        }
        std::cout << "]\n";
    }
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
