#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Balloon.h"
#include "TileRoad.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(TestBalloon)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		

		TEST_METHOD(TestBalloonRoad)
		{
			// This is an empty test just to ensure the system is working
			CGame game;
			shared_ptr<CBalloon> balloon = make_shared<CBalloon>(&game);
			CTileRoad road(&game, L"", L"");
			road.GiveBalloon(balloon);
			Assert::IsTrue(road.NumBalloons() == 1);
			shared_ptr<CBalloon> balloon1 = make_shared<CBalloon>(&game);
			road.GiveBalloon(balloon1);
			Assert::IsTrue(road.NumBalloons() == 2);
			road.Update(20);
			// Balloons are gone
			Assert::IsTrue(road.NumBalloons() == 0);
		}

	};
}