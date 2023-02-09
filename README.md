# CPTR 142: Project III

Add information about your project.
Such as detailed description, known bugs and user operation instructions.
This is the file a user will first look at when attempting to run your program.

We will simulate a chess board with ASCII art. Have user input to describe movements using standard chess notation. We will need to describe the standard notation in a markdown file. We will need functions for printing the board. We will have some way of storing the information of a chess board. We would also like to have error checking to see if it is a valid move.

## Terminal Commands

Build and run the program.

```sh
make && ./a.out
```

Clean out build files.

```sh
make clean
```

Build and run testing program.

```sh
make DRIVER=src/test_driver.cpp && ./a.out
```

Clean out test build files.

```sh
make DRIVER=src/test_driver.cpp clean
```
