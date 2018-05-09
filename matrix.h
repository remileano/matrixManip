#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

////////////////////////////////////////////////////////////////////////////////
//                              CLASS DECLARATIONS                            //
////////////////////////////////////////////////////////////////////////////////

class Matrix {
    public:
        // Constructors
        Matrix();
        Matrix(std::string name, int size, std::vector< std::vector<double> > vect);
        Matrix(std::string name, int size);
        // The size attribute is constant and cannot be changed.
        std::string getName() const;
        int getSize() const;
        std::vector< std::vector<double> > getVect() const;
        void setName(std::string newName);
        void setVect(std::vector< std::vector<double> > newVect);
        /* Method printM - prints out the columns and rows of a matrix to cout.
         * @param no parameters
         * @return void
         */
        void printM() const;
        /* Method read - prompts the user for information about a new matrix.
         * Generates the rows and columns of the matrix based on user entry.
         * Checks the database before allowing a name to be used, to ensure
         * that no redundancies are created.
         * @param the active database
         * @return void
         */
        void read(std::vector<Matrix> whichDatabase);
        /* Method load - reads in the matrix entries (rows and columns) stored
         * in the .txt file linked to the ifstream.
         * @param the ifstream linked to the .txt
         * @return void
         */
        void load(std::ifstream& fin);
    private:
        std::string _name;
        int _size;
        std::vector< std::vector<double> > _vect;
        
};

#endif
