/* CS-11 Final project, matrixManip
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
#include <iomanip>

////////////////////////////////////////////////////////////////////////////////
//                                GLOBAL CONST                                //
////////////////////////////////////////////////////////////////////////////////

const std::vector<double> EMPTYCOL(0); // empty column vector

const std::vector<std::vector<double>> EMPTYROW; // empty row vector

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
        void setVect(std::vector<std::vector<double>> newVect);
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
    _vect = EMPTYROW;
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

void writeToFile(std::string& name, int& size, double& a, double& b, double& c, double& d);
////////////////////////////////////////////////////////////////////////////////
//                                  MAIN LOOP                                 //
////////////////////////////////////////////////////////////////////////////////

int main() {
    printLogo();
    
    int userSize = 0;
    std::string userName = "unnamed";
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double d = 0.0;
    bool correctness = false;
    do {
        std::cout << "Please enter the name for your matrix: ";
        std::cin >> userName;
        std::cout << "Please enter the size of your matrix: ";
        std::cin >> userSize;
    
        if (userSize == 2){
            std::cout << "[ " << " a " << " b " << " ]" << std::endl;
            std::cout << "[ " << " c " << " d " << " ]" << std::endl;
            std::cout << "Please enter the entries of your matrix in order (alphabetical), with entries separated by spaces: ";
            std::cin >> a >> b >> c >> d;
            std::cout << std::setprecision(2);
            std::cout << std::setprecision(2) << "[  " << a << "  " << b << "  ]" << std::endl;
            std::cout << "[  " << c << "  " << d << "  ]" << std::endl;
            std::cout << "Is this correct? (1=true/0=false): ";
            std::cin >> correctness;
            if (correctness) {
                std::cout << "you entered: true" << std::endl;
                writeToFile(userName, userSize, a, b, c, d);
            }
        }
    } while (userSize == 2); 
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
    "                                                     |_|    2018" << std::endl << 
    "******************************************************************" << std::endl;
}

void writeToFile(std::string& name, int& size, double& a, double& b, double& c, double& d) {
    std::ofstream outfile;
    outfile.open("output.txt", std::fstream::app); // Append parameter makes it so we don't overwrite the file.
    if (outfile.fail()) {
        std::cout << "Failed to write to file. Exiting...\n";
        exit(-1);    
    }
    outfile << "Matrix Name: " << name << "\nMatrix Size: " << size
            << "\nMatrix: [" << a << " " << b << "]\n\t\t[" << c << " " << d
            << "]\n" << std::endl;
}

//void addMatrix(){} 
