#include <vector>
#include <iostream>
#include <set>
#include <opm/lattice/GridManager.hpp>

GridManager::GridManager(int NX, int NY, int NZ)
     :NX_(NX)
     ,NY_(NY)
     ,NZ_(NZ)
     ,boundary_(NX*NY*NZ, 0)
{
    std::cout << "GridManager was successfully created!\n";
}

GridManager::~GridManager()
{}

int
GridManager::dimension() const
{
    return NX_ * NY_ * NZ_;
}

int
GridManager::spaceDim() const
{
    if (NZ_ == 1)
        return 2;
    else
        return 3;
}

int 
GridManager::index(const int x, const int y, const int z) const
{
    return NZ_ * NY_ * z +  NY_ * y + x;
}
void
GridManager::setBoundary()
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
    for (int i = 0; i < static_cast<int>(idx.size()); ++i) {
        boundary_[idx[i]] = 1;
    }
}
#if 0
int main () {
    GridManager grid(3,3,3);
    std::cout << "total dimension: " << grid.dimension() << " with NX:" << grid.NX() << " NY: " << grid.NY()<< " NZ: "<<grid.NZ()<< std::endl;
    std::cout << "spaceDime(): " << grid.spaceDim() << std::endl;
    std::cout << "boundary:\n";
    std::vector<int> bd;
    bd = grid.boundary();
    for (auto i : bd) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    
}
#endif