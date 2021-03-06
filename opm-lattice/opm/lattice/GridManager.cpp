#include <vector>
#include <iostream>
#include <set>
#include <opm/lattice/GridManager.hpp>

GridManager::GridManager(const int NX, const int NY, const int NZ)
     :NX_(NX)
     ,NY_(NY)
     ,NZ_(NZ)
     ,boundary_(NX*NY*NZ, 0)
{
    std::vector<int> idx;
    //compute inner index.
    for (int z  = 0; z < NZ_; ++z) {
        for (int y = 0; y < NY_; ++y) {
            idx.push_back(index(0, y, z));
            idx.push_back(index(NX_-1, y, z));
        }
    }

    for (int z = 0; z < NZ_; ++z) {
        for (int x = 0; x < NX_; ++x) {
            idx.push_back(index(x, 0, z));
            idx.push_back(index(x, NY_-1, z));
        }
    }
    for (int y = 0; y < NY_; ++y) {
        for (int x = 0; x < NX_; ++x) {
            idx.push_back(index(x, y, 0));
            idx.push_back(index(x, y, NZ_-1));
        }
    }
    typedef std::vector<int>::size_type vec_sz;
    for (vec_sz i = 0; i < idx.size(); ++i) {
        boundary_[idx[i]] = 1;
    }
}

const int
GridManager::dimension() const
{
    return NX_ * NY_ * NZ_;
}

const int
GridManager::spaceDim() const
{
    if (NZ_ == 1)
        return 2;
    else
        return 3;
}

const int 
GridManager::index(const int x, const int y, const int z) const
{
    return NX_ * NY_ * z +  NX_ * y + x;
}
