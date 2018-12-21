/*unittest1.cpp*/

//
// myvector class test harness
//
// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS341, Spring 2018
// Project #03
//

#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\myvector\myvector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace myvectorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test01)
		{
      myvector<int>  V;

      V.push_back(1);
      V.push_back(2);
      V.push_back(3);

      Assert::IsTrue(V.front() == 1);
      Assert::IsTrue(V.back() == 3);
		}

	};
}