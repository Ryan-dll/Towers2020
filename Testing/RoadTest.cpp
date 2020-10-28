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
	TEST_CLASS(TileRoadTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestSimpleGamePathing)
		{
			CGame testGame;
			testGame.SetStart(0, 0);
			wstring road = L"roadEW.png";
			wstring type = L"EW";
			auto road1 = make_shared<CTileRoad>(&testGame, road, type);
			road1->SetGrid(0, 0);
			testGame.Add(road1);
			auto road2 = make_shared<CTileRoad>(&testGame, L"roadEW.png", type);
			road2->SetGrid(1, 0);
			testGame.Add(road2);
			auto road3 = make_shared<CTileRoad>(&testGame, L"roadEW.png", type);
			road3->SetGrid(2, 0);
			testGame.Add(road3);
			auto road4 = make_shared<CTileRoad>(&testGame, L"roadEW.png", type);
			road4->SetGrid(3, 0);
			testGame.Add(road4);
			
			testGame.SetupPath();
			Assert::IsTrue(road1->GetNext() == road2.get());
			Assert::IsTrue(road2->GetNext() == road3.get());
			Assert::IsTrue(road3->GetNext() == road4.get());
				
			

		}
		
		TEST_METHOD(TestAdvancedGamePathing)
		{
			CGame testGame;
			testGame.SetStart(1, 0);
			auto road1 = make_shared<CTileRoad>(&testGame, L"roadNW.png", L"NW");
			road1->SetGrid(1, 0);
			testGame.Add(road1);
			auto road2 = make_shared<CTileRoad>(&testGame, L"roadSE.png", L"SE");
			road2->SetGrid(0, 0);
			testGame.Add(road2);
			auto road3 = make_shared<CTileRoad>(&testGame, L"roadNE.png", L"NE");
			road3->SetGrid(0, 1);
			testGame.Add(road3);
			auto road4 = make_shared<CTileRoad>(&testGame, L"roadSW.png", L"SW");
			road4->SetGrid(1, 1);
			testGame.Add(road4);
			
			testGame.SetupPath();
			Assert::IsTrue(road1->GetNext() == road2.get());
			Assert::IsTrue(road2->GetNext() == road3.get());
			Assert::IsTrue(road3->GetNext() == road4.get());
				
			

		}

	};
}