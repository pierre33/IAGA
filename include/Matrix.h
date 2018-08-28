/* author: Pierre Lassalle */
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include <functional>
namespace iaga{

struct matrix{
    // memeber attribute.
    std::vector< std::vector<float> > _data;
    // member methods
    matrix(unsigned int nbrows, unsigned int nbcols, float value = 0.0f);
    void print() const;
    void multiply(const float scalar);
    matrix dot(const matrix& m);
    void randomize();
    void addScalar(const float scalar);
    matrix add(const matrix& m);
    matrix sub(const matrix& m);
    matrix pmultiply(const matrix& m);
    matrix transpose() const;
    void apply(std::function<float(float)> func);
};

} // end of namespace iaga

#endif