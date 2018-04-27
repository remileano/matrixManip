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
#include <climits>

const int MENUOPT = 6;

////////////////////////////////////////////////////////////////////////////////
//                          NON-MEMBER FUNCTION PROTOTYPES                    //
////////////////////////////////////////////////////////////////////////////////

// void readData();

void printLogo();

void printToFile(std::string& name, int& size, double& a, double& b, double& c, double& d);

void saveToFile(std::vector<Matrix>& whichDatabase);

void loadFromFile(std::vector<Matrix>& whichDatabase);

void addMatrix(std::vector<Matrix>& whichDatabase);

void deleteMatrix(std::vector<Matrix>& whichDatabase);

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
    const int SIZE = 0;
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
        } else if (menuChoice == 3) {
            //Delete a matrix
            deleteMatrix(thisDatabase);
        } else if (menuChoice == 4) {
            //Load from a file
            loadFromFile(thisDatabase);
        } else if (menuChoice == 5) {
            //Save to a file
            saveToFile(thisDatabase);
        } else if (menuChoice == 6) {
            //Open MATH menu
            std::cout << "Menu doesn't exist yet." << std::endl;
        }
    }
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//                         NON-MEMBER FUNCTION DEFINITIONS                    //
////////////////////////////////////////////////////////////////////////////////
 
void printLogo(){
    //***COMPLETE***//
    std::cout <<
    "                 _        _                         _"    << std::endl <<
    " _ __ ___   __ _| |_ _ __(_)_  __ /\\/\\   __ _ _ __ (_)_ __ " << std::endl <<
    "| '_ ` _ \\ / _` | __| '__| \\ \\/ //    \\ / _` | '_ \\| | '_ \\ " << std::endl << 
    "| | | | | | (_| | |_| |  | |>  </ /\\/\\ \\ (_| | | | | | |_) |" << std::endl << 
    "|_| |_| |_|\\__,_|\\__|_|  |_/_/\\_\\/    \\/\\__,_|_| |_|_| .__/ " << std::endl << 
    "                                                     |_|    2018" << std::endl << 
    "******************************************************************" << std::endl;
}

/* 
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

*/

void addMatrix(std::vector<Matrix>& whichDatabase){
    //***COMPLETE***//
    std::cout << "Creating a new matrix." << std::endl << std::endl;
    Matrix creation;
    creation.read(whichDatabase);
    whichDatabase.push_back(creation);
    std::cout << "New matrix, \"" << creation.getName() << "\", created." << std::endl << std::endl;
}

void deleteMatrix(std::vector<Matrix>& whichDatabase){
    bool found = false;
    std::string deleter = "";
    int deletePos = INT_MAX;
    std::cout << "Deleting an existing matrix." << std::endl << std::endl;
    printAll(whichDatabase);
    if (whichDatabase.size() < 1){
        return;
    }
    std::cout << "Enter the name of the matrix to delete: ";
    std::cin >> deleter;
    for (int i = 0; i < (int) whichDatabase.size(); i++){
        if (whichDatabase[i].getName() == deleter){
            found = true;
            deletePos = i;
            for (unsigned j = deletePos; j < whichDatabase.size() - 1; j++) {
                whichDatabase[j] = whichDatabase[j+1];
            }
            whichDatabase.pop_back();
            std::cout << "Matrix \"" << deleter << "\" was successfully deleted." << std::endl;
        }
    }
    
    if (!found){
        std::cout << "\"" << deleter << "\" did not match the names of any matrices in the database. No matrices were deleted." << std::endl;
    }
    
    std::cout << std::endl;
}

void saveToFile(std::vector<Matrix>& whichDatabase){
    std::string userFile = "";
    std::cout << "Enter the name of the file to save to: ";
    std::cin >> std::ws;
    int loopcount = 0;
    std::getline(std::cin, userFile);
    std::ofstream fout;
    fout.open(userFile, std::fstream::app); // Append parameter makes it so we don't overwrite the file.
    if (fout.fail()) {
        std::cout << "Failed to write to file. Exiting...\n";
        return;
    }
    while (fout.good()){
        for (int i = 0; i < (int) whichDatabase.size(); i++){
            fout << whichDatabase[i].getName() << std::endl << whichDatabase[i].getSize();
        }
    }
    std::cout << std::endl;
    std::cout << "Successfully saved " << loopcount;
    if (loopcount == 1){
        std::cout << " matrix to ";
    } else {
        std::cout << " matrices to ";
    }
    std::cout << userFile << "." << std::endl;
    fout.close();
    std::cout << std::endl;
}

void loadFromFile(std::vector<Matrix>& whichDatabase){
    //***COMPLETE***//
    std::string userFile = "";
    std::cout << "Enter the name of the file to load from: ";
    std::cin >> std::ws;
    int loopcount = 0;
    std::getline(std::cin, userFile);
    std::ifstream fin;
    fin.open(userFile);
    if (fin.fail()) {
        std::cout << "Input file failed to open.\n";
        return;
        //exit(-1);
    }
    while (fin.good()){
        Matrix temp;
        if (!temp.load(fin, whichDatabase)){
            loopcount++;
            whichDatabase.push_back(temp);
        }
    }
    std::cout << std::endl;
    std::cout << "Successfully added " << loopcount;
    if (loopcount == 1){
        std::cout << " matrix from ";
    } else {
        std::cout << " matrices from ";
    }
    std::cout << userFile << "." << std::endl;
    fin.close();
    std::cout << std::endl;
}

int menu(int &aChoice) {
    //***COMPLETE***//
    std::cout << "Please choose one of the following operations:" << std::endl;
    std::cout << "0. Exit program \n1. List matrices \n2. Add a new matrix \n3. Delete a matrix \n4. Load from file \n5. Save to file (UNDER CONSTRUCTION) \n6. Mathematics menu (UNDER CONSTRUCTION) \nChoice (0-" << MENUOPT << "): ";
    std::cin >> aChoice;
    while (aChoice > MENUOPT){
        std::cout << "*Value entered must be between 0 and " << MENUOPT << "!*" << std::endl;
        std::cout << "Choice (0-" << MENUOPT << "): ";
        std::cin >> aChoice;
    }
    return aChoice;   
}

void printAll(std::vector<Matrix>& whichDatabase){
    //***COMPLETE***//
    if (whichDatabase.size() == 0){
        std::cout << "No entries." << std::endl;
    } else {
        for (int i = 0; i < (int) whichDatabase.size(); i++){
            std::cout << std::endl;
            std::cout << whichDatabase[i].getName() <<
            ", " << whichDatabase[i].getSize() << "x" << whichDatabase[i].getSize()    
            << std::endl;
            whichDatabase[i].printM();
        }
    }
    std::cout << std::endl;
}


