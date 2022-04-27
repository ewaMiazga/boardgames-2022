#pragma once
#include <string>
#include <map>
#include <ostream>
#include <iostream>
#include <fstream>
#include <vector>


class Crossword
{
private:
	std::string crosswordClue;
	std::string crosswordClueInfo;
	std::vector<std::pair<char, std::pair<std::string, std::string>>> crosswordClues;
	std::map<std::string, std::string> clues;
public:
	Crossword();

	std::string getCrosswordClue();

	std::string getClue();

	std::pair<std::string, std::string> findLetter(char letter, std::string word);

	int findLetterPos(char letter, std::string word);

	int findMaxLetterPos();

	void chooseCrosswordClue(std::string crosswordClueValue);

	void chooseCrosswordClues();

	std::string encryptClue(std::string clue);

	friend std::ostream& operator<<(std::ostream& COUT, Crossword& crossword);

	friend std::istream& operator>>(std::istream& CIN, Crossword& crossword);

	void generateCrossword();

	void display();
};

void readFromFile(std::string fileName);
