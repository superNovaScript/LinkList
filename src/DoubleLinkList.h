#pragma once

#include <iostream>
#include <algorithm>
namespace SecondCase
{
	template<class T>
	class Node
	{
	public:
		Node(T val) : next{ nullptr }, previous{ nullptr }, value{ val }
		{

		};
		~Node()
		{
			std::cout << "Called dctor of " << this << std::endl;
		}
		friend std::ostream  & operator <<(std::ostream & output, const Node<T> *n)
		{

			output << n->value << " ";
			return output;
		}
	public:
		Node<T> * next;
		Node<T> * previous;
		T value;
	};

	template<class T>
	class DoubleLinkList
	{
	public:
		DoubleLinkList() noexcept : head{ nullptr }, tail{ nullptr }, size{ 0 }
		{};

		DoubleLinkList(T value) noexcept
		{
			// Create a new node
			Node<T> * newNode = new Node(value);

			// Set head and tails
			head = newNode ;
			tail =  newNode ;

			// Increment counter
			size = 1;
		}

		DoubleLinkList(std::initializer_list<T> vals)
		{
			std::for_each(vals.begin(), vals.end(), [=](int val) { append(val); });
		}

		~DoubleLinkList()
		{
			Node<T> * currentNode = head;
			while (currentNode)
			{
			
				// Store previous node
				Node<T> *previous =currentNode->previous;
				
				// Delete it
				delete previous;
				previous = nullptr;

				
				if (!currentNode->next)
				{
					// Next node not available we are at the end of list then delete current one
					delete currentNode;
					currentNode = nullptr;
					break;
				}
				// go further
				currentNode = currentNode->next;

			}
		}

		void append(T value)
		{
			Node<T> *newNode = new Node<T>(value);

			// Update head and tail
			if (size == 0)
			{
				head = newNode ;
				tail =  newNode;
			}
			else
			{
				tail->next = newNode;
				newNode->previous = tail;
				tail = newNode;
			}

			size++;
		}

		void prepend(T value)
		{
			Node<T> *newNode = new Node<T>(value);

			if (size == 0)
			{
				head = newNode;
				tail = newNode;
			}
			else
			{
				newNode->next = head;
				head->previous = newNode;
				head = newNode;
			}
			size++;

		}

		void removeLast()
		{
			if (size <= 0)
				return;
			else if (size == 1)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				Node <T> *temp = tail;
				tail = temp->previous;
				tail->next = nullptr;

				delete temp;
				temp = nullptr;
				
			}

			size--;
		}

		void removeFirst()
		{

			if (size == 0)
			{
				return;
			}
			else if (size == 1)
			{
				delete head; 
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				Node<T> * temp = head;
				head = temp->next;
				head->previous = nullptr;

				delete temp;
				temp = nullptr;
			}
			size--;

		}
		Node <T>*  get(int index) const
		{
			if (index >= size || index < 0)
				return nullptr;

			Node<T>* temp = head;

			if (index < size / 2)
			{
				for (size_t i = 0; i < index; i++)
				{
					temp = temp->next;
				}
			}
			else
			{
				temp = tail;
				for (size_t i = size-1; i >index; i--)
				{
					temp = temp->previous;
				}
			}
			return temp;
		}
		void set(int index, T val)
		{
			if (index >= size || index < 0)
				return;

			Node <T> *currentNode = get(index);

			// Set the value
			currentNode->value = val;
		}

		void insert(const T &val, const int index)
		{
			if (index > size || index < 0)
			{
				return;
			}
			else if (index == 0)
			{
				prepend(val);
			}
			else if (index == size)
			{
				append(val);
			}
			else
			{

				Node<T> *previousNode = get(index - 1);
				
				Node <T> *newNode = new Node<T>(val);
				
				// New node'u ayarla
				newNode->next = previousNode->next;
				newNode->previous = previousNode;
				newNode->next->previous = newNode;

				// Previous node'u ayarla
				previousNode->next = newNode;


				size++;
			}
		}

		void remove(const int index)
		{
			if (index > size || index < 0)
			{
				return;
			}
			else if (index == 0)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
				size--;
			}
			else if (index == size)
			{
				// new tail
				Node<T> *previous = tail->previous;
				delete tail;
				tail = nullptr;
				
				tail = previous;
				tail->next = nullptr;
				size--;
			}
			else
			{
				Node<T> *currentNode = get(index);

				Node<T> *previous = currentNode->previous;
				Node<T> *next = currentNode->next;

				previous->next = next;
				next->previous = previous;

				delete currentNode;
				currentNode = nullptr;
				size--;

			}

		}

		friend std::ostream  & operator <<(std::ostream & output, const DoubleLinkList<T> &list)
		{
			Node<T> * currentNode = list.getHead();
			while (currentNode)
			{
				output << currentNode;
				currentNode = currentNode->next;
			}

			output << std::endl;
			return output;

		}

		Node<T> * getHead() const
		{
			return head;
		}

		Node<T> * getTail() const
		{
			return tail;
		}

		int count() const
		{
			return size;
		}

	private:
		Node<T> * head;
		Node<T> * tail;
		int size{ 0 };

	};

}

