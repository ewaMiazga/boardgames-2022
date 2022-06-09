#include "CppUnitTest.h"
#include "..\BoardGamesLib\User.h"
#include "..\BoardGamesLib\Stats.h"

// -------------------------------------------------- Bartlomiej Niewiarowski ----------------------------------------------------------

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UserTests
{
	TEST_CLASS(UserTests)
	{
	public:
		TEST_METHOD(TestInitUser)
		{
			user first;
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(0, first.get_y());
			Assert::AreEqual(0, first.get_points());
		}

		TEST_METHOD(TestMove1)
		{
			user first;
			first.move(1, 0);
			Assert::AreEqual(1, first.get_x());
			Assert::AreEqual(0, first.get_y());
		}

		TEST_METHOD(TestMove2)
		{
			user first;
			first.move(-1, 0);
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(0, first.get_y());
		}

		TEST_METHOD(TestMove3)
		{
			user first;
			first.move(2, 0);
			first.move(-1, 0);
			Assert::AreEqual(1, first.get_x());
			Assert::AreEqual(0, first.get_y());
		}

		TEST_METHOD(TestMove4)
		{
			user first;
			first.move(0, 1);
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(1, first.get_y());
		}

		TEST_METHOD(TestMove5)
		{
			user first;
			first.move(0, -1);
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(0, first.get_y());
		}

		TEST_METHOD(TestMove6)
		{
			user first;
			first.move(0, 2);
			first.move(0, -1);
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(1, first.get_y());
		}

		TEST_METHOD(TestAddPoint)
		{
			user first;
			first.add_point();
			Assert::AreEqual(1, first.get_points());
		}

		TEST_METHOD(TestResetPosition)
		{
			user first;
			first.reset_position();
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(0, first.get_y());
			Assert::AreEqual(0, first.get_points());
		}

		TEST_METHOD(TestResetPosition1)
		{
			user first;
			first.move(2, 2);
			first.reset_position();
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(0, first.get_y());
			Assert::AreEqual(0, first.get_points());
		}

		TEST_METHOD(TestIsPremium)
		{
			user first;
			Assert::IsFalse(first.is_premium());
		}
		// USER ACCOUNT
		TEST_METHOD(TestInitUserAccountDefault)
		{
			user_account first;
			std::string name = "user_1";
			time_t t = 0;
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(0, first.get_y());
			Assert::AreEqual(0, first.get_points());
			Assert::AreEqual(name, first.get_name());
			Assert::AreEqual(t, first.get_current_sesion());
		}

		TEST_METHOD(TestInitUserAccount)
		{
			user_account first("Player2002");
			std::string name = "Player2002";
			time_t t = 0;
			Assert::AreEqual(0, first.get_x());
			Assert::AreEqual(0, first.get_y());
			Assert::AreEqual(0, first.get_points());
			Assert::AreEqual(name, first.get_name());
			Assert::AreEqual(t, first.get_current_sesion());
		}

		TEST_METHOD(TestInitUserAccountWithStats)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			time_t t = 200;
			std::string title = "Sudoku";
			user_account first("Player2002", Sudoku, TTC, Crosswords);

			Assert::AreEqual(t, first.get_sudoku_stats().get_time());
			Assert::AreEqual(title, first.get_sudoku_stats().get_title());
			Assert::AreEqual(50, first.get_sudoku_stats().get_points());

			t = 1000;
			title = "Tic Tac Toe";
			Assert::AreEqual(t, first.get_ttc_stats().get_time());
			Assert::AreEqual(title, first.get_ttc_stats().get_title());
			Assert::AreEqual(20, first.get_ttc_stats().get_points());

			t = 200;
			title = "Crosswords";
			Assert::AreEqual(t, first.get_crosswords_stats().get_time());
			Assert::AreEqual(title, first.get_crosswords_stats().get_title());
			Assert::AreEqual(30, first.get_crosswords_stats().get_points());
		}

		TEST_METHOD(TestUserAccountSetName)
		{
			user_account first;
			std::string name = "Bartek";
			first.set_name(name);
			Assert::AreEqual(name, first.get_name());
		}

		TEST_METHOD(TestUserSetSudokuStats)
		{
			user_account first;
			stats Sudoku("Sudoku", 2500, 400);

			first.set_sudoku_stats(Sudoku);

			time_t t = 2500;
			std::string title = "Sudoku";

			Assert::AreEqual(t, first.get_sudoku_stats().get_time());
			Assert::AreEqual(title, first.get_sudoku_stats().get_title());
			Assert::AreEqual(400, first.get_sudoku_stats().get_points());
		}

		TEST_METHOD(TestUserSetTTCStats)
		{
			user_account first;
			stats TTC("Tic Tac Toe", 2500, 400);

			first.set_ttc_stats(TTC);

			time_t t = 2500;
			std::string title = "Tic Tac Toe";

			Assert::AreEqual(t, first.get_ttc_stats().get_time());
			Assert::AreEqual(title, first.get_ttc_stats().get_title());
			Assert::AreEqual(400, first.get_ttc_stats().get_points());
		}

		TEST_METHOD(TestUserSetCrosswordsStats)
		{
			user_account first;
			stats Sudoku("Crosswords", 2500, 400);

			first.set_crosswords_stats(Sudoku);

			time_t t = 2500;
			std::string title = "Crosswords";

			Assert::AreEqual(t, first.get_crosswords_stats().get_time());
			Assert::AreEqual(title, first.get_crosswords_stats().get_title());
			Assert::AreEqual(400, first.get_crosswords_stats().get_points());
		}

		TEST_METHOD(TestStartGame1)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			user_account first("Player2002", Sudoku, TTC, Crosswords);
			first.start_game("Sudoku");
			std::string game = "Sudoku";
			Assert::AreEqual(game, first.get_current_game());
		}

		TEST_METHOD(TestStartGame2)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			user_account first("Player2002", Sudoku, TTC, Crosswords);
			first.start_game("TicTacToe");
			std::string game = "TicTacToe";
			Assert::AreEqual(game, first.get_current_game());
		}

		TEST_METHOD(TestStartGame3)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			user_account first("Player2002", Sudoku, TTC, Crosswords);
			first.start_game("Crosswords");
			std::string game = "Crosswords";
			Assert::AreEqual(game, first.get_current_game());
		}

		TEST_METHOD(TestStopGame)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			user_account first("Player2002", Sudoku, TTC, Crosswords);
			first.start_game("Sudoku");
			first.add_point();
			first.stop_game();
			Assert::AreEqual(51, first.get_sudoku_stats().get_points());
		}

		TEST_METHOD(TestShowMyStats1)
		{
			user_account first("new_user");
			size_t n = 1;
			Assert::AreEqual(n, first.show_my_stats().size());
		}

		TEST_METHOD(TestShowMyStats2)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			user_account first("Player2002", Sudoku, TTC, Crosswords);
			size_t n = 5;
			Assert::AreEqual(n, first.show_my_stats().size());
		}

		TEST_METHOD(TestIsPremiumAccount)
		{
			user_account first;
			Assert::IsFalse(first.is_premium());
		}

		TEST_METHOD(TestUpdateToPremium)
		{
			user_account first;
			Assert::IsFalse(first.update_to_premium());
		}

		TEST_METHOD(TestUpdateToPremiumTrue)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			user_account first("Player2002", Sudoku, TTC, Crosswords);
			Assert::IsTrue(first.update_to_premium());
		}

		// Premium User
		TEST_METHOD(TestInitPremiumUser)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			time_t t = 200;
			std::string title = "Sudoku";
			premium_user first("Player2002", Sudoku, TTC, Crosswords);

			Assert::AreEqual(t, first.get_sudoku_stats().get_time());
			Assert::AreEqual(title, first.get_sudoku_stats().get_title());
			Assert::AreEqual(50, first.get_sudoku_stats().get_points());

			t = 1000;
			title = "Tic Tac Toe";
			Assert::AreEqual(t, first.get_ttc_stats().get_time());
			Assert::AreEqual(title, first.get_ttc_stats().get_title());
			Assert::AreEqual(20, first.get_ttc_stats().get_points());

			t = 200;
			title = "Crosswords";
			Assert::AreEqual(t, first.get_crosswords_stats().get_time());
			Assert::AreEqual(title, first.get_crosswords_stats().get_title());
			Assert::AreEqual(30, first.get_crosswords_stats().get_points());
		}

		TEST_METHOD(TestIsPremium2)
		{
			premium_user first;
			Assert::IsTrue(first.is_premium());
		}

		TEST_METHOD(TestUpdate)
		{
			stats Sudoku("Sudoku", 200, 50), TTC("Tic Tac Toe", 1000, 20), Crosswords("Crosswords", 200, 30);
			time_t t = 200;
			std::string title = "Sudoku";
			user_account default_user("Player2002", Sudoku, TTC, Crosswords);
			premium_user first = update_to_premium(default_user);

			Assert::AreEqual(t, first.get_sudoku_stats().get_time());
			Assert::AreEqual(title, first.get_sudoku_stats().get_title());
			Assert::AreEqual(50, first.get_sudoku_stats().get_points());

			t = 1000;
			title = "Tic Tac Toe";
			Assert::AreEqual(t, first.get_ttc_stats().get_time());
			Assert::AreEqual(title, first.get_ttc_stats().get_title());
			Assert::AreEqual(20, first.get_ttc_stats().get_points());

			t = 200;
			title = "Crosswords";
			Assert::AreEqual(t, first.get_crosswords_stats().get_time());
			Assert::AreEqual(title, first.get_crosswords_stats().get_title());
			Assert::AreEqual(30, first.get_crosswords_stats().get_points());
		}
	};
}