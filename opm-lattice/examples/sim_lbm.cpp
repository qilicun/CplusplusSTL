#include <opm/lattice/FluidProperties.hpp>
#include <opm/lattice/GridManager.hpp>
#include <opm/lattice/LatticeBoltzmannModule.hpp>
#include <opm/lattice/LatticeBoltzmannMethod.hpp>
#include <opm/lattice/SimulatorState.hpp>
#include <opm/lattice/writeVtkData.hpp>
#include <opm/lattice/DataMap.hpp>
#include <boost/filesystem.hpp>
#include <opm/lattice/StopWatch.hpp>
#include <iostream>
#include <string>

int main()
{
    std::cout << "\n================    Test program for two-phase lattice boltzmann simulator     ===============\n\n";
    std::shared_ptr<GridManager> grid;
    std::shared_ptr<FluidProperties> red;
    std::shared_ptr<FluidProperties> blue;
    std::shared_ptr<LatticeBoltzmannModule> module;
    SimulatorState state;

    grid.reset(new GridManager(80, 20, 20));
    module.reset(new LatticeBoltzmannModule());
    red.reset(new FluidProperties(grid, module, 1.0, 1.0, 0.1667, 0.1));
    blue.reset(new FluidProperties(grid, module, 1.0, 1.0, 0.1667, 0.1));

    std::cout << "\n\n================    Starting main simulation loop     ===============\n"
              << std::flush;
    SimulatorTimer simtimer;

    TwoPhaseLatticeBoltzmannSimulator:: simulator(grid, red, blue, module);
    simtimer.init(1e6, 1);
    simulator.run(simtimer, state);
    std::cout << "\n\n================    End of simulation     ===============\n\n";
    
    return 0;
}