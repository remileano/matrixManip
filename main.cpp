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
        Matrix(std::string name, int size, std::vector< std::vector<double> > vect);
        // The size attribute is constant and cannot be changed.
        std::string getName() const;
        int getSize() const;
        std::vector< std::vector<double> > getVect() const;
        void setName(std::string newName);
        void setVect(std::vector< std::vector<double> > newVect);
    private:
        std::string _name;
        int _size;
        std::vector< std::vector<double> > _vect;
};

////////////////////////////////////////////////////////////////////////////////
//                             MEMBER FUNCTION DEFINITIONS                    //
////////////////////////////////////////////////////////////////////////////////
    
Matrix::Matrix(){
    _name = "unnamed";
    _size = 0;
    _vect = empty(_size);
}

Matrix::Matrix(std::string name, int size, std::vector< std::vector<double> > vect){
    _name = name;
    _size = size;
    _vect = vect;
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
    
 
