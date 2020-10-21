#include "pch.h"
#include "CppUnitTest.h"
#include <memory>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <Game.h>

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
		
		TEST_METHOD(Test1)
		{
			wstring path = TempPath() + L"test.xml";
			string level1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <level width=\"16\" height=\"16\" start-y=\"13\" start-x=\"0\"><declarations><road id=\"i001\" image=\"roadEW.png\" type=\"EW\"/><road id=\"i002\" image=\"roadNS.png\" type=\"NS\"/><road id=\"i003\" image=\"roadSE.png\" type=\"SE\"/><road id=\"i004\" image=\"roadSW.png\" type=\"SW\"/><road id=\"i005\" image=\"roadNE.png\" type=\"NE\"/><road id=\"i006\" image=\"roadNW.png\" type=\"NW\"/><open id=\"i007\" image=\"grass1.png\"/><open id=\"i008\" image=\"grass2.png\"/><house id=\"i011\" image=\"house1.png\"/><house id=\"i012\" image=\"house2.png\"/><house id=\"i013\" image=\"house3.png\"/><house id=\"i014\" image=\"house4a.png\"/><house id=\"i015\" image=\"house4b.png\"/><house id=\"i016\" image=\"castlea.png\"/><house id=\"i017\" image=\"castleb.png\"/><trees id=\"i018\" image=\"trees1.png\"/><trees id=\"i019\" image=\"trees2.png\"/><trees id=\"i020\" image=\"trees3.png\"/><trees id=\"i021\" image=\"trees4.png\"/></declarations><items><open id=\"i007\" x=\"0\" y=\"15\"/><open id=\"i008\" x=\"0\" y=\"14\"/><road id=\"i001\" x=\"0\" y=\"13\"/><open id=\"i008\" x=\"0\" y=\"12\"/><open id=\"i007\" x=\"0\" y=\"11\"/><open id=\"i008\" x=\"0\" y=\"10\"/><open id=\"i007\" x=\"0\" y=\"9\"/><open id=\"i008\" x=\"0\" y=\"8\"/><open id=\"i008\" x=\"0\" y=\"7\"/><open id=\"i008\" x=\"0\" y=\"6\"/><open id=\"i007\" x=\"0\" y=\"5\"/><trees id=\"i019\" x=\"0\" y=\"4\"/><trees id=\"i019\" x=\"0\" y=\"3\"/><trees id=\"i020\" x=\"0\" y=\"2\"/><trees id=\"i021\" x=\"0\" y=\"1\"/><open id=\"i007\" x=\"0\" y=\"0\"/><trees id=\"i019\" x=\"1\" y=\"15\"/><open id=\"i007\" x=\"1\" y=\"14\"/><road id=\"i006\" x=\"1\" y=\"13\"/><road id=\"i002\" x=\"1\" y=\"12\"/><road id=\"i002\" x=\"1\" y=\"11\"/><road id=\"i003\" x=\"1\" y=\"10\"/><house id=\"i011\" x=\"1\" y=\"9\"/><open id=\"i008\" x=\"1\" y=\"8\"/><open id=\"i008\" x=\"1\" y=\"7\"/><house id=\"i017\" x=\"1\" y=\"6\"/><house id=\"i016\" x=\"1\" y=\"5\"/><open id=\"i008\" x=\"1\" y=\"4\"/><trees id=\"i019\" x=\"1\" y=\"3\"/><trees id=\"i020\" x=\"1\" y=\"2\"/><trees id=\"i021\" x=\"1\" y=\"1\"/><trees id=\"i021\" x=\"1\" y=\"0\"/><trees id=\"i020\" x=\"2\" y=\"15\"/><trees id=\"i020\" x=\"2\" y=\"14\"/><trees id=\"i020\" x=\"2\" y=\"13\"/><open id=\"i007\" x=\"2\" y=\"12\"/><open id=\"i008\" x=\"2\" y=\"11\"/><road id=\"i001\" x=\"2\" y=\"10\"/><open id=\"i007\" x=\"2\" y=\"9\"/><road id=\"i005\" x=\"2\" y=\"8\"/><road id=\"i002\" x=\"2\" y=\"7\"/><road id=\"i002\" x=\"2\" y=\"6\"/><road id=\"i002\" x=\"2\" y=\"5\"/><road id=\"i003\" x=\"2\" y=\"4\"/><open id=\"i007\" x=\"2\" y=\"3\"/><trees id=\"i020\" x=\"2\" y=\"2\"/><trees id=\"i021\" x=\"2\" y=\"1\"/><trees id=\"i021\" x=\"2\" y=\"0\"/><trees id=\"i021\" x=\"3\" y=\"15\"/><trees id=\"i019\" x=\"3\" y=\"14\"/><trees id=\"i021\" x=\"3\" y=\"13\"/><trees id=\"i019\" x=\"3\" y=\"12\"/><open id=\"i007\" x=\"3\" y=\"11\"/><road id=\"i001\" x=\"3\" y=\"10\"/><open id=\"i008\" x=\"3\" y=\"9\"/><road id=\"i001\" x=\"3\" y=\"8\"/><open id=\"i008\" x=\"3\" y=\"7\"/><open id=\"i007\" x=\"3\" y=\"6\"/><open id=\"i007\" x=\"3\" y=\"5\"/><road id=\"i001\" x=\"3\" y=\"4\"/><house id=\"i011\" x=\"3\" y=\"3\"/><open id=\"i007\" x=\"3\" y=\"2\"/><trees id=\"i020\" x=\"3\" y=\"1\"/><trees id=\"i020\" x=\"3\" y=\"0\"/><trees id=\"i021\" x=\"4\" y=\"15\"/><trees id=\"i020\" x=\"4\" y=\"14\"/><trees id=\"i021\" x=\"4\" y=\"13\"/><trees id=\"i020\" x=\"4\" y=\"12\"/><open id=\"i008\" x=\"4\" y=\"11\"/><road id=\"i006\" x=\"4\" y=\"10\"/><road id=\"i002\" x=\"4\" y=\"9\"/><road id=\"i004\" x=\"4\" y=\"8\"/><open id=\"i007\" x=\"4\" y=\"7\"/><trees id=\"i020\" x=\"4\" y=\"6\"/><trees id=\"i019\" x=\"4\" y=\"5\"/><road id=\"i001\" x=\"4\" y=\"4\"/><open id=\"i007\" x=\"4\" y=\"3\"/><road id=\"i005\" x=\"4\" y=\"2\"/><road id=\"i003\" x=\"4\" y=\"1\"/><trees id=\"i019\" x=\"4\" y=\"0\"/><trees id=\"i021\" x=\"5\" y=\"15\"/><trees id=\"i020\" x=\"5\" y=\"14\"/><trees id=\"i020\" x=\"5\" y=\"13\"/><trees id=\"i020\" x=\"5\" y=\"12\"/><open id=\"i007\" x=\"5\" y=\"11\"/><open id=\"i007\" x=\"5\" y=\"10\"/><house id=\"i015\" x=\"5\" y=\"9\"/><house id=\"i014\" x=\"5\" y=\"8\"/><trees id=\"i019\" x=\"5\" y=\"7\"/><trees id=\"i020\" x=\"5\" y=\"6\"/><open id=\"i007\" x=\"5\" y=\"5\"/><road id=\"i006\" x=\"5\" y=\"4\"/><road id=\"i002\" x=\"5\" y=\"3\"/><road id=\"i004\" x=\"5\" y=\"2\"/><road id=\"i001\" x=\"5\" y=\"1\"/><open id=\"i007\" x=\"5\" y=\"0\"/><trees id=\"i019\" x=\"6\" y=\"15\"/><trees id=\"i020\" x=\"6\" y=\"14\"/><open id=\"i007\" x=\"6\" y=\"13\"/><open id=\"i007\" x=\"6\" y=\"12\"/><open id=\"i008\" x=\"6\" y=\"11\"/><open id=\"i008\" x=\"6\" y=\"10\"/><open id=\"i007\" x=\"6\" y=\"9\"/><open id=\"i007\" x=\"6\" y=\"8\"/><trees id=\"i018\" x=\"6\" y=\"7\"/><open id=\"i007\" x=\"6\" y=\"6\"/><open id=\"i008\" x=\"6\" y=\"5\"/><open id=\"i007\" x=\"6\" y=\"4\"/><trees id=\"i020\" x=\"6\" y=\"3\"/><open id=\"i007\" x=\"6\" y=\"2\"/><road id=\"i001\" x=\"6\" y=\"1\"/><house id=\"i011\" x=\"6\" y=\"0\"/><open id=\"i008\" x=\"7\" y=\"15\"/><open id=\"i007\" x=\"7\" y=\"14\"/><road id=\"i005\" x=\"7\" y=\"13\"/><road id=\"i002\" x=\"7\" y=\"12\"/><road id=\"i002\" x=\"7\" y=\"11\"/><road id=\"i002\" x=\"7\" y=\"10\"/><road id=\"i002\" x=\"7\" y=\"9\"/><road id=\"i002\" x=\"7\" y=\"8\"/><road id=\"i002\" x=\"7\" y=\"7\"/><road id=\"i002\" x=\"7\" y=\"6\"/><road id=\"i003\" x=\"7\" y=\"5\"/><trees id=\"i021\" x=\"7\" y=\"4\"/><trees id=\"i019\" x=\"7\" y=\"3\"/><trees id=\"i021\" x=\"7\" y=\"2\"/><road id=\"i001\" x=\"7\" y=\"1\"/><open id=\"i007\" x=\"7\" y=\"0\"/><open id=\"i007\" x=\"8\" y=\"15\"/><open id=\"i008\" x=\"8\" y=\"14\"/><road id=\"i001\" x=\"8\" y=\"13\"/><house id=\"i011\" x=\"8\" y=\"12\"/><open id=\"i007\" x=\"8\" y=\"11\"/><open id=\"i007\" x=\"8\" y=\"10\"/><open id=\"i008\" x=\"8\" y=\"9\"/><open id=\"i007\" x=\"8\" y=\"8\"/><open id=\"i008\" x=\"8\" y=\"7\"/><house id=\"i013\" x=\"8\" y=\"6\"/><road id=\"i001\" x=\"8\" y=\"5\"/><trees id=\"i019\" x=\"8\" y=\"4\"/><trees id=\"i021\" x=\"8\" y=\"3\"/><trees id=\"i020\" x=\"8\" y=\"2\"/><road id=\"i001\" x=\"8\" y=\"1\"/><house id=\"i012\" x=\"8\" y=\"0\"/><open id=\"i008\" x=\"9\" y=\"15\"/><open id=\"i008\" x=\"9\" y=\"14\"/><road id=\"i001\" x=\"9\" y=\"13\"/><house id=\"i011\" x=\"9\" y=\"12\"/><open id=\"i007\" x=\"9\" y=\"11\"/><open id=\"i007\" x=\"9\" y=\"10\"/><open id=\"i007\" x=\"9\" y=\"9\"/><open id=\"i008\" x=\"9\" y=\"8\"/><open id=\"i007\" x=\"9\" y=\"7\"/><open id=\"i007\" x=\"9\" y=\"6\"/><road id=\"i001\" x=\"9\" y=\"5\"/><open id=\"i008\" x=\"9\" y=\"4\"/><open id=\"i007\" x=\"9\" y=\"3\"/><open id=\"i008\" x=\"9\" y=\"2\"/><road id=\"i001\" x=\"9\" y=\"1\"/><open id=\"i007\" x=\"9\" y=\"0\"/><open id=\"i007\" x=\"10\" y=\"15\"/><road id=\"i005\" x=\"10\" y=\"14\"/><road id=\"i004\" x=\"10\" y=\"13\"/><open id=\"i007\" x=\"10\" y=\"12\"/><open id=\"i007\" x=\"10\" y=\"11\"/><road id=\"i005\" x=\"10\" y=\"10\"/><road id=\"i002\" x=\"10\" y=\"9\"/><road id=\"i003\" x=\"10\" y=\"8\"/><open id=\"i007\" x=\"10\" y=\"7\"/><road id=\"i005\" x=\"10\" y=\"6\"/><road id=\"i004\" x=\"10\" y=\"5\"/><open id=\"i007\" x=\"10\" y=\"4\"/><road id=\"i005\" x=\"10\" y=\"3\"/><road id=\"i002\" x=\"10\" y=\"2\"/><road id=\"i004\" x=\"10\" y=\"1\"/><open id=\"i007\" x=\"10\" y=\"0\"/><open id=\"i007\" x=\"11\" y=\"15\"/><road id=\"i006\" x=\"11\" y=\"14\"/><road id=\"i002\" x=\"11\" y=\"13\"/><road id=\"i002\" x=\"11\" y=\"12\"/><road id=\"i002\" x=\"11\" y=\"11\"/><road id=\"i004\" x=\"11\" y=\"10\"/><open id=\"i007\" x=\"11\" y=\"9\"/><road id=\"i001\" x=\"11\" y=\"8\"/><open id=\"i008\" x=\"11\" y=\"7\"/><road id=\"i001\" x=\"11\" y=\"6\"/><trees id=\"i018\" x=\"11\" y=\"5\"/><trees id=\"i020\" x=\"11\" y=\"4\"/><road id=\"i001\" x=\"11\" y=\"3\"/><open id=\"i007\" x=\"11\" y=\"2\"/><open id=\"i007\" x=\"11\" y=\"1\"/><open id=\"i007\" x=\"11\" y=\"0\"/><open id=\"i008\" x=\"12\" y=\"15\"/><open id=\"i008\" x=\"12\" y=\"14\"/><open id=\"i007\" x=\"12\" y=\"13\"/><open id=\"i008\" x=\"12\" y=\"12\"/><open id=\"i007\" x=\"12\" y=\"11\"/><trees id=\"i019\" x=\"12\" y=\"10\"/><trees id=\"i020\" x=\"12\" y=\"9\"/><road id=\"i001\" x=\"12\" y=\"8\"/><open id=\"i007\" x=\"12\" y=\"7\"/><road id=\"i001\" x=\"12\" y=\"6\"/><open id=\"i008\" x=\"12\" y=\"5\"/><trees id=\"i020\" x=\"12\" y=\"4\"/><road id=\"i001\" x=\"12\" y=\"3\"/><open id=\"i007\" x=\"12\" y=\"2\"/><trees id=\"i020\" x=\"12\" y=\"1\"/><trees id=\"i018\" x=\"12\" y=\"0\"/><open id=\"i008\" x=\"13\" y=\"15\"/><open id=\"i007\" x=\"13\" y=\"14\"/><road id=\"i005\" x=\"13\" y=\"13\"/><road id=\"i003\" x=\"13\" y=\"12\"/><house id=\"i013\" x=\"13\" y=\"11\"/><trees id=\"i019\" x=\"13\" y=\"10\"/><open id=\"i007\" x=\"13\" y=\"9\"/><road id=\"i001\" x=\"13\" y=\"8\"/><open id=\"i007\" x=\"13\" y=\"7\"/><road id=\"i006\" x=\"13\" y=\"6\"/><road id=\"i002\" x=\"13\" y=\"5\"/><road id=\"i002\" x=\"13\" y=\"4\"/><road id=\"i004\" x=\"13\" y=\"3\"/><trees id=\"i018\" x=\"13\" y=\"2\"/><trees id=\"i021\" x=\"13\" y=\"1\"/><trees id=\"i021\" x=\"13\" y=\"0\"/><open id=\"i008\" x=\"14\" y=\"15\"/><open id=\"i008\" x=\"14\" y=\"14\"/><road id=\"i001\" x=\"14\" y=\"13\"/><road id=\"i006\" x=\"14\" y=\"12\"/><road id=\"i002\" x=\"14\" y=\"11\"/><road id=\"i002\" x=\"14\" y=\"10\"/><road id=\"i002\" x=\"14\" y=\"9\"/><road id=\"i004\" x=\"14\" y=\"8\"/><open id=\"i008\" x=\"14\" y=\"7\"/><open id=\"i007\" x=\"14\" y=\"6\"/><house id=\"i015\" x=\"14\" y=\"5\"/><house id=\"i014\" x=\"14\" y=\"4\"/><open id=\"i007\" x=\"14\" y=\"3\"/><trees id=\"i021\" x=\"14\" y=\"2\"/><trees id=\"i021\" x=\"14\" y=\"1\"/><trees id=\"i020\" x=\"14\" y=\"0\"/><open id=\"i008\" x=\"15\" y=\"15\"/><open id=\"i008\" x=\"15\" y=\"14\"/><road id=\"i001\" x=\"15\" y=\"13\"/><open id=\"i008\" x=\"15\" y=\"12\"/><open id=\"i007\" x=\"15\" y=\"11\"/><open id=\"i008\" x=\"15\" y=\"10\"/><open id=\"i007\" x=\"15\" y=\"9\"/><open id=\"i008\" x=\"15\" y=\"8\"/><open id=\"i007\" x=\"15\" y=\"7\"/><open id=\"i007\" x=\"15\" y=\"6\"/><open id=\"i007\" x=\"15\" y=\"5\"/><open id=\"i007\" x=\"15\" y=\"4\"/><open id=\"i007\" x=\"15\" y=\"3\"/><trees id=\"i021\" x=\"15\" y=\"2\"/><trees id=\"i021\" x=\"15\" y=\"1\"/><trees id=\"i021\" x=\"15\" y=\"0\"/></items></level>";
			WriteFile(path, level1);

			CGame game;
			game.Load(path);
			//game.mAllGameItems
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