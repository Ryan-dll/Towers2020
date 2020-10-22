#include "pch.h"
#include "CppUnitTest.h"
#include <memory>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <Game.h>
#include "CppUnitTest.h"
#include "Tower.h"
#include "TowerProjectile.h"
#include "Item.h"
#include "TowerEight.h"
#include "TowerCross.h"
#include "TowerRing.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(TowerTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		
		TEST_METHOD(TowerEight)
		{
			CGame game;
			
			auto testTower1 = make_shared<CTowerEight>(&game);
			testTower1->setCoordinates(100, 100);

			Assert::IsTrue(testTower1->GetListLen() == 0);
			testTower1->ArmTower();
			Assert::IsTrue(testTower1->GetListLen() == 8);

			game.Add(testTower1);

			Assert::IsTrue(testTower1->GetX() == 100);
			Assert::IsTrue(testTower1->GetY() == 100);

			testTower1->Fire();
			Assert::IsTrue(testTower1->GetListLen() == 8);

			testTower1->setCoordinates(200, 200);

			Assert::IsTrue(testTower1->GetX() == 200);
			Assert::IsTrue(testTower1->GetY() == 200);
		}

		TEST_METHOD(TowerCross)
		{
			CGame game;

			auto testTower2 = make_shared<CTowerCross>(&game);
			testTower2->setCoordinates(100, 100);

			Assert::IsTrue(testTower2->GetCrossStatus() == true);

			game.Add(testTower2);

			Assert::IsTrue(testTower2->GetX() == 100);
			Assert::IsTrue(testTower2->GetY() == 100);

			testTower2->Fire();
			Assert::IsTrue(testTower2->GetCrossStatus() == false);

			testTower2->Fire();
			Assert::IsTrue(testTower2->GetCrossStatus() == true);

			testTower2->setCoordinates(200, 200);

			Assert::IsTrue(testTower2->GetX() == 200);
			Assert::IsTrue(testTower2->GetY() == 200);
		
		}
	};
}