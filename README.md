# so_long

A 2D graphical game project developed in C using MiniLibX, where the player navigates a map, collects all collectibles, and escapes through an exit. The project demonstrates fundamental concepts in C programming, file parsing, event-driven graphics, and basic game logic.

## Overview

`so_long` challenges you to develop a simple yet complete 2D game. The player's goal is to collect all items on a map and reach the exit by the shortest route. The game takes a `.ber` map file as input, uses graphical rendering via MiniLibX, and requires careful management of user input, graphics, and map validation.

## Main Technical Points

- **Graphics with MiniLibX:**  
  Game rendering is handled using MiniLibX, including window creation, sprite drawing, and event handling (keyboard and window close events).

- **Map Parsing and Validation:**  
  The game loads a map from a `.ber` file, parses it into a 2D array, and checks for validity (e.g., rectangular shape, wall boundaries, required elements: player, exit, collectibles).

- **Game Loop & User Input:**  
  The player moves with W, A, S, D (or arrow keys). Each move is validated against the map structure (no walking through walls) and is counted and displayed in the terminal.

- **Resource Management:**  
  All dynamic allocations (maps, sprites) are properly handled, and the game ensures graceful exit on ESC/key close or window button.

- **Custom Utility Library:**  
  The project uses a custom `libft` for string and memory operations, along with custom implementations of `ft_printf` and `get_next_line` for I/O.

- **Clean Makefile Build:**  
  The provided Makefile automates compilation and cleaning, including dependencies on `libft` and MiniLibX.

## Installation

```sh
git clone https://github.com/ricmanue97/so_long.git
cd so_long/so_long
make
```

## Usage

```sh
./so_long path/to/map.ber
```

- The map must be a valid `.ber` file placed in the correct directory.
- Use W, A, S, D (or arrow keys) to move.
- The number of moves is printed to the terminal after every move.

## Game Rules

- Collect all collectibles before exiting.
- The player cannot move through walls.
- The exit only opens after collecting all items.
- The game is displayed in a window; ESC or window close exits cleanly.

## Example Map

```
11111
1P0C1
100E1
11111
```
Legend:  
- 1: Wall  
- 0: Empty  
- P: Player  
- C: Collectible  
- E: Exit  

## Project Structure

- `so_long.c`, `playing.c`, `map_check.c`, etc.: Core game logic and map handling
- `libft/`: Custom utility library
- `mlx_linux/`: MiniLibX graphics library (external dependency)
- `maps/`: Example and test maps
