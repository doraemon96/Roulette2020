#pragma once

#include <deque>        // deque
#include "Roulette.hpp" // Roulette, FrenchRoulette

/*
 * Roulette Player
 */

class RoulettePlayer {
public:
    RoulettePlayer(std::deque<unsigned int>& initial_memory
        , Roulette& roulette);
    void play(bool result);
    int balance;
private:
    unsigned int next_bet();
    void won(unsigned int);
    void lost(unsigned int);
    std::deque<unsigned int> memory;
    std::deque<unsigned int> initial_memory;

    void reset_memory();

    unsigned int max_bet;
    unsigned int min_bet;
};


/*
 * French Roulette Player
 */

class FrenchRoulettePlayer : public RoulettePlayer {
public:
    FrenchRoulettePlayer(std::deque<unsigned int>& initial_memory
        , FrenchRoulette& roulette);
};