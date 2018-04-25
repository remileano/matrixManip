
////////////////////////////////////////////////////////////////////////////////
//                             MEMBER FUNCTION DEFINITIONS                    //
////////////////////////////////////////////////////////////////////////////////
    
Matrix::Matrix(){
    _name = "unnamed";
    _size = 2;
    _vect = EMPTYCOL;
}

Matrix::Matrix(std::string name, int size, std::vector< std::vector<double> > vect){
    _name = name;
    _size = size;
    _vect = vect;
}

void Matrix::read(){
    double temp = 0.0;
    std::cout << "Enter the name for the matrix: ";
    std::cin >> std::ws;
    std::getline(std::cin, _name);
    std::cout << "Enter the size of the matrix: ";
    std::cin >> _size;
    std::vector<double> newrow;
    for (int i = 1; i < _size + 1; i++){
    std::cout << "Enter the #" << i << " row of the matrix, separated by spaces: ";
        for (int i = 1; i < _size + 1; i++){
            std::cin >> temp;
            newrow.push_back(temp);
        }
        _vect.push_back(newrow);
    }
}
    

void Matrix::printM() const{
    std::cout << "[ " << _vect[0][0] << "  " << _vect[0][1] << " ]" << std::endl << "[ " << _vect[1][0] << "  " << _vect[1][1] << " ]" << std::endl;
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
