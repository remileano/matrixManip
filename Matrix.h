#ifndef MATRIX_H
#define MATRIX_H

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
        void printM() const;
        void read();
    private:
        std::string _name;
        int _size;
        std::vector< std::vector<double> > _vect;
        
};

#endif
