#include "InterviewQuestions.h"
using namespace std;

void LinkListOperations()
{
	FerLinkList<int> list(100.6);

// Append
list.append(34.21);	// Complexity O(1)
list.append(55.33);	// Complexity O(1)
//
// prepend 
list.prepend(1);	// Complexity O(1)
list.prepend(21);	// Complexity O(1)
list.prepend(13);	// Complexity O(1)
list.prepend(111); // Complexity O(1)



// remove last
list.removeLast();  // Complexty o(n)
list.removeLast();	// Complexty o(n)

std::cout << "List before remove first :"<<std::endl<<list<<std::endl;

// remove first
list.removeFirst();  // complexty(1)

std::cout << "List after remove first :" << std::endl << list << std::endl;

 //Insert
list.insert(2, 444);
std::cout << "List after insert :" << std::endl << list << std::endl;

// Remove
list.removeAt(2);
std::cout << "List after remove :" << std::endl << list << std::endl;

// Insert
list.insert(1, 111111);
std::cout << "List after insert :" << std::endl << list << std::endl;

// Remove
list.removeAt(1);
std::cout << "List after remove :" << std::endl << list << std::endl;

// reverse
list.reverse();
std::cout << "List after reverse:" << std::endl << list << std::endl;

std::cout << "Middle:" << list.middle() << std::endl;

// Make loop

list.last()->next = list.first();

// test
std::cout<< Questions::LinkList::hasLoop(list)<<std::endl;

FerLinkList<int> temp(1);
temp.append(4);
temp.append(3);
temp.append(2);
temp.append(5);
temp.append(2);

std::cout << "List before parionate :" << temp << std::endl;

Questions::LinkList::partitionList(temp, 3);
std::cout << "List after parionate :" << temp << std::endl;

Questions::LinkList::removeDuplicates(temp);
std::cout << "List after removeDuplicate:" << temp << std::endl;
}

void DoubleLinkListPlayGround()
{
	SecondCase::DoubleLinkList<int> myList{ 1,2,3,4,5 };
	
	std::cout << myList;

	std::cout << "After Prepend" << std::endl;
	myList.prepend(12312321);
	std::cout << myList;

	std::cout << "After append" << std::endl;
	myList.append(333);
	std::cout << myList;

	std::cout << "After remove last" << std::endl;
	myList.removeLast();

	std::cout << myList;

	// Delete first item
	std::cout << "After removing first item" << std::endl;
	
	myList.removeFirst();

	std::cout << myList;

	// insert item
	myList.insert(321, 2);
	std::cout << "Inserting item" << std::endl;
	std::cout << myList;

	// delete item
	myList.remove(3);
	std::cout << "Removing item" << std::endl;
	std::cout << myList;


	// delete item
	myList.remove(1);
	std::cout << "Removing item" << std::endl;
	std::cout << myList;
}
int main()
{

	DoubleLinkListPlayGround();

}


