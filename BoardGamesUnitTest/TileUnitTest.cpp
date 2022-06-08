#include <array>
#include <exception>
#include "CppUnitTest.h"
#include "../BoardGamesLib/tile.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Tile>(const Tile& t)
{
	std::wstring result;
	result += L"{";
	result += ToString(t);
	result += L"}";
	return result;
}


namespace TileUnitTest
{
	TEST_CLASS(TileUnitTest)
	{
	public:
		sf::Font t_font;
		TEST_METHOD_INITIALIZE(init)
		{
			sf::Font font;
			if (!font.loadFromFile("../resources/fonts/Qarolina.ttf")){}
			t_font = font;
		}
		TEST_METHOD(getValue_ch9)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				'9'
			);
			char expected = '9';
			char returned = tile.getValue();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(getValue_chz)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				'z'
			);
			char expected = 'z';
			char returned = tile.getValue();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(getValue_default)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				true
			);
			char expected = 0;
			char returned = tile.getValue();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(setValue_ch8)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				'9'
			);
			char expected = '9';
			char returned = tile.getValue();
			Assert::AreEqual(expected, returned);
			tile.setValue('8');
			expected = '8';
			returned = tile.getValue();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(setValue_chA)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				12
			);
			char expected = 12;
			char returned = tile.getValue();
			Assert::AreEqual(expected, returned);
			tile.setValue('A');
			expected = 'A';
			returned = tile.getValue();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(setValue_illegal)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				14
			);
			char expected = 14;
			char returned = tile.getValue();
			Assert::AreEqual(expected, returned);
			tile.setValue(-100);
			expected = -100;
			returned = tile.getValue();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(isVisible_yes)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				true,
				'z'
			);
			bool expected = true;
			bool returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(isVisible_no)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				'z'
			);
			bool expected = false;
			bool returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(setVisibility_no_to_no)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				'z'
			);
			bool expected = false;
			bool returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
			tile.setVisibility(false);
			returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(setVisibility_yes_to_yes)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				true,
				'z'
			);
			bool expected = true;
			bool returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
			tile.setVisibility(true);
			returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(setVisibility_no_to_yes)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				false,
				'z'
			);
			bool expected = false;
			bool returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
			tile.setVisibility(true);
			expected = true;
			returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
		}
		TEST_METHOD(setVisibility_yes_to_no)
		{
			Tile tile(
				sf::Vector2f(0, 0),
				sf::Color::Black,
				sf::Color::Red,
				sf::Color::White,
				t_font,
				80,
				true,
				'z'
			);
			bool expected = true;
			bool returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
			tile.setVisibility(false);
			expected = false;
			returned = tile.isVisible();
			Assert::AreEqual(expected, returned);
		}
	};
}
