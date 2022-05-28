#include <array>
#include <exception>
#include "CppUnitTest.h"
#include "../UIlib/ui.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Obj>(const Obj& t)
{
	std::wstring result;
	result += L"{";
	result += ToString(t);
	result += L"}";
	return result;
}


namespace uiUnitTest
{
	TEST_CLASS(uiUnitTest)
	{
	public:
		
		TEST_METHOD(placeholder)
		{
			Assert::IsTrue(true == true);
		}
		

	};
}
