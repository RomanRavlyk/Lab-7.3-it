#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.3 it/Lab 7.3 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int rowCount = 3, colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            Create(a, rowCount, colCount, -17, 15);

            int count = 0;
            countColumnsWithZero(a, rowCount, colCount, count);
            int longestSeriesRow = -1;
            int maxSeriesLength = 0;
            FindRowWithLongestSeries(a, rowCount, colCount, longestSeriesRow, maxSeriesLength);

           
            Assert::AreEqual(0, count);

            
            Assert::AreEqual(-1, longestSeriesRow);

        }
    };
}