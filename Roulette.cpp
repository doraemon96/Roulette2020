
#include "Roulette.hpp"

/*
 * Roulette
 */

// Roulette constructor
//  initializes numbers of the roulette from 0 to max (included)
Roulette::Roulette(unsigned int max)
{
    // fill roulette with available numbers
    for (unsigned int i = 0; i <= max; i++) {
        this->numbers.push_back(i);
    }
    // seed the rng
    std::srand(time(NULL));
}

// throw_ball method
//  generates a uniformly random chosen roulette number
void Roulette::throw_ball()
{
    // throw a (higly low-number biased) #numbers-sided dice
    this->last = rand() % this->numbers.size();
}


/*
 * French Roulette
 */

// FrenchRoulette constructor
//  initializes a roulette with 37 numbers, minimum bet of 5 and maximum of 4000
//  and its respective number sets
FrenchRoulette::FrenchRoulette() : Roulette(36)
{
    this->min_bet = 5;
    this->max_bet = 4000;

    this->reds   = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    this->blacks = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    this->highs  = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    this->lows   = {19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
    this->evens  = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};
    this->odds   = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35};
}

// is_red method
//  checks if the last number is red
bool FrenchRoulette::is_red()
{
    return (reds.find(last) != reds.end());
}

// is_black method
//  checks if the last number is black
bool FrenchRoulette::is_black()
{
    return (blacks.find(last) != blacks.end());
}

// is_high method
//  checks if the last number is high
bool FrenchRoulette::is_high()
{
    return (highs.find(last) != highs.end());
}

// is_low method
//  checks if the last number is low
bool FrenchRoulette::is_low()
{
    return (lows.find(last) != lows.end());
}

// is_even method
//  checks if the last number is even
bool FrenchRoulette::is_even()
{
    return (evens.find(last) != evens.end());
}

// is_odd method
//  checks if the last number is odd
bool FrenchRoulette::is_odd()
{
    return (odds.find(last) != odds.end());
}