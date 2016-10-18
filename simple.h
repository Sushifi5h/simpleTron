/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 1                                               *
* Programming Assignment: Programming Assignment 7					                       *
* Date: Apirl 07, 2016                                                                     *
*******************************************************************************************/

//includ std lib
#include <iostream>
#include <fstream>
#include <string>

//namespaces
using std::cout;
using std::endl;
using std::showpos;
using std::fstream;
using std::string;
using std::cin;


class Simpletron {
public:
	//constructor and destructor
	Simpletron() { this->accumulator = 0; this->registry = 0; intArray(); this->instructionCode = 0; }
	void intArray(void)
	{
		for (int counter = 0; counter < 999; counter++)
			memory[counter] = 0000;
		for (int counter = 0; counter < 10; counter++)
			instructions[counter] = 0000;
	}
	~Simpletron() { cout << "IN Simpletron destructor" << endl; }
	//getters just in case
	int getaccumulator(void) { return accumulator; }
	int getregistry(void) { return registry; }
	//settes jsut in case
	void setaccumulator(int input) {this->accumulator = accumulator;}
	void setregistry(int input) { this->registry = input; }

	//main functions
	void runnerMainFunction(void);
	void mainScreen(int operand, int operationCode);
	void grabInstructionsForFile(void);

	const int fetch(void);  // read the next SML instruction from memory
	void decode(int instructionCode, int &operationCode, int &operand); // determine the operationCode and operand of the instruction
	void execute(int instructionCode, int &operationCode, int &operand); // perform the correct operation
	void READ(int &grid); // 10 - Read a word from the keyboard into a specific location in memory
	void WRITE(int &grid); // 11 - Write a word from a specific location in memory to the screen
	void LOAD(int &grid); // 20 - Load a word from a specific location in memory into the accumulator
	void STORE(int &grid); // 21 - Store a word from the accumulator into a specific location in memory
	void ADD(int &grid); // 30 - Add a word from a specific location in memory to the word in the acculmulator (leave result in accumulator)
	void SUBTRACT(int &grid); // 31 - Subtract a word from a specific location in memory from the word in the accumulator (leave result in accumulator)
	void DIVIDE(int &grid); // 32 - Divide a word from a specific location in memory into the word in the accumulator
	void MULTIPLY(int &grid); // 33 - Multiply a word from a specific location in memory by the word in the accumulator
	void BRANCH(int &grid); // 40 - Branch to a specific location in memory
	void BRANCHNEG(int &grid); // 41 - Branch to a specific location in memory if the accumulator is negative
	void BRANCHZERO(int &grid); // 42 - Branch to a specific location in memory if the accumulator is zero
	void HALT(); // 43 - Halt - the program has completed its task
private:
	int accumulator; // Current data
	int memory[1000]; // Storage
	int instructions[10]; // Programming instructions
	int registry; // Current instruction
	int instructionCode; 
};