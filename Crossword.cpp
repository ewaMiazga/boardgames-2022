#include "Crossword.h"

Crossword::Crossword()
{
}

std::string Crossword::getCrosswordClue()
{
    return crosswordClue;
}

std::string Crossword::getClue()
{
    return crosswordClueInfo;
}

std::pair<std::string, std::string> Crossword::findLetter(char letter, std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == letter)
            return std::make_pair(word, clues.at(word));
    }
    return std::make_pair("error", "error");
}

int Crossword::findLetterPos(char letter, std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == letter)
            return i;
    }
    return -1;
}

int Crossword::findMaxLetterPos()
{
    int maxPos = 0;
    for (auto clue : crosswordClues)
    {
        int pos = findLetterPos(clue.first, (clue.second).first);
        if (pos > maxPos)
            maxPos = pos;
    }
    return maxPos;
}

void  Crossword::chooseCrosswordClue(std::string crosswordClueValue)
{
    crosswordClue = crosswordClue;
    crosswordClueInfo = clues.at(crosswordClueValue); // try except because clue can not be in map
    clues.erase(crosswordClueValue);
}

void  Crossword::chooseCrosswordClues()
{
    std::pair<std::string, std::string> LetterNotOccur = std::make_pair("error", "error");
    std::vector<std::pair<char, std::pair<std::string, std::string>>>  choosenClues;
    for (int i = 0; i < crosswordClue.size(); i++)
    {
        char letter = crosswordClue.at(i);
        for (std::map<std::string, std::string>::iterator it = clues.begin(); it != clues.end(); it++)
        {
            if (findLetter(letter, it->first) != LetterNotOccur)
            {
                choosenClues.push_back(std::make_pair(letter, findLetter(letter, it->first)));
                break;
            }
        }
    }
    crosswordClues = choosenClues;
}

std::string Crossword::encryptClue(std::string clue)
{
    std::string s;
    for (int i = 0; i < clue.size(); i++)
    {
        s += "_";
    }
    return s;
}

std::ostream& operator<<(std::ostream& COUT, Crossword& crossword)
{
    for (std::map<std::string, std::string>::iterator it = crossword.clues.begin(); it != crossword.clues.end(); it++)
    {
        COUT << it->first << std::endl;
        COUT << it->second << std::endl;
    }
    return COUT;
}

std::istream& operator>>(std::istream& CIN, Crossword& crossword)
{
    std::string clue;
    std::string clueInfo;
    CIN >> clue;
    CIN >> clueInfo;
    crossword.clues.insert({ clue, clueInfo });
    return CIN;
}

void Crossword::generateCrossword()
{
    int maxPos = findMaxLetterPos();
    int i = 0;
    int num = 1;
    while (i < maxPos)
    {
        std::cout << " ";
        i++;
    }
    std::cout << " #" << std::endl;
    for (auto clue : crosswordClues)
    {
        if (findLetterPos(clue.first, (clue.second).first) < maxPos)
        {
            int gap = maxPos - findLetterPos(clue.first, (clue.second).first);
            while (gap > 0)
            {
                std::cout << " ";
                gap--;
            }
        }
        std::cout << num << encryptClue((clue.second).first) << std::endl;

    }
    while (i > 0)
    {
        std::cout << " ";
        i--;
    }
    std::cout << " #" << std::endl;
    for (auto clue : crosswordClues)
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << (clue.second).second << std::endl;
    }
}

void Crossword::display()
{
    int maxPos = findMaxLetterPos();
    int i = 0;
    int num = 1;
    while (i < maxPos)
    {
        std::cout << " ";
        i++;
    }
    std::cout << " #" << std::endl;
    for (auto clue : crosswordClues)
    {
        if (findLetterPos(clue.first, (clue.second).first) < maxPos)
        {
            int gap = maxPos - findLetterPos(clue.first, (clue.second).first);
            while (gap > 0)
            {
                std::cout << " ";
                gap--;
            }
        }
        std::cout << num << encryptClue((clue.second).first) << std::endl;
    }
    while (i > 0)
    {
        std::cout << " ";
        i--;
    }
    std::cout << " #" << std::endl;
}

void readFromFile(std::string fileName)
{
    fileName += ".txt";
    std::ifstream fileHandleOpen(fileName);
    if (!fileHandleOpen)
    {
        std::cerr << "File cannot be open - this path not exist " << std::endl;
    }
    else
    {
        while (!fileHandleOpen.eof())
        {
            Crossword crosswordTemp;
            fileHandleOpen >> crosswordTemp;
        }
        fileHandleOpen.close();
    }
}
