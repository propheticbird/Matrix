#include "matrix.h"

template <class T>
std::ostream& operator<< (std::ostream& out, const Matrix<T>& rhs)
{
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
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
