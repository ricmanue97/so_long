# So Long

## Overview
`so_long` is a basic 2D game where the player's goal is to collect all collectibles on the map and then escape by choosing the shortest possible route. The game is developed using MiniLibX and requires a map description file with the `.ber` extension as input.

## Function Prototype
```c
char *so_long(int fd);
```

## Files to Submit
- `Makefile`
- `*.h`
- `*.c`
- `maps`
- `textures`

## Makefile Targets
- `NAME`: The name of the executable.
- `all`: Builds the executable.
- `clean`: Removes object files.
- `fclean`: Removes object files and the executable.
- `re`: Rebuilds the project.

## Arguments
- A map file in the `.ber` format.

## External Functions
- `open`, `close`, `read`, `write`
- `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions of the math library (`-lm` compiler option, `man man 3 math`)
- All functions of the MiniLibX
- `ft_printf` and any equivalent YOU coded

## Libft
- Libft is authorized.

## Description
`so_long` is a game where a dolphin (or any character of your choice) collects fish (or any collectibles) and escapes Earth (or any place) using the shortest route possible. The game follows these rules:

### Game Rules
- The player’s goal is to collect all collectibles on the map and then escape.
- Use the W, A, S, and D keys to move the main character in four directions: up, down, left, and right.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- Use a 2D view (top-down or profile).
- The game does not have to be in real time.
- You can use ZQSD or the arrow keys instead of WASD to move the character.

### Graphic Management
- The program displays the game in a window.
- Window management should remain smooth (switching, minimizing, etc.).
- Pressing ESC should close the window and quit the program cleanly.
- Clicking on the window's close button should also close the window and quit the program cleanly.
- Use MiniLibX images for graphics.

### Map Rules
- The map consists of walls, collectibles, and free space.
- The map can only include the following characters:
  - `0` for an empty space
  - `1` for a wall
  - `C` for a collectible
  - `E` for a map exit
  - `P` for the player’s starting position
- A valid map example:
  ```
  1111111111111
  10010000000C1
  1000011111001
  1P0011E000001
  1111111111111
  ```
- A valid map must contain 1 exit, 1 starting position, and at least 1 collectible.
- The map must be rectangular and enclosed by walls.
- Verify if there is a valid path in the map.
- Parse any map that respects the above rules.
- Handle misconfigurations by displaying "Error\n" and an explicit error message.

### Example of a Minimal .ber Map
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## Conclusion
Implementing `so_long` will help you create a 2D game that involves managing graphics, handling user inputs, and ensuring smooth gameplay with MiniLibX. Ensure to follow the game and map rules for a successful project.
