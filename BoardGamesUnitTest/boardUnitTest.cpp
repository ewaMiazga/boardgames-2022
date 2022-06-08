#include <array>
#include <exception>
#include "CppUnitTest.h"
#include "../BoardGamesLib/board.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Board>(const Board& t)
{
	std::wstring result;
	result += L"{";
	result += ToString(t);
	result += L"}";
	return result;
}


namespace BoardUnitTest
{
	TEST_CLASS(BoardUnitTest)
	{
	public:
		sf::Font t_font;
		TEST_METHOD_INITIALIZE(init)
		{
			sf::Font font;
			if (!font.loadFromFile("../resources/fonts/Qarolina.ttf")){}
			t_font = font;
		}
		TEST_METHOD(getTile)
		{
			sf::RenderWindow window;
			window.setActive(false);
			window.create(sf::VideoMode(1000, 1000), "title");
			Board board(sf::Vector2f(0, 0),
						sf::Color::Black,
						sf::Color(155, 155, 155, 100),
						sf::Color::Black,
						t_font,
						900,
						9,
						window);
			Tile tile = board.getTile(std::make_pair(0, 1));
			char expected = 0;
			char returned = tile.getValue();
			Assert::AreEqual(expected, returned);
			bool expected2 = true;
			bool returned2 = tile.isVisible();
			Assert::AreEqual(expected2, returned2);
		}
		TEST_METHOD(getIndex)
		{
			sf::RenderWindow window;
			window.setActive(false);
			window.create(sf::VideoMode(1000, 1000), "title");
			Board board(sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color(155, 155, 155, 100),
				sf::Color::Black,
				t_font,
				900,
				9,
				window);
			std::pair<int, int> expected(0, 0);
			std::pair<int, int> returned = board.getIndex(sf::Vector2i(1, 12));
			Assert::AreEqual(expected.first, returned.first);
			Assert::AreEqual(expected.second, returned.second);
		}
	};
}
