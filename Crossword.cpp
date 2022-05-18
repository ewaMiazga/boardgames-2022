#include "Crossword.h"

Crossword::Crossword()
{
    //std::string fileName = "C:/Users/a.miazga/Desktop/CrosswordData";
    std::string fileName = "C:/Users/a.miazga/Desktop/CrosswordDataUTF";
    //std::string fileName = "C:/Users/a.miazga/Desktop/nowiutkitxt";
    readFromFile(fileName, *this); // call its own 
    chooseClueRandomly();
    chooseCrosswordClues();
    for (int i = 0; i < crosswordClues.size(); i++)
    {   
        std::string clueInfo = crosswordClues.at(i).second.second;
        std::string clue = "_";
        crosswordCluesUser.push_back(std::make_pair(i + 1, std::make_pair(clue, clueInfo)));
    }
}

std::string Crossword::getClue()
{
    return crosswordClue.first;
}

std::string Crossword::getClueInfo()
{
    return crosswordClue.second;
}

void Crossword::chooseClueRandomly()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(clues), std::end(clues), g);
    int i = rand() % clues.size();
    crosswordClue = clues[i];
    clues.erase(clues.begin() + i);
}

std::vector<std::pair<std::string, std::string>> Crossword::getClues()
{
    return clues;
}

std::vector<std::pair<int, std::pair<std::string, std::string>>> Crossword::getCrosswordCluesUser()
{
    return crosswordCluesUser;
}

void Crossword::addClue(std::string Clue, std::string ClueInfo)
{
    clues.push_back(std::make_pair(Clue, ClueInfo));
}

bool Crossword::findLetter(char letter, std::pair<std::string, std::string> word)
{
    for (int i = 0; i < word.first.size(); i++)
    {
        if (word.first[i] == letter)
            return true;
    }
    return false;
}

int Crossword::findLetterPos(char letter, std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == letter)
            return i;
    }
}

int Crossword::findMaxLetterPos()
{
    int maxPos = 0;
    int i = 0;
    for (auto clue : crosswordClues)
    {
        char letter = crosswordClue.first[i];
        int pos = findLetterPos(letter, (clue.second).first);
        if (pos > maxPos)
            maxPos = pos;
        i++;
    }
    return maxPos;
}

void  Crossword::chooseCrosswordClues()
{
    for (int i = 0; i < crosswordClue.first.size(); i++)
    {
        char letter = crosswordClue.first[i];
        for (std::vector<std::pair<std::string, std::string>>::iterator it = clues.begin(); it != clues.end(); it++)
        {
            if (findLetter(letter, *it))
            {
                crosswordClues.push_back(std::make_pair(i+1, *it));
                clues.erase(it);
                break;
            }
        }
    }
}

void Crossword::insert(int num, std::string clueValue)
{
    //if (crosswordCluesUser[num - 1].second.first == "_")
    crosswordCluesUser[num - 1].second.first = clueValue;
}

std::string Crossword::encryptClue(std::string clue)
{
    std::string s;
    for (int i = 0; i < clue.size(); i++)
        s += "_ ";
    return s;
}

std::ostream& operator<<(std::ostream& COUT, Crossword& crossword)
{
    for (std::vector<std::pair<std::string, std::string>>::iterator it = crossword.clues.begin(); it != crossword.clues.end(); it++)
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
    std::getline(CIN, clue);
    std::getline(CIN, clueInfo);
    crossword.clues.push_back(std::make_pair(clue, clueInfo));
    return CIN;
}

