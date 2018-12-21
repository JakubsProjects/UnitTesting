/*unittest1.cpp*/

//
// myvector class test harness
//
// <<Jakub Glebocki>>
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


		TEST_METHOD(Test02)
		{
			myvector<int>  V;

			Assert::IsTrue(V.size() == 0);

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);

			Assert::IsTrue(V.size() == 3);
		}

		//This test, tests if node increases in size by *2
		TEST_METHOD(Test03)
		{
			myvector<int>  V;

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			//Check to see if full
			Assert::IsTrue(V.capacity() == 4);
			//add 2 more elements
			V.push_back(5);
			V.push_back(6);
			//Check to see if created new vector
			Assert::IsTrue(V.capacity() == 12);

			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			//Seeing if node is full
			Assert::IsTrue(V.capacity() == 12);

			//push back 1 element
			V.push_back(13);
			//Tests to see if new node created(if capacity increased)
			Assert::IsTrue(V.capacity() == 28);
		}

		//test to see if Num of nodes is correct, size is correct, and capacity is correct.
		TEST_METHOD(Test04)
		{
			myvector<int>  V;

			for (int i = 0; i < 1019; i++) {
				V.push_back(i);
			}
			
			Assert::IsTrue(V.nodes() == 8);
		
			Assert::IsTrue(V.size() == 1019);

			Assert::IsTrue(V.capacity() == 1020);
		}


		//This inserts elements and checks the following:
		TEST_METHOD(Test05)
		{
			myvector<int>  V;
			
			for (int i = 0; i <= 999; i++) {
				V.push_back(i);
			}

			//If num of nodes correct
			Assert::IsTrue(V.nodes() == 8);

			//If size is correct
			Assert::IsTrue(V.size() == 1000);

			//if cacpacity is correct
			Assert::IsTrue(V.capacity() == 1020);

			//if first and alst element is correct
			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 999);

			//addnign 1 more element
			V.push_back(1010);

			//Seeing if element inserted correctly
			Assert::IsTrue(V.back() == 1010);
		}

		//Tests the [] operator, if we can access elements successfully from any available position
		TEST_METHOD(Test06)
		{
			
			myvector<int>  V;

			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			//Check if sizes match
			Assert::IsTrue(V.capacity() == V.size());

			V.push_back(5);
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);

			Assert::IsTrue(V.capacity() == V.size());
			V.push_back(13);
			V.push_back(14);

			Assert::IsFalse(V.capacity() == V.size());

			//Check if each is correctly inserted
			//checks if all elements are correct inserted by using [] operator
			Assert::IsTrue(V[0] == 1);
			Assert::IsTrue(V[1] == 2);
			Assert::IsTrue(V[2] == 3);
			Assert::IsTrue(V[3] == 4);
			Assert::IsTrue(V[4] == 5);
			Assert::IsTrue(V[5] == 6);
			Assert::IsTrue(V[6] == 7);
			Assert::IsTrue(V[7] == 8);
			Assert::IsTrue(V[8] == 9);
			Assert::IsTrue(V[9] == 10);
			Assert::IsTrue(V[10] == 11);
			Assert::IsTrue(V[11] == 12);
			Assert::IsTrue(V[12] == 13);
			Assert::IsTrue(V[13] == 14);

			//Checks the size, front, back, # of node and capacity
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 14);

			Assert::IsTrue(V.nodes() == 3);

			Assert::IsTrue(V.size() == 14);

			Assert::IsTrue(V.capacity() == 28);
		}

		//This test tests for if sizes and all are correct after inserting
		TEST_METHOD(Test07)
		{
			myvector<int>  V;

			for (int i = 0; i < 2000; i++) {
				V.push_back(i);
			}

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 1999);

			Assert::IsTrue(V.nodes() == 9);

			Assert::IsTrue(V.size() == 2000);

			Assert::IsTrue(V.capacity() == 2044);
		}

		//Testing strings in stead of ints
		TEST_METHOD(Test08)
		{
			myvector<string>  V;

			
		 V.push_back("Professor");
		 V.push_back("Hummel");
		 V.push_back("is");
		 V.push_back("a");
		 V.push_back("very");
		 V.push_back("interesting");
		 V.push_back("Guy");
			
		 
		 Assert::IsTrue(V[0] == "Professor");
		 Assert::IsTrue(V[1] == "Hummel");
		 Assert::IsTrue(V[2] == "is");
		 Assert::IsTrue(V[3] == "a");
		 Assert::IsTrue(V[4] == "very");
		 Assert::IsTrue(V[5] == "interesting");
		 Assert::IsTrue(V[6] == "Guy");

		 Assert::IsTrue(V.front() == "Professor");
	     Assert::IsTrue(V.back() == "Guy");

		 Assert::IsTrue(V.nodes() == 2);
		 Assert::IsTrue(V.size() == 7);
		 Assert::IsTrue(V.capacity() == 12);
		}

		//Test string input and pushback
		TEST_METHOD(Test09)
		{
			myvector<char>  V;
			unsigned char a = 'a';
			for (int i = 0; i < 26; i++) {
				a = 'a' + i;
				V.push_back(a);
			}

			//adding 1 to each character. a + 1 = b
			for (int i = 0; i < 26; i++) {
				Assert::IsTrue(V[i] == 'a' + i);
			}

			//Seeing if correct
			Assert::IsTrue(V.nodes() == 3);
			Assert::IsTrue(V.size() == 26);
			Assert::IsTrue(V.capacity() == 28);
		}

		//This tests the copy constrcutor
		TEST_METHOD(Test10)
		{

			myvector<int>  V;
			
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(4);
			V.push_back(5);

			//Testing copy constructor
			myvector<int> CopyofV = V;

			//Testing to see if size, pos, front, and back are correct
			Assert::IsTrue(CopyofV.size() == 5);
			Assert::IsTrue(CopyofV[4] == 5);
			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 5);

			//# of nodes created
			Assert::IsTrue(V.nodes() == 2);
			Assert::IsTrue(V.size() == 5);
			
			V.push_back(6);
			V.push_back(7);
			V.push_back(8);
			V.push_back(9);
			V.push_back(10);
			V.push_back(11);
			V.push_back(12);
			V.push_back(13);


			Assert::IsTrue(V.front() == 1);
			Assert::IsTrue(V.back() == 13);
			Assert::IsTrue(V.nodes() == 3);
			Assert::IsTrue(V.size() == 13);
			Assert::IsTrue(V.capacity() == 28);

			//Capacity should NOT match size
			Assert::IsFalse(V.capacity() == V.size());
		}

		//Testing if iterators advance properly
		TEST_METHOD(Test11)
		{
			myvector<int>  V;
			int j = 0;
			for (int i = 0; i < 10; i++) {
				V.push_back(i);
			}

			for (auto e : V) {
				Assert::IsTrue(e == j);
				j++;
			}
				
			auto iter = V.begin();
			
			Assert::IsTrue(*iter == 0);
			++iter;
			Assert::IsTrue(*iter == 1);
			++iter;
			Assert::IsTrue(*iter == 2);
			++iter;
			Assert::IsTrue(*iter == 3);
			++iter;
			Assert::IsTrue(*iter == 4);
			++iter;
			Assert::IsTrue(*iter == 5);
			
		}

		//Testing iterators
		TEST_METHOD(Test12) {
			myvector<int> V;
			int Number = 15;
			int compare = 0;
			for (int a = 0; a < Number; a++) {
				V.push_back(a + 2);

			}

			//looping through them
			for (auto iterator = V.begin(); iterator != V.end(); ++iterator) {
				Assert::IsTrue(compare + 2 == *iterator);
				compare++;
			}
			//Testing if number and compare are the same
			Assert::IsTrue(Number == compare);
		}

		//Tests for iterators and it goes over everything
		TEST_METHOD(Test13) {
			myvector<int> V;
			int Number = 60;

			for (int a = 0; a < Number; a++) {
				V.push_back(a);
			}

			Assert::IsTrue(V.front() == 0);
			Assert::IsTrue(V.back() == 59);
			Assert::IsTrue(V.size() == 60);
			Assert::IsTrue(V.nodes() == 4);
			Assert::IsTrue(V.capacity() == 60);

			auto iterator1 = V.begin();
			auto iterator2 = V.end();

			int position = 0;


			for (iterator1; iterator1 != iterator2; ++iterator1) {
				Assert::IsTrue(V[position] == *iterator1);
				position++;

			}

			Assert::IsTrue(Number == position);
		}
		
		//Test copy constructor, if everything copied was indeed copied successfully.
		TEST_METHOD(Test14) {
			myvector<int>  V;

			for (int i = 0; i < 2044; i++) {
				V.push_back(i);
			}


			myvector<int>  CopyV = V;
			int i = 0;

			for (int j = 0; j < 2044; j++) {
				Assert::IsTrue(CopyV[j] == i);
				++i;
			}

			myvector<int>  V1;
			int k = 0;
			for (k = 0; k < 2044; k++) {
				V1.push_back(k);
			}

			myvector<int>  V2 = V1;

			
			for (int i = k - 1; i >= 0; i--) {
				Assert::IsTrue(V2[i] == V1[i]);
			}
		}

	};



}