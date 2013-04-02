#ifndef MATRIX_H
#define MATRIX_H

#include <iosfwd>
#include <exception>

template <class T>
class Matrix
{
    friend std::ostream operator<< (std::ostream&, const Matrix<T>&);

    static const int ROWS = 4;
    static const int COLUMNS = 4;

    enum Directions
    {
        X_AXIS,
        y_AXIS,
        Z_AXIS
    };

public:
    Matrix(); // default constructor sets matrix identity
    Matrix(T);
    Matrix(const Matrix&);

    Matrix&  operator= (const Matrix&);

    void setTranspose();
    void setIdentity();

    void setRotate(Directions, double);
    void setScale(double, double, double);
    void setTranslation(double, double, double);

    bool isOrthogonal() const;

    class InitializationError : public std::exception
    {
    };

private:
    T m_matrix[ROWS][COLUMNS];
    inline void copy(T&, const T&);
    inline void swap(T&, T&);

};

#endif // MATRIX_H
