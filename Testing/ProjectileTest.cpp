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
#include "Projectile.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(ProjectileTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}


		TEST_METHOD(DartAngleTest)
		{
			CGame game;

			auto testTower1 = make_shared<CTowerEight>(&game);
			testTower1->setCoordinates(100, 100);

			auto testDart1 = make_shared<CProjectile>(&game);
			testDart1->setCoordinates(100, 100);
			testDart1->SetOrigin(100, 100);

			game.Add(testTower1);
			game.Add(testDart1);

			Assert::IsTrue(testDart1->GetX() == 100);
			Assert::IsTrue(testDart1->GetY() == 100);

			testDart1->SetAngle(10);

			Assert::IsTrue(testDart1->GetAngle() == 10);

			Assert::IsTrue(testDart1->GetActive() == false);
		}


		TEST_METHOD(DartResetTest)
		{
			CGame game;

			auto testTower1 = make_shared<CTowerEight>(&game);
			testTower1->setCoordinates(100, 100);

			auto testDart1 = make_shared<CProjectile>(&game);
			testDart1->setCoordinates(100, 100);
			testDart1->SetOrigin(100, 100);

			game.Add(testTower1);
			game.Add(testDart1);

			testDart1->SetAngle(10);


			testDart1->ResetDart();
			Assert::IsTrue(testDart1->GetActive() == false);
			Assert::IsTrue(testDart1->GetX() == 100);
			Assert::IsTrue(testDart1->GetY() == 100);

			testDart1->setCoordinates(600,600);
			testDart1->ResetDart();

			// If the distance between origin and current coordinates is above 90, coordinates should be origin
			Assert::IsTrue(testDart1->GetX() == 100);
			Assert::IsTrue(testDart1->GetY() == 100);
		}
	};
}