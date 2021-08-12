/*Write a class template for queue class. Assume the programmer using the queue won't make mistakes, like exceeding the capacity of the queue or trying to remove an item when the queue is empty. Define several queues of different data types and insert and remove data from them.

*/
#include <iostream>
#include <string>
using namespace std;


template<typename T>
class Queue
{
private:
	int front, rear; 
	static const int m_maxsize=100;

	T m_queue[m_maxsize];
public:
	Queue()
	:
	front(0), rear(0)
	{

	}
	void enqueue(T data)
	{
	
		if ( rear == m_maxsize ) {
			cout << "Queue is full\n";
		}
		else {
			m_queue[rear++] = data;

		}

	}
	void dequeue()
	{
		if ( front == rear )
			cout << "Queue is empty\n";
		else {
			for ( int i =0; i < rear-1; ++i) // or rear+1
				m_queue[i] = m_queue[i+1];
			rear--;
		}
		
	}
	void display()
	{
		if ( front == rear)
			cout << "Queue is empty";
		else {
			for ( int i = front; i < rear; ++i)
				cout <<  m_queue[i] << "<-";
		}
	}
	void show_front()
	{
		if ( front == rear)
			cout << "Queue is empty";
		else 
			cout << m_queue[front];
	}
	


};

int main()
{
	Queue<int> ageQueque;
	Queue<string> gameQueque;

	cout << "\nchecking exception handled or not\n";
	ageQueque.dequeue();

	ageQueque.enqueue(23);
	ageQueque.enqueue(24);
	ageQueque.enqueue(26);

	gameQueque.enqueue("Football");
	gameQueque.enqueue("Tennis");
	gameQueque.enqueue("Basketball");
	gameQueque.enqueue("Hockey");
	gameQueque.enqueue("VolleyBall");

	cout << "\nchecking enqueue exception handled or not\n";
	gameQueque.enqueue("Basketball");
	cout << "\nAge queue\n";
	ageQueque.display();
	cout << "\nGame queue\n";
	gameQueque.display();

	gameQueque.dequeue();
	ageQueque.dequeue();

	cout << "\n\nAfter deleting 1 node in each\n";

	cout << "\nAge queue\n";
	ageQueque.display();
	cout << "\nGame queue\n";
	gameQueque.display();


}