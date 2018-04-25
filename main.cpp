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
#include "matrix.h"

const int MENUOPT = 2;

////////////////////////////////////////////////////////////////////////////////
//                          NON-MEMBER FUNCTION PROTOTYPES                    //
////////////////////////////////////////////////////////////////////////////////

// void readData();

void printLogo();

void printToFile(std::string& name, int& size, double& a, double& b, double& c, double& d);

void saveToFile(std::string& name, int& size, double& a, double& b, double& c, double& d);

void loadFromFile(std::vector<Matrix>& whichDatabase);

void addMatrix(std::vector<Matrix>& whichDatabase);

int menu(int &aChoice);

void printAll(std::vector<Matrix>& whichDatabase);

/*
    Function menu1 - lists all of the matrices stored in vector thisDatabase.
    
    @param no parameters
    @return none
*/
//void menu1();

/*
    Function menu2 - adds three empty matrices to thisDatabase.
    
    @param no parameters
    @return none
*/
void menu2();

////////////////////////////////////////////////////////////////////////////////
//                                  MAIN LOOP                                 //
////////////////////////////////////////////////////////////////////////////////

int main() {
    int menuChoice = 7;
    const int SIZE = 1;
    std::vector<Matrix> thisDatabase(SIZE);
    
    printLogo();
    
    while (menuChoice != 0) {
        menu(menuChoice);
        if (menuChoice == 1) {
            //List matrices
            printAll(thisDatabase);
        } else if (menuChoice == 2) {
            //Add a matrix
            addMatrix(thisDatabase);
        } 
    /* 
        else if (menuChoice == 3) {
            //Delete a matrix
            menu3(thisDatabase);
        } else if (menuChoice == 4) {
            //Edit a matrix
            menu4(thisDatabase);
        } else if (menuChoice == 5) {
            //NONE 
            menu5(thisDatabase);
        } else if (menuChoice == 6) {
            //NONE
            menu6(thisDatabase);
        }
 */
    }
    
    //loadFromFile(thisDatabase);
    
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
 
void read(){
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
                    printToFile(userName, userSize, a, b, c, d);
                    saveToFile(userName, userSize, a, b, c, d);
                }
            }
        } while (userSize == 2); 
}
 
 
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

void printToFile(std::string& name, int& size, double& a, double& b, double& c, double& d) {
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

void saveToFile(std::string& name, int& size, double& a, double& b, double& c, double& d) {
    std::ofstream outfile;
    outfile.open("loaddata.txt", std::fstream::app); // Append parameter makes it so we don't overwrite the file.
    if (outfile.fail()) {
        std::cout << "Failed to write to file. Exiting...\n";
        exit(-1);    
    }
    outfile << name << " " << size << " " << a << " " << b << " " << c << " " << d << std::endl;
}


void addMatrix(std::vector<Matrix>& whichDatabase){
    std::cout << "Creating a new matrix:" << std::endl;
    Matrix creation;
    creation.read();
    whichDatabase.push_back(creation);
}

void loadFromFile(std::vector<Matrix>& whichDatabase){
    std::ifstream fin;
    fin.open("loaddata.txt");
    
    // whichDatabase is a vector of Matrix objects
    // first, generate row vectors
    // then, generate column vectors
    
    for(int i = 0; i < 3; i++){
        addMatrix(whichDatabase);
    }
    
    /* 
    std::string tempName = "none";
    int tempSize = 6;
    //std::vector<std::vector> tempVect;
    int tempNum1 = 6;
    int tempNum2 = 6;
    
    if (fin.fail()) {
        std::cout << "Input file failed to open.\n";
        exit(-1);
    }
    //while (fin >> nextStr)  {
        fin >> tempName;
    //} 
    //double nextNum;
    //while (fin >> nextNum)  {
        //for (int i = 0; i < 3; ++i) {
            fin >> tempSize;
            fin >> tempNum1;
            fin >> tempNum2;
        //}
    //} 
    
    std::cout << tempName << tempSize << tempNum1 << tempNum2;
    fin.close();
 */
}

int menu(int &aChoice) {
    std::cout << "Please choose one of the following operations:" << std::endl;
    std::cout << "0. Exit program \n1. List matrices \n2. Add an empty matrix \nChoice (0-" << MENUOPT << "): ";
    std::cin >> aChoice;
    while (aChoice > 2){
        std::cout << "*Value entered must be between 0 and " << MENUOPT << "!*" << std::endl;
        std::cout << "Choice (0-" << MENUOPT << "): ";
        std::cin >> aChoice;
    }
    
    return aChoice;   
}

void printAll(std::vector<Matrix>& whichDatabase){
    for (int i = 0; i < (int) whichDatabase.size(); i++){
        std::cout << whichDatabase[i].getName() <<
        ", " << whichDatabase[i].getSize() << "x" << whichDatabase[i].getSize()    
        << std::endl;
        whichDatabase[i].printM();
    }
}


