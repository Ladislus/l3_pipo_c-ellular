
# C-ellular-project
School project to create a cellular automaton. Written in C.

## Informations
**Group** : Ladislas WALCAK, Simon DRIEUX.   
**Git repository** : [github.com](https://github.com/SimonDr18/C-ellular-project)

## Requirements
For this program to work, you need to install :
 - GCC compiler
 - Valgrind
 - Makefile
 - Doxygen (Optionnal)

## Run the project
Here are the steps to run the project (in the terminal)
 1. To run the project, first compile it :

	    make
	*if you want to compile the project from zero run*
	
		make clean && make
	

 2. Then, run the executable
 
		make run
		
You can also generate the documentation. To do so, you need to either create a Doxygen configuration file with the command

	doxygen -g <filename>
	
Or download the customized file "Doxyfile" on the github of the project.
Then, simply enter the command

	make doc

On github, you can also find an example of configuration file named "config.txt". The format of the file (Order, line breaks etc...) must be strictly respected. More over, some constraints must be respected

 - 2 <= State <= 10
 - 5 <= Size
 - 2 <= Iteration
 - Start must have the same length than Size (if Size=10, then Start must be 10 characters long) and all characters must be 0 <= X < State
 -  Rule must be (((State - 1) * 3) + 1) characters long (ex : States = 4, Rule is 10 characters long) and all characters must be 0 <= X < State

**A .pdf file with more explainations can be found on the git repository**