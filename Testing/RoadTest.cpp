#include "pch.h"
#include "CppUnitTest.h"
#include <memory>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <Game.h>
#include "TileTrees.h"
#include "TileRoad.h"
#include "TileOpen.h"
#include "TileHouse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

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
		TEST_METHOD(TestSimpleGamePathing)
		{
			// This is an empty test just to ensure the system is working
			CGame testGame;
			testGame.SetStart(0, 0);
			auto road1 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road1->SetGrid(0, 0);
			testGame.Add(road1);
			auto road2 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road2->SetGrid(0, 1);
			testGame.Add(road2);
			auto road3 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road3->SetGrid(0, 2);
			testGame.Add(road3);
			auto road4 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road4->SetGrid(0, 3);
			testGame.Add(road4);
			
			testGame.SetupPath();
			Assert::IsTrue(road1->GetNext() == road2.get());
			Assert::IsTrue(road2->GetNext() == road3.get());
			Assert::IsTrue(road3->GetNext() == road4.get());
				
			

		}
		
		TEST_METHOD(TestAdvancedGamePathing)
		{
			// This is an empty test just to ensure the system is working
			CGame testGame;
			testGame.SetStart(0, 0);
			auto road1 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road1->SetGrid(0, 0);
			testGame.Add(road1);
			auto road2 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road2->SetGrid(0, 1);
			testGame.Add(road2);
			auto road3 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road3->SetGrid(0, 2);
			testGame.Add(road3);
			auto road4 = make_shared<CTileRoad>(&testGame, L"roadEW.png", L"WE");
			road4->SetGrid(0, 3);
			testGame.Add(road4);
			
			testGame.SetupPath();
			Assert::IsTrue(road1->GetNext() == road2.get());
			Assert::IsTrue(road2->GetNext() == road3.get());
			Assert::IsTrue(road3->GetNext() == road4.get());
				
			

		}

	};
}