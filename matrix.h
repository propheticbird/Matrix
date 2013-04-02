#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>

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

private:
    T m_matrix[ROWS][COLUMNS];
    inline void copy(T&, const T&);
    inline void swap(T&, T&);

};

template <class T>
std::ostream& operator<< (std::ostream& out, const Matrix<T>& rhs)
{
    for(int i = 0; i < Matrix<T>::ROWS; ++i)
        for(int j = 0; j < Matrix<T>::COLUMNS; ++j)
            out << rhs.m_matrix[i][j] << " ";
    return out;
}

template <class T>
Matrix<T>::Matrix()
{
    setIdentity();
}

template <class T>
Matrix<T>::Matrix(T value)
{
    for(int i = 0; i < ROWS; ++i)
        for(int j = 0; j < COLUMNS; ++j)
            m_matrix[i][j] = value;
}

template <class T>
Matrix<T>::Matrix(const Matrix &mcp)
{
    copy(m_matrix, mcp.m_matrix);
}

template <class T>
Matrix<T>& Matrix<T>::operator= (const Matrix& rhs)
{
    Matrix temp(rhs);

    T arr = m_matrix;
    m_matrix = temp.m_matrix;
    temp.m_matrix = arr;

    return *this;
}

template <class T>
inline void Matrix<T>::copy(T& dest, const T& src)
{
    for(int i = 0; i < ROWS; ++i)
        for(int j = 0; j < COLUMNS; ++j)
            dest[i][j] = src[i][j];
}

template <class T>
inline void Matrix<T>::swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}

template <class T>
void Matrix<T>::setTranspose()
{
    for(int i = 0; i < ROWS; ++i)
        for(int j = 0; j < i; j++)
            swap(m_matrix[i][j], m_matrix[j][i]);
}

template <class T>

void Matrix<T>::setIdentity()
{
    for(int i = 0; i < ROWS; ++i)
        for(int j = 0; j < COLUMNS; ++j)
            m_matrix[i][j] = 1;
}

#endif // MATRIX_H
