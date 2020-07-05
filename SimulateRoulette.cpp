/*
 * French roulette simulation
 *
 * Soncini Nicolás - iRobot interview (2020)
 */

#include <iostream> // cout, endl
#include <deque>    // deque
#include <map>      // map
#include <functional>

#include "Roulette.hpp"
#include "RoulettePlayer.hpp"


/* TYPES & MACROS*/
#ifndef DEBUG
#define DEBUG 0
#endif

typedef bool (FrenchRoulette::*compare_fun)();


/* HELPER FUNCTIONS & DATA STRUCTURES */

class SimulateRoulette {
public:
    SimulateRoulette(FrenchRoulette *roulette) {
        this->roulette = roulette;
    };

    // add_player method
    //  stores a player with it's corresponding check function
    void add_player(FrenchRoulettePlayer *rp, compare_fun cp){
        players.insert(std::pair<FrenchRoulettePlayer*,compare_fun>(rp, cp));
    };

    // step method
    //  iterates one step of the simulation
    void step(){
        // play roulette
        roulette->throw_ball();
        // check on all players
        for (auto pf : players) {
            pf.first->play(((*roulette).*(pf.second))());
        }
    };

    // print_info method
    //  prints relevant information about the simulation
    void print_info() {
        // print last number from roulette
        std::cout << "Roulette: " << roulette->last << std::endl;
        // print player balances
        std::cout << "Balances: ";
        for (auto pf : players) {
            std::cout << ">" << pf.first->balance  << " ";
        }
        std::cout << std::endl;
    };
private:
    FrenchRoulette *roulette;
    std::map<FrenchRoulettePlayer*, compare_fun> players;
};


/* MAIN FUNCTION*/

int main(void)
{
    FrenchRoulette roulette;

    std::deque<unsigned int> init_m = {1,2,3,4};
    FrenchRoulettePlayer *pred, *pblack, *phigh, *plow, *peven, *podd;
    pred   = new FrenchRoulettePlayer(init_m, roulette);
    pblack = new FrenchRoulettePlayer(init_m, roulette);
    phigh  = new FrenchRoulettePlayer(init_m, roulette);
    plow   = new FrenchRoulettePlayer(init_m, roulette);
    peven  = new FrenchRoulettePlayer(init_m, roulette);
    podd   = new FrenchRoulettePlayer(init_m, roulette);

    SimulateRoulette simulation(&roulette);
    simulation.add_player(pred, &FrenchRoulette::is_red);
    simulation.add_player(pblack, &FrenchRoulette::is_black);
    simulation.add_player(phigh, &FrenchRoulette::is_high);
    simulation.add_player(plow, &FrenchRoulette::is_low);
    simulation.add_player(peven, &FrenchRoulette::is_even);
    simulation.add_player(podd, &FrenchRoulette::is_odd);

    for (unsigned int sim_counter = 0; sim_counter < 10000; sim_counter++) {
        simulation.step();
        if(DEBUG){
            simulation.print_info();
        }
    }

    std::cout << "Final Balance: " << 
        pred->balance + pblack->balance + phigh->balance + plow->balance
        + peven->balance + podd->balance << std::endl;

    return 0;
}

