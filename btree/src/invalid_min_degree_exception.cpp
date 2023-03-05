#include "../include/invalid_min_degree_exception.hpp"

InvalidMinDegreeException::InvalidMinDegreeException(int degree) {
    this->degree = degree;
}

InvalidMinDegreeException::InvalidMinDegreeException(const InvalidMinDegreeException& exception) {
    this->degree = exception.degree;
}

const char* InvalidMinDegreeException::what() {
    return "Invalid tree degree";
}