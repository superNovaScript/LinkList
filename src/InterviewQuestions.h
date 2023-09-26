#pragma once
#include "FerLinkList.h"
#include "DoubleLinkList.h"
namespace Questions
{
	namespace LinkList
	{
		template <class T>
		void partitionList(FerLinkList<T> &originalList, int x)
		{
			FerLinkList<T> lessList(33);
			FerLinkList<T> greaterList(22);


			std::shared_ptr<Node<T>> iter = originalList.first();
			while (iter)
			{
				auto currentValue = iter->value;
				if (currentValue < x)
				{
					lessList.append(currentValue);
				}
				else
				{
					greaterList.append(currentValue);
				}
				iter = iter->next;
			}
			// Update heads
			lessList.first() = lessList.first()->next;
			greaterList.first() = greaterList.first()->next;


			// Merge two list
			lessList.last()->next = greaterList.first();

			originalList.first() = lessList.first();

		}
		template<class T>
		bool hasLoop(FerLinkList<T> & list)
		{
			if (list.count() == 0)
				return false;
			else if (list.last()->next == list.first())
			{
				return true;
			}
			else if (list.count() == 1)
			{
				return false;
			}
			else
			{
				auto fast = list.first()->next->next;
				auto tail = list.last();
				auto slow = tail->next;

				while (fast)
				{
					if (fast == slow)
					{
						return true;
					}
					fast = fast->next->next;
					slow = slow->next;
				}
				return false;
			}


		}

		template<class T>
		void removeDuplicates(FerLinkList<T> &list)
		{
			std::shared_ptr<Node<T>> current = list.first();
			

			while (current)
			{
				// Take current value
				const T currentValue = current->value;
				
				// Define a runner node
				std::shared_ptr<Node<T>> runner = current->next;

				// Define a previous node for runner it is necessary to create link while deleting a node.
				std::shared_ptr<Node<T>> runnerPrevious = current;

				while (runner)
				{

					const T runnerValue = runner->value;

					if (currentValue == runnerValue)
					{

						// Delete this node on original list. Establish connections properly regarding to the deletion.
						
						runnerPrevious->next = runner->next;

						std::shared_ptr<Node<T>> deletionNode = runner;
						deletionNode = nullptr;
						list.size--;
					}
					runner = runner->next;


				}

				current = current->next;
			}



		}

		
		int binaryToDecimal(FerLinkList<int> &list)
		{

			int num{ 0 };
			
			std::shared_ptr<Node<int>> current = list.first();

			while (current)
			{
				num = num * 2 + current->value;
			}

			return num;

		}
	}

	
	namespace Second {

		template <class T>
		void swapFirstLast(SecondCase::DoubleLinkList<T> &list)
		{
			
			size_t size = list.count();
			

			if (size == 0)
			{
				//do nothing
			}
			else if(size ==1)
			{
				// do nothing

				
			}
			else
			{
				Node<T> head = list.getHead();
				Node<T> tail = list.getTail();

				head.value = tail.value;
			}

		}

	}



}