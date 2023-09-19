#include "InterviewQuestions.h"

using namespace std;




int main()
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


