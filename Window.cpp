// Window.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "User.h"
#include "Sudoku.h"

void gowno()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");
	std::vector<std::string> text = { "Quick Game", "Load User", "Exit" };
	user first;
	Menu menu(600, 600, text);
	menu.RunMenu(window);



	/*std::vector<std::string> texts_1 = {"Quick Game", "Load User", "Exit"};
	std::vector<std::string> texts_2 = { "Sudoku", "Tic Tac Toe", "Crosswords" };

	Menu start_menu(window.getSize().x, window.getSize().y, texts_1);
	Menu chose_game(window.getSize().x, window.getSize().y, texts_2);
	LoginWindow login(window.getSize().x, window.getSize().y);

	int result = start_menu.RunMenu(window);
	if (result == 0)
	{
		chose_game.RunMenu(window);
	}
	if (result == 1)
	{
		login.RunMenu(window);
		chose_game.RunMenu(window);
	}*/
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
