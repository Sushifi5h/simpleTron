/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 1                                               *
* Programming Assignment: Programming Assignment 7					                       *
* Date: Apirl 07, 2016                                                                     *
*******************************************************************************************/
//gaurd code
#pragma once

//include local libraries
#include "simple.h"

void Simpletron::runnerMainFunction(void)
{
	int operationCode = 0, operand = 0;
	grabInstructionsForFile();
	
	while (1)
	{
		instructionCode = fetch();
		decode(instructionCode, operationCode, operand);
		mainScreen(operand, operationCode);
		execute(instructionCode, operationCode, operand);
		system("pause");
		system("cls");
	}

	
}

void Simpletron::mainScreen(int operand, int operationCode)
{
	cout << "REGISTERS:" << endl;
	cout << "accumulator\t\t" << showpos << accumulator << endl;
	cout << "instructionCounter\t" << showpos << instructionCode << endl;
	cout << "instructionRegister\t" << showpos << instructions[registry] << endl;
	cout << "operationCode\t\t" << showpos << operationCode << endl;
	cout << "operand\t\t\t" << showpos << operand << endl << endl;

	cout << "Memory:" << endl;
	for (int counter = 0; counter < 100; counter++)
	{
		cout << showpos << memory[counter];
		printf("%03d ", memory[counter]);

		if (((counter % 9) == 0) && (counter > 0))
			cout << endl;
	}

	cout << endl << "Instructions: " << endl << "[";
	for (int counter = 0; counter < 10; counter++)
	{
		cout << " " << showpos << instructions[counter];
	
	}
	cout << " ]" << endl << endl;
	cout << "Instruction: " << instructions[registry] << endl;
}

void Simpletron::grabInstructionsForFile(void)
{
	string holderBefore = "";
	fstream getIt;
	getIt.open("Example1.sml");
	
	int  counter = 0;
	while (getline(getIt, holderBefore))
	{
		instructions[counter] = atoi(holderBefore.c_str());
		counter++;
	}
	
	getIt.close();
}

const int Simpletron::fetch(void)
{
	return instructions[registry++];
}

void Simpletron::decode(int instructionCode, int &operationCode, int &operand)
{
	int decodeThisI = instructionCode;
	string decodeThisS = std::to_string(decodeThisI);

	int counter = 0;
	string empty = "";
	for (std::string::iterator it = decodeThisS.begin(); it != decodeThisS.end(); ++it) 
	{
		empty = empty + *it;

		if (counter == 1)
		{
			operationCode = atoi(empty.c_str());
			empty = "";
		}
		
		if (counter == decodeThisS.length() - 1)
			operand = atoi(empty.c_str());

		counter++;
	}
 }

void Simpletron::execute(int instructionCode, int &operationCode, int &operand)
{
	switch (operationCode)
	{
	case 10:
		READ(operand);
		break;
	case 11:
		WRITE(operand);
		break;
	case 20:
		LOAD(operand);
		break;
	case 21:
		STORE(operand);
		break;
	case 30:
		ADD(operand);
		break;
	case 31:
		SUBTRACT(operand);
		break;
	case 32:
		DIVIDE(operand);
		break;
	case 33:
		MULTIPLY(operand);
		break;
	case 40:
		BRANCH(operand);
		break;
	case 41:
		BRANCHNEG(operand);
		break;
	case 42:
		BRANCHZERO(operand);
		break;
	case 43:
		HALT();
		break;
	default:
		break;
	}
}

void Simpletron::READ(int &grid)
{
	cout << ">>";
	cin >> memory[grid];
}

void Simpletron::WRITE(int &grid)
{
	cout << "Output: " << memory[grid] << endl;
}

void Simpletron::LOAD(int &grid)
{
	accumulator = memory[grid];
}

void Simpletron::STORE(int &grid)
{
	memory[grid] = accumulator;
}

void Simpletron::ADD(int &grid)
{
	accumulator = accumulator + memory[grid];
}

void Simpletron::SUBTRACT(int &grid)
{
	accumulator = accumulator - memory[grid];
}

void Simpletron::DIVIDE(int &grid)
{
	accumulator = accumulator/memory[grid];
}

void Simpletron::MULTIPLY(int &grid)
{
	accumulator = accumulator * memory[grid];
}

void Simpletron::HALT(void)
{
	cout << "Done running Progam Exiting." << endl;
	system("pause");
	exit(0);
}

void Simpletron::BRANCH(int &grid)
{
	instructionCode = grid;
}

void Simpletron::BRANCHNEG(int &grid)
{
	if (accumulator < 0)
		instructionCode = grid;
}

void Simpletron::BRANCHZERO(int &grid)
{
	if (accumulator == 0)
		instructionCode = grid;
}

void Simpletron::MOD(int &grid)
{

}