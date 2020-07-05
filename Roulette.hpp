#pragma once

#include <stdlib.h> // rand
#include <vector>   // vector
#include <set>      // set
#include <ctime>    // time

/*
 * Roulette
 */

class Roulette {
public:
    Roulette(unsigned int max);
    void throw_ball();
    unsigned int min_bet;
    unsigned int max_bet;
    unsigned int last;
private:
    std::vector<unsigned int> numbers;
};


/*
 * French Roulette
 */

class FrenchRoulette : public Roulette {
public:
    FrenchRoulette();
    bool is_red();
    bool is_black();
    bool is_high();
    bool is_low();
    bool is_even();
    bool is_odd();
private:
    std::set<unsigned int> reds;
    std::set<unsigned int> blacks;
    std::set<unsigned int> highs;
    std::set<unsigned int> lows;
    std::set<unsigned int> evens;
    std::set<unsigned int> odds;
};