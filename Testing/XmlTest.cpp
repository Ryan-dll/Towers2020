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
	TEST_CLASS(XmlTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestBasic)
		{
			wstring path = TempPath() + L"test.xml";
			string level1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <level width=\"16\" height=\"16\" start-y=\"7\" start-x=\"0\"> <declarations> <road id=\"i001\" image=\"roadEW.png\" type=\"EW\"/> <road id=\"i002\" image=\"roadNS.png\" type=\"NS\"/> <road id=\"i003\" image=\"roadSE.png\" type=\"SE\"/> <road id=\"i004\" image=\"roadSW.png\" type=\"SW\"/> <road id=\"i005\" image=\"roadNE.png\" type=\"NE\"/> <road id=\"i006\" image=\"roadNW.png\" type=\"NW\"/> <open id=\"i007\" image=\"grass1.png\"/> <open id=\"i008\" image=\"grass2.png\"/> <house id=\"i011\" image=\"house1.png\"/> <trees id=\"i019\" image=\"trees2.png\"/> <trees id=\"i021\" image=\"trees4.png\"/> </declarations> <items> <trees id=\"i021\" x=\"0\" y=\"9\"/> <open id=\"i008\" x=\"0\" y=\"8\"/> <road id=\"i001\" x=\"0\" y=\"7\"/> <open id=\"i007\" x=\"0\" y=\"6\"/> <open id=\"i008\" x=\"0\" y=\"5\"/> <trees id=\"i019\" x=\"1\" y=\"9\"/> <open id=\"i007\" x=\"1\" y=\"8\"/> <road id=\"i001\" x=\"1\" y=\"7\"/> <open id=\"i008\" x=\"1\" y=\"6\"/> <open id=\"i007\" x=\"1\" y=\"5\"/> <open id=\"i008\" x=\"2\" y=\"9\"/> <road id=\"i005\" x=\"2\" y=\"8\"/> <road id=\"i004\" x=\"2\" y=\"7\"/> <open id=\"i007\" x=\"2\" y=\"6\"/> <open id=\"i007\" x=\"2\" y=\"5\"/> <open id=\"i007\" x=\"3\" y=\"9\"/> <road id=\"i006\" x=\"3\" y=\"8\"/> <road id=\"i002\" x=\"3\" y=\"7\"/> <road id=\"i003\" x=\"3\" y=\"6\"/> <open id=\"i008\" x=\"3\" y=\"5\"/> <open id=\"i007\" x=\"4\" y=\"9\"/> <open id=\"i007\" x=\"4\" y=\"8\"/> <open id=\"i007\" x=\"4\" y=\"7\"/> <road id=\"i001\" x=\"4\" y=\"6\"/> <house id=\"i011\" x=\"4\" y=\"5\"/> </items> </level>";
			WriteFile(path, level1);

			CGame game;
			game.Load(path);
			
			// Test item 0
			Assert::IsTrue(game.GetItem(0)->GetId().compare(L"i021") == 0);
			Assert::IsTrue(game.GetItem(0)->GetXGrid() == 0);
			Assert::IsTrue(game.GetItem(0)->GetYGrid() == 9);

			// Test item 1
			Assert::IsTrue(game.GetItem(1)->GetId().compare(L"i008") == 0);
			Assert::IsTrue(game.GetItem(1)->GetXGrid() == 0);
			Assert::IsTrue(game.GetItem(1)->GetYGrid() == 8);

			// Test item 2
			Assert::IsTrue(game.GetItem(2)->GetId().compare(L"i001") == 0);
			Assert::IsTrue(game.GetItem(2)->GetXGrid() == 0);
			Assert::IsTrue(game.GetItem(2)->GetYGrid() == 7);

			// Test item 3
			Assert::IsTrue(game.GetItem(3)->GetId().compare(L"i007") == 0);
			Assert::IsTrue(game.GetItem(3)->GetXGrid() == 0);
			Assert::IsTrue(game.GetItem(3)->GetYGrid() == 6);

			// Test item 4
			Assert::IsTrue(game.GetItem(4)->GetId().compare(L"i008") == 0);
			Assert::IsTrue(game.GetItem(4)->GetXGrid() == 0);
			Assert::IsTrue(game.GetItem(4)->GetYGrid() == 5);

			// Test item 15
			Assert::IsTrue(game.GetItem(15)->GetId().compare(L"i007") == 0);
			Assert::IsTrue(game.GetItem(15)->GetXGrid() == 3);
			Assert::IsTrue(game.GetItem(15)->GetYGrid() == 9);

			// Test item 25
			Assert::IsTrue(game.GetItem(24)->GetId().compare(L"i011") == 0);
			Assert::IsTrue(game.GetItem(24)->GetXGrid() == 4);
			Assert::IsTrue(game.GetItem(24)->GetYGrid() == 5);
		}

		TEST_METHOD(TestRoad)
		{
			wstring path = TempPath() + L"test.xml";
			string level1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <level width=\"16\" height=\"16\" start-y=\"7\" start-x=\"0\"> <declarations> <road id=\"i001\" image=\"roadEW.png\" type=\"EW\"/> <road id=\"i002\" image=\"roadNS.png\" type=\"NS\"/> <road id=\"i003\" image=\"roadSE.png\" type=\"SE\"/> <road id=\"i004\" image=\"roadSW.png\" type=\"SW\"/> <road id=\"i005\" image=\"roadNE.png\" type=\"NE\"/> <road id=\"i006\" image=\"roadNW.png\" type=\"NW\"/> <open id=\"i007\" image=\"grass1.png\"/> <open id=\"i008\" image=\"grass2.png\"/> <house id=\"i011\" image=\"house1.png\"/> <trees id=\"i019\" image=\"trees2.png\"/> <trees id=\"i021\" image=\"trees4.png\"/> </declarations> <items> <trees id=\"i021\" x=\"0\" y=\"9\"/> <open id=\"i008\" x=\"0\" y=\"8\"/> <road id=\"i001\" x=\"0\" y=\"7\"/> <open id=\"i007\" x=\"0\" y=\"6\"/> <open id=\"i008\" x=\"0\" y=\"5\"/> <trees id=\"i019\" x=\"1\" y=\"9\"/> <open id=\"i007\" x=\"1\" y=\"8\"/> <road id=\"i001\" x=\"1\" y=\"7\"/> <open id=\"i008\" x=\"1\" y=\"6\"/> <open id=\"i007\" x=\"1\" y=\"5\"/> <open id=\"i008\" x=\"2\" y=\"9\"/> <road id=\"i005\" x=\"2\" y=\"8\"/> <road id=\"i004\" x=\"2\" y=\"7\"/> <open id=\"i007\" x=\"2\" y=\"6\"/> <open id=\"i007\" x=\"2\" y=\"5\"/> <open id=\"i007\" x=\"3\" y=\"9\"/> <road id=\"i006\" x=\"3\" y=\"8\"/> <road id=\"i002\" x=\"3\" y=\"7\"/> <road id=\"i003\" x=\"3\" y=\"6\"/> <open id=\"i008\" x=\"3\" y=\"5\"/> <open id=\"i007\" x=\"4\" y=\"9\"/> <open id=\"i007\" x=\"4\" y=\"8\"/> <open id=\"i007\" x=\"4\" y=\"7\"/> <road id=\"i001\" x=\"4\" y=\"6\"/> <house id=\"i011\" x=\"4\" y=\"5\"/> </items> </level>";
			WriteFile(path, level1);

			CGame game;
			game.Load(path);

			// Test item 2, a road of type EW
			shared_ptr<CItem> item2 = game.GetItem(2);
			CTileRoad* road1 = dynamic_cast<CTileRoad*>(item2.get());
			Assert::IsTrue(road1->GetType().compare(L"EW") == 0);
			Assert::IsTrue(road1->GetId().compare(L"i001") == 0);

			// Test item 7, a road of type EW
			shared_ptr<CItem> item7 = game.GetItem(7);
			CTileRoad* road2 = dynamic_cast<CTileRoad*>(item7.get());
			Assert::IsTrue(road2->GetType().compare(L"EW") == 0);
			Assert::IsTrue(road2->GetId().compare(L"i001") == 0);

			// Test item 11, a road of type NE
			shared_ptr<CItem> item11 = game.GetItem(11);
			CTileRoad* road3 = dynamic_cast<CTileRoad*>(item11.get());
			Assert::IsTrue(road3->GetType().compare(L"NE") == 0);
			Assert::IsTrue(road3->GetId().compare(L"i005") == 0);

			// Test item 12, a road of type SW
			shared_ptr<CItem> item12 = game.GetItem(12);
			CTileRoad* road4 = dynamic_cast<CTileRoad*>(item12.get());
			Assert::IsTrue(road4->GetType().compare(L"SW") == 0);
			Assert::IsTrue(road4->GetId().compare(L"i004") == 0);

			// Test item 16, a road of type NW
			shared_ptr<CItem> item16 = game.GetItem(16);
			CTileRoad* road5 = dynamic_cast<CTileRoad*>(item16.get());
			Assert::IsTrue(road5->GetType().compare(L"NW") == 0);
			Assert::IsTrue(road5->GetId().compare(L"i006") == 0);

			// Test item 17, a road of type NS
			shared_ptr<CItem> item17 = game.GetItem(17);
			CTileRoad* road6 = dynamic_cast<CTileRoad*>(item17.get());
			Assert::IsTrue(road6->GetType().compare(L"NS") == 0);
			Assert::IsTrue(road6->GetId().compare(L"i002") == 0);

			// Test item 18, a road of type NS
			shared_ptr<CItem> item18 = game.GetItem(18);
			CTileRoad* road7 = dynamic_cast<CTileRoad*>(item18.get());
			Assert::IsTrue(road7->GetType().compare(L"SE") == 0);
			Assert::IsTrue(road7->GetId().compare(L"i003") == 0);
		}

		/**
		* Create a path to a place to put temporary files
		*/
		wstring TempPath()
		{
			// Create a path to temporary files
			wchar_t path_nts[MAX_PATH];
			GetTempPath(MAX_PATH, path_nts);

			// Convert null terminated string to wstring
			return wstring(path_nts);
		}

		/**
		* Read a file into a wstring and return it.
		* \param filename Name of the file to read
		* \return File contents
		*/
		wstring ReadFile(const wstring& filename)
		{
			ifstream t(filename);
			wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

			return str;
		}

		/**
		* Write a string to file
		* \param filename Name of the file to write to
		* \param content Content to write to file
		*/
		void WriteFile(const wstring& filename, string content)
		{
			std::ofstream ofs(filename, std::ofstream::out);
			ofs << content;
			ofs.close();
		}

	};
}