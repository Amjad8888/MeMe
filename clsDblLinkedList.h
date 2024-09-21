#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;



template <class T>



class clsDblLinkedList
{


protected:

	T _Size;
	
	
public:

	class Node
	{

	
	public:
		int _value;
		Node* next;
		Node* prev;

	};

	Node* head = NULL;

	void InsertAtBegging(T value)
	{
		Node* New = new Node();
		New->_value = value;
		if (head!=NULL)
		{
			New->next = head;
			head->prev = New;
			
		}
		
		head = New;
		
		_Size++;
	}
	
	void print() {
		Node* Current = head;
		cout << endl;
		while (Current!=NULL)
		{
			cout << Current->_value << " " ;
			Current = Current->next;
		}
		delete Current;
		cout << endl;
	}

	Node* Find(T value)
	{
		Node* Current = head;
		
		if (Current!= NULL)
		{
			while (Current != NULL && Current->_value != value)
			{
				Current = Current->next;
			}

			return Current;
		}
			
		
		return NULL;
	}

	
	
	void InsertAtEnd(T value)
	{
		Node* New = new Node();
		New->_value = value;
		Node* Current = head;
		if (Current ==NULL)
		{
			New->prev = NULL;
			head = New;
			return;
		}
		if (Current->next==NULL)
		{
			Current->next = New;
			New->prev = Current;
			_Size++;
			return;
		}
		while (Current->next!=NULL)
		{
			Current = Current->next;
		}
		Current->next = New;
		New->prev = Current;
		_Size++;
		return;
	}

	void  InsertAfter(T valueFind, T valueInset)
	{
		Node* New = new Node();
		New->_value = valueInset;
		Node* Item = GetNode(valueFind);
		if (Item == NULL)
		{
			return;
		}

		if (Item->next == NULL)
		{
			InsertAtEnd(valueInset);
			return;
		}
		New->next = Item->next;
		Item->next->prev = New;
		Item->next = New;
		New->prev = Item;
		_Size++;
		return;

	}
	bool DeleteFirst()
	{
		if (head == NULL)
		{
			return false;
		}
		else
		{
			Node* temp = head;
			head = temp->next;
			head->prev = NULL;
			_Size--;
			delete temp;
			
			
			return true;
		}
	}

	bool DeleteEnd()
	{
		if (head ==NULL)
		{
			return false;
		}
		Node* Current = head;
		while (Current->next!=NULL)
		{
			Current = Current->next;
		}
		
		Current->prev->next = NULL;
		Current = NULL;
		_Size--;
		return true;
	}

	bool DeleteNode(T item)
	{
		if (head == NULL)
		{
			return false;
		}
		if (head->next == NULL)
		{
			head = NULL;
			_Size--;
			return false;
		}

		Node* N = Find(item);
		Node* Current = head;

		
		if (N != NULL)
		{

			if (N->prev == NULL)
			{
				return DeleteFirst();
			}

			if (Current->next == NULL)
			{
				return DeleteEnd();
			}

			while (Current!=N && Current!= NULL)
			{
				
				Current = Current->next;

			}
			if (Current->next == NULL)
			{
				return DeleteEnd();
			}
			else
			{
				Current->prev->next = Current->next;
				Current->next->prev = Current->prev;
				Current = NULL;
				_Size--;
				return true;
			}
			
		}
		return false;
	}

	T Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0 ? true : false;
	}

	void Clear()
	{
		while (Size()>0)
		{
			DeleteFirst();
		}
	}


	void ReVerse()
	{
		
		Node* Current = head;
		Node* Temp = NULL;
		Node* Temp2 = NULL;
		while (Current!=NULL)
		{
		
			Temp = Current->prev;
			Current->prev = Current->next;
			
			Current->next = Temp;
			Temp2 = Current;
			Current = Current->prev;
		}
		head =Temp2;
		

	}


	Node* GetNode(T index)
	{
		int  counter = 0;
		if (index < 0 || index > _Size)
		{
			return NULL;
		}

		Node* Current = head;
		while (Current !=NULL && counter != index)
		{
			Current = Current->next;
			counter++;
		}
		return Current;

		
	}



	bool UpdateNode(T index, T value)
	{
		Node* getNode = GetNode(index);
		if (getNode ==NULL)
		{
			return false;
		}
		getNode->_value = value;
		return true;
	}

	T GetItem(T index)
	{
		Node* N = GetNode(index);
		return N->_value;
	}
};

