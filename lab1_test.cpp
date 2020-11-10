//#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/varka/Documents/Алгоритмы/кхм/dualList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1test
{
	TEST_CLASS(lab1test)
	{
	public:
		dualList* test;
		dualList* test_2;
		TEST_METHOD_INITIALIZE(setup)
		{
			test = new dualList();
			test_2 = new dualList();
		}

		TEST_METHOD(at_correct_index)
		{
			test->push_back(1);
			test->push_back(2);
			Assert::AreEqual(test->at(1),2);
		}
		TEST_METHOD(at_incorrect_index)
		{
			try {
				test->at(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}

		}

		TEST_METHOD(test_IsEmptyTrue)
		{
			Assert::AreEqual(test->isEmpty(), true);
		}

		TEST_METHOD(test_IsEmptyFalse)
		{
			test->push_back(1);
			test->push_back(2);
			Assert::AreEqual(test->isEmpty(), false);
		}

		TEST_METHOD(test_PushFront)
		{
			test->push_front(3);
			test->push_front(2);
			test->push_front(1);
			Assert::AreEqual(test->at(0), 1);
		}
		TEST_METHOD(test_PushBack)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			Assert::AreEqual(test->at(2), 3);
		}
		TEST_METHOD(test_PushBackAndFront)
		{
			test->push_back(2);
			test->push_back(3);
			test->push_front(1);
			test->push_back(4);
			Assert::AreEqual(test->at(2), 3);
			Assert::AreEqual(test->at(0), 1);
			Assert::AreEqual(test->at(3), 4);
		}
		TEST_METHOD(test_GetSze)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			Assert::AreEqual(test->get_size(), (size_t)3);
		}
		TEST_METHOD(test_GetSzeEmpty)
		{
			Assert::AreEqual(test->get_size(), (size_t)0);
		}

		TEST_METHOD(test_PopBack)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->pop_back();
			test->pop_back();
			Assert::AreEqual(test->get_size(), (size_t)1);
			Assert::AreEqual(test->at(0), 1);
		}

		TEST_METHOD(test_PopBackFromEmpty)
		{
			try {
				test->pop_back();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Segmentation fault", e.what());
			}
		}
		TEST_METHOD(test_PopFront)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->pop_front();
			test->pop_front();
			Assert::AreEqual(test->get_size(), (size_t)1);
			Assert::AreEqual(test->at(0), 3);
		}

		TEST_METHOD(test_PopFrontFromEmpty)
		{
			try {
				test->pop_front();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Segmentation fault", e.what());
			}
		}

		TEST_METHOD(test_PopBackAndFrontFirst)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->push_front(0);
			test->pop_front();
			test->pop_back();
			Assert::AreEqual(test->get_size(), (size_t)2);
			Assert::AreEqual(test->at(0), 1);
		}
		TEST_METHOD(test_PopBackAndFrontLast)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->push_front(0);
			test->pop_front();
			test->pop_back();
			Assert::AreEqual(test->get_size(), (size_t)2);
			Assert::AreEqual(test->at(1), 2);
		}

		TEST_METHOD(test_Remove)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->remove(1);
			Assert::AreEqual(test->get_size(), (size_t)2);
			Assert::AreEqual(test->at(1), 3);
		}
		TEST_METHOD(test_RemoveFirst)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->remove(0);
			Assert::AreEqual(test->get_size(), (size_t)2);
			Assert::AreEqual(test->at(0), 2);
		}
		TEST_METHOD(test_RemoveLast)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->remove(2);
			Assert::AreEqual(test->get_size(), (size_t)2);
			Assert::AreEqual(test->at(1), 2);
		}
		TEST_METHOD(test_Remove_incorrect_index)
		{
			try {
				test->remove(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(test_Insert)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(4);
			test->insert(3, 2);
			Assert::AreEqual(test->get_size(), (size_t)4);
			Assert::AreEqual(test->at(2), 3);
		}
		TEST_METHOD(test_InsertFirst)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(4);
			test->insert(0, 0);
			Assert::AreEqual(test->get_size(), (size_t)4);
			Assert::AreEqual(test->at(0), 0);
			Assert::AreEqual(test->at(1), 1);
		}
		TEST_METHOD(test_Insert_incorrect_index)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			try {
				test->insert(4, 3);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(test_Clear)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->clear();
			Assert::AreEqual(test->isEmpty(), true);
		}
		TEST_METHOD(test_ClearEmpty)
		{
			test->clear();
			Assert::AreEqual(test->isEmpty(), true);
		}
		TEST_METHOD(test_ClearBeforePush)
		{
			test->push_back(1);
			test->clear();
			test->push_back(1);
			Assert::AreEqual(test->isEmpty(), false);
			Assert::AreEqual(test->at(0), 1);
		}
		TEST_METHOD(test_DoSTHAfterClear)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->clear();
			try {
				test->at(0);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(test_Set)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->set(1, 0);
			Assert::AreEqual(test->at(1), 0);
			Assert::AreEqual(test->at(2), 3);
		}

		TEST_METHOD(test_SetAfterAndBefore)
		{
			test->push_back(1);
			test->push_back(2);
			test->push_back(3);
			test->set(1, 0);
			Assert::AreEqual(test->at(0), 1);
			Assert::AreEqual(test->at(2), 3);
		}
		TEST_METHOD(test_Set_incorrect_index)
		{
			test->push_back(1);
			try {
				test->set(8, 0);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(test_PushBackList)
		{
			test_2->push_back(3);
			test_2->push_back(4);
			test->push_back(1);
			test->push_back(2);
			test->push_back(*test_2);
			Assert::AreEqual(test->get_size(), (size_t)4);
			Assert::AreEqual(test->at(2), 3);
		}
		TEST_METHOD(test_PushBackListLastItem)
		{
			test_2->push_back(3);
			test_2->push_back(4);
			test->push_back(1);
			test->push_back(2);
			test->push_back(*test_2);
			Assert::AreEqual(test->get_size(), (size_t)4);
			Assert::AreEqual(test->at(3), 4);
		}
		TEST_METHOD(test_PushBackListFirstItem)
		{
			test_2->push_back(3);
			test_2->push_back(4);
			test->push_back(2);
			test->push_front(1);
			test->push_back(*test_2);
			Assert::AreEqual(test->get_size(), (size_t)4);
			Assert::AreEqual(test->at(0), 1);
		}
		TEST_METHOD(test_PushBackListWithChangeFront)
		{
			test_2->push_back(3);
			test_2->push_back(4);
			test->push_back(2);
			test->push_front(1);
			test->push_back(*test_2);
			test->push_front(0);
			Assert::AreEqual(test->get_size(), (size_t)5);
			Assert::AreEqual(test->at(0), 0);
		}
		TEST_METHOD(test_PushBackListWithChangeLast)
		{
			test_2->push_back(3);
			test_2->push_back(4);
			test->push_back(2);
			test->push_front(1);
			test->push_back(*test_2);
			test->push_front(0);
			test->push_back(5);
			Assert::AreEqual(test->get_size(), (size_t)6);
			Assert::AreEqual(test->at(5), 5);
		}
	};
}
