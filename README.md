# Games
Repo containing games developed with SFML and C/C++ for Linux  

## Installation and Running the Games
In order to build each game, you will need to have SFML installed.  
Follow [this tutorial](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) for installing SFML for Linux.  
Then use each games makefile and `make release` to create the executable.  
Run the game by using `./<game-name>`  
Note: if you downloaded SFML to a non-standard path you may need to tell the linker where to find the libraries  
If this is the case, try `export LD_LIBRARY_PATH=<sfml-install-path>/lib && ./<game-name>`

## Running the tests
Some games were developed using TDD principles. The test harness used here is CppUTest.  
This repo assumes CppUTest as a git submodule. In order to run the tests, you will need to configure CppUTest first.  

1. Retrieve the submodule after cloning the repo `git submodule update --init --recursive`
2. Change directory into the cpputest folder `cd cpputest`
3. Generate cpputest's build files `autoreconf . -i`
4. Change directory into the generated solution `cd ./configure`
5. Run the cpputest build's tests `make tdd`

This should run a series of tests on the cpputest submodule.  
Once this is complete, you should be able to build each game's tests.  
Run the tests for each game using `make test`  
If you encounter errors, please look into the [CppUTest documentation](https://cpputest.github.io/index.html)