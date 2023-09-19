#include <iostream>
#include <memory>
#include <string>
#include <ostream>

template<class T>
class Node
{
public:
	Node(const T val) : value{ val }
	{
	}

	friend std::ostream  & operator <<(std::ostream & output, const std::shared_ptr<Node<T>> &n)
	{

		output << n->value << " ";
		return output;
	}

	T value;
	std::shared_ptr<Node<T>> next{ nullptr };
};
template<class T>
class FerLinkList
{
public:

	FerLinkList(const T value)
	{
		tail = std::make_unique<Node<T>>(value);
		head = tail;
		size = 1;
	}

	friend std::ostream& operator<<(std::ostream & output, const FerLinkList<T> &list)
	{
		std::shared_ptr<Node<T>> temp = list.head;
		while (temp)
		{
			std::cout << temp;
			temp = temp->next;
		}

		return output;
	}

	void append(const T value)
	{
		std::shared_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);

		if (size == 0)
		{

			head = newNode;
			tail = newNode;

		}
		else
		{
			tail->next = newNode;
			tail = newNode;

		}
		size++;

	}
	void prepend(const T value)
	{
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);

		if (size == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{

			newNode->next = head;

			head = newNode;
		}
		size++;

	}

	void removeLast() noexcept
	{
		// tail i koparacaksýn
		if (size == 0)
		{
			return;

		}
		else if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			// tailin bir öncekine ihtiyaç var
			std::shared_ptr<Node<T>> temp = head;

			while (temp)
			{
				if (temp->next == tail)
					break;
				temp = temp->next;
			}
			tail = temp;
			tail->next = nullptr;
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
			head = nullptr;
			tail = nullptr;

		}
		else
		{
			std::shared_ptr<Node<T>> temp = head;

			head = head->next;
			temp = nullptr;


		}
		size--;
	}
	//get
	std::shared_ptr<Node<T>>  get(int index)
	{
		if (index >= size || size < 0)
			return nullptr;

		std::shared_ptr <Node<T>> temp = head;

		size_t cIndex{ 0 };
		while (temp)
		{
			if (cIndex == index)
			{
				break;
			}

			temp = temp->next;
			cIndex++;
		}
		return temp;
	}

	//setter
	T & operator [](int index)
	{
		std::shared_ptr <Node<T>> temp = head;

		size_t cIndex{ 0 };
		while (temp)
		{
			if (cIndex == index)
			{
				break;
			}

			temp = temp->next;
			cIndex++;
		}
		return temp->value;
	}

	std::shared_ptr<Node<T>> at(int index) const
	{
		std::shared_ptr <Node<T>> temp = head;

		size_t cIndex{ 0 };
		while (temp)
		{
			if (cIndex == index)
			{
				break;
			}

			temp = temp->next;
			cIndex++;
		}
		return temp;
	}

	void insert(int index, const T &value)
	{
		if (index < 0 || index>size)
			return;
		else if (index == 0)
		{
			prepend(value);
		}
		else if (index == size)
		{
			append(value);
		}
		else
		{
			std::shared_ptr<Node<T>>previousNode = get(index - 1);

			//Yeni bir node oluþturalým
			std::shared_ptr<Node<T>>newNode = std::make_shared<Node<T>>(value);

			newNode->next = previousNode->next;
			previousNode->next = newNode;

			size++;
		}
	}
	void reverse()
	{
		std::shared_ptr<Node<T>> temp = head;

		head = tail;

		tail = temp;

		std::shared_ptr<Node<T>> after = temp->next;
		std::shared_ptr<Node<T>> before = nullptr;

		for (int i = 0; i < size; i++)
		{
			after = temp->next;

			temp->next = before;

			before = temp;

			temp = after;
		}

	}
	void  removeAt(const int index)
	{
		if (index <0 || index>size)
		{
			return;
		}
		else if (index == 0)
		{
			removeFirst();

		}
		else if (index == size - 1)
		{
			removeLast();
		}
		else
		{
			std::shared_ptr<Node<T>> previousNode = get(index - 1);

			std::shared_ptr<Node<T>> temp = previousNode->next;

			previousNode->next = temp->next;

			temp = nullptr;
			size--;

		}
	}

	std::shared_ptr < Node<T>>  middle()
	{
		int midIndex = size / 2;

		return get(midIndex);
		

	}


	constexpr int count() const
	{
		return size;
	}

	std::shared_ptr<Node<T>> &first() 
	{
		return head;
	}
	std::shared_ptr<Node<T>> & last()
	{
		return tail;
	}

	int size{ 0 };

private:
	std::shared_ptr<Node<T>>  head;
	std::shared_ptr<Node<T>>  tail;
};