void Crossword::display()
{
    int maxPos = findMaxLetterPos();
    int i = 0;
    int j = 0;
    while (i < maxPos)
    {
        std::cout << "  ";
        i++;
    }
    std::cout << "#" << std::endl;
    for (auto clue : crosswordClues)
    {
        if (findLetterPos(crosswordClue.first[j], (clue.second).first) < maxPos)
        {
            int gap = maxPos - findLetterPos(crosswordClue.first[j], (clue.second).first);
            while (gap > 0)
            {
                std::cout << "  ";
                gap--;
            }
        }
        //std::cout << clue.first << ".";
        auto userClue = crosswordCluesUser[clue.first - 1];
        //if (clue.second == userClue.second)
        //{
        //    for (int k = 0; k < userClue.second.first.size(); k++)
        //        std::cout << userClue.second.first[k] << " ";
        //}
        ////else if(userClue.second.first == "_" && clue.first == userClue.first)
        //else
        //    std::cout << encryptClue((clue.second).first);
        if (userClue.second.first == "_")
        {
            std::cout << encryptClue((clue.second).first);
        }
        else
        {
            for (int k = 0; k < userClue.second.first.size(); k++)
                std::cout << userClue.second.first[k] << " ";
            if (userClue.second.first.size() < clue.second.first.size())
                for (int k = 0; k < clue.second.first.size() - userClue.second.first.size(); k++)
                    std::cout << "_ ";
        }
        std::cout << std::endl;
        j++;
    }
    while (i > 0)
    {
        std::cout << "  ";
        i--;
    }
    std::cout << "#" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    for (auto clue : crosswordClues)
    {
        std::cout << std::endl;
        std::cout << clue.first << ". " << (clue.second).second << std::endl;
    }
}

void Crossword::display2()
{
    //int horzPos = findLetterPos(letter, crosswordClues[1].second.first);
    //printVert(horzPos, crosswordClues[0].second.first);
    for (int i = 1; i < crosswordClues.size(); i++)
    {
        for (int j = 0; j < crosswordClues[i].second.first.size(); j++)
        {
            char letter = crosswordClues[i].second.first[j];
            if (findLetter(letter, crosswordClues[i - 1].second))
            {
                int horzPos = findLetterPos(letter, crosswordClues[i - 1].second.first);
                if (i % 2 == 0)
                    printVert(horzPos, crosswordClues[i].second.first);
                else
                    printHoriz(horzPos, crosswordClues[i - 1].second.first);
                //printVert(horzPos, crosswordClues[i].second.first);
                //printHoriz(horzPos, crosswordClues[i - 1].second.first);
            }
        }

    }
}

void Crossword::printVert(int allignment, std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        int j = 0;
        while (j < allignment)
        {
            std::cout << " ";
            j++;
        }
        std::cout << word[i] << std::endl;
    }
}

void Crossword::printHoriz(int allignment, std::string word)
{
    int j = 0;
    while (j < allignment)
    {
        std::cout << " ";
        j++;
    }
    for (int i = 0; i < word.size(); i++)
        std::cout << word[i] << std::endl;
}

void Crossword::solveCrossword()
{
    for (int i = 0; i < crosswordCluesUser.size(); i++)
    {
        if (crosswordCluesUser[i].second.first == "_") // why cant I write empty instead of "_"
            insert(i + 1, crosswordClues[i].second.first);
    }
}

bool Crossword::isSolved()
{
    for (int i = 0; i < crosswordCluesUser.size(); i++)
    {
        if (crosswordCluesUser[i].second.first == "_")
            return false;
    }
    return true;
}

bool Crossword::checkCorrectness()
{
    for (int i = 0; i < crosswordCluesUser.size(); i++)
    {
        if (crosswordCluesUser[i].second.first != crosswordClues[i].second.first)
            return false;
    }
    return true;
}

void Crossword::play()
{
    while (!isSolved() && !checkCorrectness())
    {
        display();
        int num;
        std::cout << std::endl;
        std::cout << "choose number: " << std::endl;
        std::string clue;
        std::cin >> num;
        std::cout << "write clue: " << std::endl;
        std::cin >> clue;
        insert(num, clue);
    }
    display();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Crossword is solved" << std::endl;
    std::cout << std::endl;
    std::cout << "CLUE: " << crosswordClue.first << std::endl;
    std::cout << "CLUE INFO: " << crosswordClue.second << std::endl;
    std::cout << std::endl;
}

void readFromFile(std::string fileName, Crossword& crosswordTemp)
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
            fileHandleOpen >> crosswordTemp;
        }
        fileHandleOpen.close();
    }
}
