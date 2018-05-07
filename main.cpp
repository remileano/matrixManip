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
#include <climits>
#include <string>
#include <vector>
#include <iomanip>
#include "matrix.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

const int MENUOPT = 11;

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
void drawShape();

void pascalsTriangle();

int fibonacci(int n);

////////////////////////////////////////////////////////////////////////////////
//                                  MAIN LOOP                                 //
////////////////////////////////////////////////////////////////////////////////

int main() {
    sf::RenderWindow win(sf::VideoMode(1800, 1200), "matrixManip");

    sf::RectangleShape menu1(sf::Vector2f(200, 50));
    menu1.setFillColor(sf::Color(95,75,139));
    menu1.setPosition(sf::Vector2f(260, 120));
    sf::Font font;
    font.loadFromFile("Moon2.0-Bold.otf");
    sf::Text text;
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);


    int menuChoice = INT_MAX;
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
        } else if (menuChoice == 7) {
            //Clear matrices from active list
            std::cout << "Menu doesn't exist yet." << std::endl;
        } else if (menuChoice == 8) {
            //Print out a triangle
            drawShape();
        } else if (menuChoice == 9) {
            //Print out Pascal's triangle
            pascalsTriangle();
        } else if (menuChoice == 10){
            //open graphical menu
            while (win.isOpen())
            {
                sf::Event event;
                while (win.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        win.close();
                    }
                }

                win.clear(sf::Color(188,184,201));
                win.draw(menu1);
                win.draw(text);
                win.display();
            }
        } else if (menuChoice == 11){
            //display recursive loop
            fibonacci(30);
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
    "------------------------------------------------------------------" << std::endl;
    //"******************************************************************" << std::endl;
}

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

void loadFromFile(std::vector<Matrix>& whichDatabase){
    std::string tempName = "empty";
    std::string userFile = "mysavefile.txt";
    bool nameError = false;
    int loopcount = 0;
    int tempSize = 0;
    std::cout << "Enter the name of the file to load from: ";
    std::cin >> userFile;
    std::ifstream fin;
    fin.open(userFile.c_str()); 
    if (fin.fail()) {
        std::cout << "Input file failed to open.\n";
        return;
    }
    while (fin.good()){
        tempName = "";
        tempSize = 0;
        fin >> tempName; 
        for (int i = 0; i < (int) whichDatabase.size(); i++){
            if (tempName == whichDatabase[i].getName()){
                std::cout << std::endl;
                std::cout << "Could not load matrix \"" << tempName << "\". A matrix with that name already exists." << std::endl;
                nameError = true;
                fin >> tempSize;
                Matrix temp(tempName, tempSize);
                temp.load(fin);
            }
        }
        if (tempName.length() > 0 && nameError == false){
            fin >> tempSize;
            Matrix temp(tempName, tempSize);
            temp.load(fin);
            loopcount++;
            whichDatabase.push_back(temp);
        }
        nameError = false;
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

void saveToFile(std::vector<Matrix>& whichDatabase){
    std::string userFileSave = "mysavefile2.txt";
    std::cout << "Enter the name of the file to save to: ";
    int loopcount = 0;
    //std::getline(std::cin, userFileSave);
    std::cin >> userFileSave;
    std::ofstream fout;
    fout.open(userFileSave.c_str(), std::fstream::app); // Append parameter makes it so we don't overwrite the file.
    if (fout.fail()) {
        std::cout << "Failed to write to file " << userFileSave << ". Exiting...\n";
        return;
    }
    for (int k = 0; k < (int) whichDatabase.size(); k++){
        fout << whichDatabase[k].getName() << std::endl << whichDatabase[k].getSize() << std::endl;
        //print a column
        for (int j = 0; j < whichDatabase[k].getSize(); j++){
            //print a row
            for (int i = 0; i < whichDatabase[k].getSize(); i++){
                fout << std::fixed << whichDatabase[k].getVect()[j][i]; 
                if (i == whichDatabase[k].getSize()-1){
                   fout << std::endl;
                } else {
                    fout << " ";
                }
            }
        }
        loopcount++;
        fout << std::endl;
    }
    fout.close();
    std::cout << std::endl;
    std::cout << "Successfully saved " << loopcount;
    if (loopcount == 1){
        std::cout << " matrix to ";
    } else {
        std::cout << " matrices to ";
    }
    std::cout << userFileSave << "." << std::endl;
    std::cout << std::endl;
}

int menu(int &aChoice) {
    //***COMPLETE***//
    std::cout << "Please choose one of the following operations:" << std::endl;
    std::cout << 
    std::setw(20) << std::left << "0. Exit program" << std::setw(5) << " " << "6. Mathematics menu (UNDER CONSTRUCTION) \n" <<
    std::setw(20) << std::left << "1. List matrices" << std::setw(5) << " " << "7. Clear all (UNDER CONSTRUCTION) \n" <<
    std::setw(20) << std::left << "2. Add a new matrix" << std::setw(5) << " " << "8. Draw a shape (UNDER CONSTRUCTION) \n" <<
    std::setw(20) << "3. Delete a matrix" << std::setw(5) << " " << "9. Pascal's Triangle (UNDER CONSTRUCTION) \n"<<
    std::setw(20) << "4. Load from file" << std::setw(5) << " " << "10. Open GUI (UNDER CONSTRUCTION) \n"<<
    std::setw(20) << "5. Save to file" << std::setw(5) << " " << "11. Recursion (UNDER CONSTRUCTION) \n"<<
    "------------------------------------------------------------------" << std::endl <<
    "Choice (0-" << MENUOPT << "): ";
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

void drawShape(){
    int length = 0;
    std::cout << "Please enter a non-zero integer value: ";
    std::cin >> length;
    int distance = 0;
    int variable = length;
    
    for (int i = 0; i <= length; i++){
        distance = i;
        variable = length - i;
        for (int k = 0; k < distance; k++){
            std::cout << std::setw(2) << " ";
        }
        for (int l = 0; l < length - i; l++){
            std::cout << std::setw(4) << variable;
        }
        std::cout << std::endl;
    }
}

int fibonacci(int n){
    if(n <= 0){
        return 0;
    } else if (n == 1 || n == 2){
        return 1;
    } else {
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}

void pascalsTriangle(){
    int distance = 0;
    int variable = 0;
    int input = 0;
    int rowcount = 0;
    std::cout << "Please enter a positive, nonzero integer: ";
    std::cin >> input;
    for (int x = input; x > 1; x--){
       // for (int i = 0; i <= input; i++){
            distance = x;
            variable = input - x;
            for (int k = 0; k < distance; k++){
                std::cout << std::setw(2) << " ";
            }
            for (int l = 0; l < input - x; l++){
                if (rowcount == 0){
                    std::cout << std::setw(4) << 1;
                } else {
                    std::cout << std::setw(4) << fibonacci(x);
                }
                rowcount++;
            }
            rowcount = 0;
            std::cout << std::endl;
        //}
    }
}


