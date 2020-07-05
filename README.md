# Simulation of a French Roulette game

## Introduction
This project aims to simulate different ways to play French Roulette. A French Roulette consists of 37 numbers ([0,36]) where specific numbers have different meanings (red, black, high, low, even odd) to which a player can bet.

The simulation consists of one player betting for each of these bet types. The bet ammount is determined in runtime by a sum inside a players notebook. The notebook starts as "1,2,3,4" and the bet placed is the sum of the extremes (or the single number if only one remains). If the player wins he adds the winnings to the rightmost extreme, else he forgets about both the extremes and plays again.

The notebook is restarted to the original state if it's empty, or if the bet is higher (lower) than the maximum (minimum) roulette bets. 


## Building
Build with the following commands:

```
g++ -c RoulettePlayer.cpp Roulette.cpp
g++ -o simulation SimulateRoulette.cpp RoulettePlayer.o Roulette.o
```

Optionally to print debug info replace last command with

```
g++ -o simulation SimulateRoulette.cpp RoulettePlayer.o Roulette.o -DDEBUG=1
```

To run simply execute the built file `./simulation`

(Working and tested in `Ubuntu 18.04.4` and `g++ 7.5.0`)

## Explanation

`Roulette.cpp & Roulete.hpp` contain the class definitions for `Roulette`, a simple roulette class, and `FrenchRoulette`, a class with added number types and checks.

`RoulettePlayer.cpp & RoulettePlayer.hpp` contain the class definitions for `RoulettePlayer`, a player that bets on a given roulette, and `FrenchRoulettePlayer`, a simple wrapper for `RoulettePlayer` to work with added `FrenchRoulette` methods.

`SimulateRoulette.cpp` creates a simple class to keep track of players, and exposes the `step` function that iterates a step on the simulation, including player checks. It also exposes `print_info` to be called in any step and show the game status.


## Considerations
- The code inside `SimulateRoulette::step()` is difficult to understand. The problem is that member functions (that are not static) require an object associated, and this cannot be kept in the map. It is the price to pay for storing object functions as pointers.
- Using public getters and private setters in class-members like `balance` in `RoulettePlayer` would be the best option, but keep it simple as this is just a simulation.
- It's awkward how the roulette has the condition checks. It could be better to let the player deduce them from the sets, but it felt like something the player should not have control of. Either way for a simulation this is not entirely relevant, but it could be depending on how the code is expected to change (more bet types, different roulette rules?).
- `print_info` should take the output as argument to be able to switch between file and stdout output.
- As a sidenote, the notebook could be separated into it's own module so as to decouple the responsibility of the betting algorithm from the player, and adding to the roulette (or maybe on another class, the GameTable) the winnings for a particular bet, so as to not let the player decide how much he is winning. Again, this is only important if the betting algorithm could change in the future, or if the rules of a roulette game could change in the future.