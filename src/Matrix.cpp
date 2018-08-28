/* author: Pierre Lassalle */
#include "Matrix.h"

namespace iaga{

    matrix::matrix(unsigned int nbrows, unsigned int nbcols, float value)
    {
        assert(nbrows > 0 && nbcols > 0);
        _data = std::vector< std::vector<float> >(nbrows, std::vector<float>(nbcols, value));
    }

    void matrix::print() const
    {
        for(const auto& row : _data){
            for(const auto& val : row){
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    void matrix::multiply(const float scalar)
    {
        for(auto& row : _data){
            for(auto& val: row){
                val *= scalar;
            }
        }
    }

    matrix matrix::dot(const matrix& m)
    {
        assert(_data.size() > 0 && _data[0].size() > 0);
        assert(m._data.size() > 0 && m._data[0].size() > 0);
        assert(_data[0].size() == m._data.size());
        auto res = matrix(_data.size(), m._data[0].size());
        for(unsigned int r = 0; r < _data.size(); r++){
            for(unsigned int c = 0; c < m._data[0].size(); c++){
                for(unsigned int k = 0; k < _data[r].size(); k++){
                    res._data[r][c] += _data[r][k] * m._data[k][c];
                }
            }
        }
        return res;
    }

    void matrix::randomize()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(-1.0f, 1.0f);
        for(auto& row : _data){
            for(auto& val : row){
                val = dis(gen);
            }
        }
    }

    void matrix::addScalar(const float scalar)
    {
        for(auto& row : _data){
            for(auto& val : row){
                val += scalar;
            }
        }
    }

    matrix matrix::add(const matrix& m)
    {
        assert(_data.size() > 0 && _data[0].size() > 0);
        assert(m._data.size() > 0 && m._data[0].size() > 0);
        assert(_data.size() == m._data.size() && _data[0].size() == m._data[0].size());
        auto res = matrix(_data.size(), _data[0].size());
        for(unsigned int r = 0; r <_data.size(); r++){
            for(unsigned int c = 0; c < _data[r].size(); c++){
                res._data[r][c] = _data[r][c] + m._data[r][c];
            }   
        }
        return res;
    }

    matrix matrix::sub(const matrix& m)
    {
        assert(_data.size() > 0 && _data[0].size() > 0);
        assert(m._data.size() > 0 && m._data[0].size() > 0);
        assert(_data.size() == m._data.size() && _data[0].size() == m._data[0].size());
        auto res = matrix(_data.size(), _data[0].size());
        for(unsigned int r = 0; r <_data.size(); r++){
            for(unsigned int c = 0; c < _data[r].size(); c++){
                res._data[r][c] = _data[r][c] - m._data[r][c];
            }   
        }
        return res;
    }

    matrix matrix::pmultiply(const matrix& m)
    {
        assert(_data.size() > 0 && _data[0].size() > 0);
        assert(m._data.size() > 0 && m._data[0].size() > 0);
        assert(_data.size() == m._data.size() && _data[0].size() == m._data[0].size());
        auto res = matrix(_data.size(), _data[0].size());
        for(unsigned int r = 0; r <_data.size(); r++){
            for(unsigned int c = 0; c < _data[r].size(); c++){
                res._data[r][c] = _data[r][c] * m._data[r][c];
            }   
        }
        return res; 
    }

    matrix matrix::transpose() const
    {
        assert(_data.size() > 0 && _data[0].size() > 0);
        auto res = matrix(_data[0].size(), _data.size());
        for(unsigned int r = 0; r <_data.size(); r++){
            for(unsigned int c = 0; c < _data[r].size(); c++){
                res._data[c][r] = _data[r][c];
            }   
        }
        return res;
    }

    void matrix::apply(std::function<float(float)> func){
        for(auto& row : _data){
            for(auto& val : row){
                val = func(val);
            }
        }
    }

} // end of namespace iaga