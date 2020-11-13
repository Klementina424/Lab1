//#include "pch.h"
#include "CppUnitTest.h"
#include "dualList.h" /*/Users/varka/Documents/Алгоритмы/кхм/*/

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1test
{
	TEST_CLASS(lab1test)
	{
	public:
		dualList* current_dual_list;
		dualList* another_dual_list;
		TEST_METHOD_INITIALIZE(setup)
		{
			current_dual_list = new dualList();
			another_dual_list = new dualList();
		}

		TEST_METHOD(at_correct_index)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			Assert::AreEqual(current_dual_list->at(1),2);
		}
		TEST_METHOD(at_incorrect_index)
		{
			try {
				current_dual_list->at(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}

		}

		TEST_METHOD(test_IsEmptyTrue)
		{
			Assert::AreEqual(current_dual_list->isEmpty(), true);
		}

		TEST_METHOD(test_IsEmptyFalse)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			Assert::AreEqual(current_dual_list->isEmpty(), false);
		}

		TEST_METHOD(test_PushFront)
		{
			current_dual_list->push_front(3);
			current_dual_list->push_front(2);
			current_dual_list->push_front(1);
			Assert::AreEqual(current_dual_list->at(0), 1);
		}
		TEST_METHOD(test_PushBack)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			Assert::AreEqual(current_dual_list->at(2), 3);
		}
		TEST_METHOD(test_PushBackAndFront)
		{
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->push_front(1);
			current_dual_list->push_back(4);
			Assert::AreEqual(current_dual_list->at(2), 3);
			Assert::AreEqual(current_dual_list->at(0), 1);
			Assert::AreEqual(current_dual_list->at(3), 4);
		}
		TEST_METHOD(test_GetSze)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			Assert::AreEqual(current_dual_list->get_size(), (size_t)3);
		}
		TEST_METHOD(test_GetSzeEmpty)
		{
			Assert::AreEqual(current_dual_list->get_size(), (size_t)0);
		}

		TEST_METHOD(test_PopBack)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->pop_back();
			current_dual_list->pop_back();
			Assert::AreEqual(current_dual_list->get_size(), (size_t)1);
			Assert::AreEqual(current_dual_list->at(0), 1);
		}

		TEST_METHOD(test_PopBackFromEmpty)
		{
			try {
				current_dual_list->pop_back();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Segmentation fault", e.what());
			}
		}
		TEST_METHOD(test_PopFront)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->pop_front();
			current_dual_list->pop_front();
			Assert::AreEqual(current_dual_list->get_size(), (size_t)1);
			Assert::AreEqual(current_dual_list->at(0), 3);
		}

		TEST_METHOD(test_PopFrontFromEmpty)
		{
			try {
				current_dual_list->pop_front();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Segmentation fault", e.what());
			}
		}

		TEST_METHOD(test_PopBackAndFrontFirst)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->push_front(0);
			current_dual_list->pop_front();
			current_dual_list->pop_back();
			Assert::AreEqual(current_dual_list->get_size(), (size_t)2);
			Assert::AreEqual(current_dual_list->at(0), 1);
		}
		TEST_METHOD(test_PopBackAndFrontLast)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->push_front(0);
			current_dual_list->pop_front();
			current_dual_list->pop_back();
			Assert::AreEqual(current_dual_list->get_size(), (size_t)2);
			Assert::AreEqual(current_dual_list->at(1), 2);
		}

		TEST_METHOD(test_Remove)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->remove(1);
			Assert::AreEqual(current_dual_list->get_size(), (size_t)2);
			Assert::AreEqual(current_dual_list->at(1), 3);
		}
		TEST_METHOD(test_RemoveFirst)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->remove(0);
			Assert::AreEqual(current_dual_list->get_size(), (size_t)2);
			Assert::AreEqual(current_dual_list->at(0), 2);
		}
		TEST_METHOD(test_RemoveLast)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->remove(2);
			Assert::AreEqual(current_dual_list->get_size(), (size_t)2);
			Assert::AreEqual(current_dual_list->at(1), 2);
		}
		TEST_METHOD(test_Remove_incorrect_index)
		{
			try {
				current_dual_list->remove(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(test_Insert)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(4);
			current_dual_list->insert(3, 2);
			Assert::AreEqual(current_dual_list->get_size(), (size_t)4);
			Assert::AreEqual(current_dual_list->at(2), 3);
		}
		TEST_METHOD(test_InsertFirst)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(4);
			current_dual_list->insert(0, 0);
			Assert::AreEqual(current_dual_list->get_size(), (size_t)4);
			Assert::AreEqual(current_dual_list->at(0), 0);
			Assert::AreEqual(current_dual_list->at(1), 1);
		}
		TEST_METHOD(test_Insert_incorrect_index)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			try {
				current_dual_list->insert(4, 3);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(test_Clear)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->clear();
			Assert::AreEqual(current_dual_list->isEmpty(), true);
		}
		TEST_METHOD(test_ClearEmpty)
		{
			current_dual_list->clear();
			Assert::AreEqual(current_dual_list->isEmpty(), true);
		}
		TEST_METHOD(test_ClearBeforePush)
		{
			current_dual_list->push_back(1);
			current_dual_list->clear();
			current_dual_list->push_back(1);
			Assert::AreEqual(current_dual_list->isEmpty(), false);
			Assert::AreEqual(current_dual_list->at(0), 1);
		}
		TEST_METHOD(test_DoSTHAfterClear)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->clear();
			try {
				current_dual_list->at(0);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(test_Set)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->set(1, 0);
			Assert::AreEqual(current_dual_list->at(1), 0);
			Assert::AreEqual(current_dual_list->at(2), 3);
		}

		TEST_METHOD(test_SetAfterAndBefore)
		{
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->set(1, 0);
			Assert::AreEqual(current_dual_list->at(0), 1);
			Assert::AreEqual(current_dual_list->at(2), 3);
		}
		TEST_METHOD(test_Set_incorrect_index)
		{
			current_dual_list->push_back(1);
			try {
				current_dual_list->set(8, 0);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
		TEST_METHOD(test_list_in_list)
		{
			current_dual_list = new dualList();
			another_dual_list = new dualList();
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->push_back(4);
			another_dual_list->push_back(2);
			another_dual_list->push_back(4);
			Assert::AreEqual(current_dual_list->list_in_list(another_dual_list), false);
		}
		TEST_METHOD(test_list_in_list2)
		{
			current_dual_list = new dualList();
			another_dual_list = new dualList();
			current_dual_list->push_back(1);
			current_dual_list->push_back(2);
			current_dual_list->push_back(3);
			current_dual_list->push_back(4);
			another_dual_list->push_back(1);
			another_dual_list->push_back(2);
			Assert::AreEqual(current_dual_list->list_in_list(another_dual_list), true);
		}
		
	};
}
