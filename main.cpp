/*
    CS-11 Final project, matrixManip
    Purpose: Manipulate matrices.

    @author Cesar Amaral, Remi Leano
    @version 1.0 04/22/2018
*/

////////////////////////////////////////////////////////////////////////////////
//                                  INCLUDE                                   //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>   // for file I/O
#include <cstdlib>   // for exit()
#include <vector>

////////////////////////////////////////////////////////////////////////////////
//                              CLASS DECLARATIONS                            //
////////////////////////////////////////////////////////////////////////////////

class Matrix {
    public:
        Matrix();
        Matrix(std::string name, int size, std::vector vect);
        // The size attribute is constant and cannot be changed.
        std::string getName() const;
        int getSize() const;
        std::vector getVect() const;
        void setName(string newName);
        void setVect(std::vector newVect);
    private:
        std::string _name;
        int _size;
        std::vector _vect;
};

////////////////////////////////////////////////////////////////////////////////
//                             MEMBER FUNCTION DEFINITIONS                    //
////////////////////////////////////////////////////////////////////////////////
    
Matrix::Matrix(){
    _name = "unnamed";
    _size = 0;
    _vect = std::vector<std::vector> myVect(_size);
}

Matrix::Matrix(std::string name, int size, std::vector vect){
    _name = name;
    _size = size;
    _vect = vect;
}

std::string Matrix::getName {
    return _name;
}

int getSize() const {
    return _size;
}

std::vector getVect() const {
    return _vect;
}

void setName(std::string newName) {
    _name = newName;
}

void setVect(std::vector newVect) {
    _vect = newVect;
}


////////////////////////////////////////////////////////////////////////////////
//                          NON-MEMBER FUNCTION PROTOTYPES                    //
////////////////////////////////////////////////////////////////////////////////

// void readData();

void printLogo();

////////////////////////////////////////////////////////////////////////////////
//                                  MAIN LOOP                                 //
////////////////////////////////////////////////////////////////////////////////

int main() {
    printLogo();
    
    
     
    // readData();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//                         NON-MEMBER FUNCTION DEFINITIONS                    //
////////////////////////////////////////////////////////////////////////////////

/* 
void readData(){
    ifstream fin;
    fin.open("rawdata.txt");
    if (fin.fail()) {
        cout << "Input file failed to open.\n";
        exit(-1);
    }
    double nextNum;
    while (fin >> nextNum)  {
        cout << "Read: " << nextNum << endl;
    } 
    fin.close();
}
 */
 
 
void printLogo(){
    std::cout <<
    "                 _        _                         _"    << std::endl <<
    " _ __ ___   __ _| |_ _ __(_)_  __ /\\/\\   __ _ _ __ (_)_ __ " << std::endl <<
    "| '_ ` _ \\ / _` | __| '__| \\ \\/ //    \\ / _` | '_ \\| | '_ \\ " << std::endl << 
    "| | | | | | (_| | |_| |  | |>  </ /\\/\\ \\ (_| | | | | | |_) |" << std::endl << 
    "|_| |_| |_|\\__,_|\\__|_|  |_/_/\\_\\/    \\/\\__,_|_| |_|_| .__/ " << std::endl << 
    "                                                     |_|    2018" << std::endl;
}
    
 
