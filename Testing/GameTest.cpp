#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}
		TEST_METHOD(TestGamePathing)
		{
			// This is an empty test just to ensure the system is working
			CGame testGame;
//			CTileRoad road1(testGame, L"", L"");
		}
	};
}