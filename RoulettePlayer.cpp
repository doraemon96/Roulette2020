
#include "RoulettePlayer.hpp"

/*
 * Roulette Player
 */

// RoulettePlayer constructor
RoulettePlayer::RoulettePlayer(
    std::deque<unsigned int>& initial_memory, Roulette& roulette)
{
    // copy initial numbers to internal memory
    this->memory = initial_memory;
    this->initial_memory = initial_memory;

    // initialize private variables
    this->max_bet = roulette.max_bet;
    this->min_bet = roulette.min_bet;
}

// won method
//  adds winnings to notebook and adds winnings to balance
void RoulettePlayer::won(unsigned int winnings)
{
    // add winnings to back of memory
    memory.push_back(winnings);
    // add winnings to balance
    balance += (int)winnings;
}

// lost method
//  removes elements from notebook and subtracts losses from balance
void RoulettePlayer::lost(unsigned int losses)
{
    if (memory.size() <= 2) {
        // restart memory to initial numbers
        reset_memory();
    }
    else { // memory.size() > 2
        // remove numbers from the extremes of memory
        memory.pop_back();
        memory.pop_front();
    }
    // add losses to balance
    balance -= (int)losses;
}

// reset_memory method
void RoulettePlayer::reset_memory()
{
    memory = initial_memory;
}

// next_bet method
//  returns the next bet calculated (can reset the memory)
unsigned int RoulettePlayer::next_bet()
{
    unsigned int play;
    if (memory.size() == 1) {
        // return single number as bet
        play = memory.front();
    }
    else { // memory.size() > 1
        // return sum of extremes as bet
        play = memory.front() + memory.back();
    }

    if (play < min_bet || play >= max_bet) {
        reset_memory();
        play = next_bet();
    }
    
    return play;
}

// play method
//  calculates a bet and checks if result was successful
//  calls won or lost to reflect the outcome on the balance
void RoulettePlayer::play(bool result)
{
    unsigned int bet = next_bet();
    if (result) {
        won(bet);
    } else {
        lost(bet);
    }
}


/*
 * French Roulette Player
 */

// FrenchRoulettePlayer constructor
FrenchRoulettePlayer::FrenchRoulettePlayer(
    std::deque<unsigned int>& initial_memory, FrenchRoulette& roulette)
    : RoulettePlayer(initial_memory, roulette)
{}
