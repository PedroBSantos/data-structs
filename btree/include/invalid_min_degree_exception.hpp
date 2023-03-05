#ifndef INVALID_MIN_DEGREE_EXCEPTION_H
#define INVALID_MIN_DEGREE_EXCEPTION_H

#include <exception>

class InvalidMinDegreeException : public std::exception {
private:
    int degree;
public:
    InvalidMinDegreeException(int degree);
    InvalidMinDegreeException(const InvalidMinDegreeException& exception);
    virtual ~InvalidMinDegreeException() = default;
    const char* what();
};
#endif