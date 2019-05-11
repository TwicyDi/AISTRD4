#include "stdafx.h"
#include "CppUnitTest.h"
#include "../main/BF.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_for_BF
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(min_cost_1)
		{
			int matrix[4][4] = { { -1,20,-1,-1 },{ 10,-1,35,-1 },{ 14,40,-1,13 },{ 35,30,8,-1 } };
			int **check = new int*[4];
			for (int i = 0; i <4; i++)
				check[i] = new int[4];
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					check[i][j] = matrix[i][j];
			int min;
			find_way(check, 4, 2, 0, min);
			Assert::AreEqual(min, 55);
		}

		TEST_METHOD(min_cost_2)
		{
			int matrix[4][4] = { { -1,20,-1,-1 },{ 10,-1,35,-1 },{ 14,40,-1,13 },{ 35,30,8,-1 } };
			int **check = new int*[4];
			for (int i = 0; i <4; i++)
				check[i] = new int[4];
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					check[i][j] = matrix[i][j];
			int min;
			find_way(check, 4, 1, 0, min);
			Assert::AreEqual(min, 20);
		}

		TEST_METHOD(min_cost_3)
		{
			int matrix[4][4] = { { -1,20,-1,-1 },{ 10,-1,35,-1 },{ 14,40,-1,13 },{ 35,30,8,-1 } };
			int **check = new int*[4];
			for (int i = 0; i <4; i++)
				check[i] = new int[4];
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					check[i][j] = matrix[i][j];
			int min;
			find_way(check, 4, 3, 2, min);
			Assert::AreEqual(min, 13);
		}

		TEST_METHOD(min_cost_4)
		{
			int matrix[4][4] = { { -1,20,-1,-1 },{ 10,-1,35,-1 },{ 14,40,-1,13 },{ 35,30,8,-1 } };
			int **check = new int*[4];
			for (int i = 0; i <4; i++)
				check[i] = new int[4];
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					check[i][j] = matrix[i][j];
			int min;
			find_way(check, 4, 1, 3, min);
			Assert::AreEqual(min, 30);
		}

		TEST_METHOD(min_cost_5)
		{
			int matrix[4][4] = { { -1,20,-1,-1 },{ 10,-1,35,-1 },{ 14,40,-1,13 },{ 35,30,8,-1 } };
			int **check = new int*[4];
			for (int i = 0; i <4; i++)
				check[i] = new int[4];
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					check[i][j] = matrix[i][j];
			int min;
			find_way(check, 4, 0, 3, min);
			Assert::AreEqual(min, 22);
		}
	};
}