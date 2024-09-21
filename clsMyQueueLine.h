
#include <iostream>
#include "clsDate.h"
#include "queue"
#include "stack"

using namespace std;



class clsMyQueueLine
{

private:
	string _pref1 ="";
	int  _NumberTicket;
	int _ServeClient;
	int _TimeWaiting;
	int _WaitingClient;

	class clsTicket
	{

	private:
		string _pref2;
		int  _TotalTicket;
		int _ClientServe;
		int _TimeWait;
		int _ClientsWaiting;


	public:

		clsTicket(string pref2,int TotaleTicket, int TimeWait, int ClientWating)
		{
			this->_pref2 = pref2;
			_TotalTicket = TotaleTicket;
			_TimeWait = TimeWait;
			_ClientsWaiting = ClientWating;
		}


		string FullName()
		{
			return _pref2 + to_string(_TotalTicket);
		}

		int TimeWait()
		{
			return _TimeWait * _ClientsWaiting;
		}


		void print()
		{
			cout << "\n \t\t\t\t Ticket \n";
			cout << "\t\t______________________________________\n";
			cout << "\t\t prefix : " << FullName() << endl;
			cout << "\t\t Date   : " << clsDate::GetSystemDateTimeString()<<endl;
			cout << "\t\t WaitingClient : " << _ClientsWaiting << endl;
			cout << "\t\t Serve Client In \n";
			cout << "\t\t\t" << TimeWait() << " Minutes" << endl;
			cout << "\t\t______________________________________\n\n";
		}

	};


public:
	queue <clsTicket> QueueLine;

	clsMyQueueLine(string pref1, int time)
	{
		this->_pref1 = pref1;
		_TimeWaiting = time;
		_NumberTicket = 0;
	}
	

	int WaitingClient()
	{
		return QueueLine.size();
	}

	
	void IssueTicket()
	{
		_NumberTicket++;
		clsTicket Ticket(_pref1, _NumberTicket, _TimeWaiting, WaitingClient());
		QueueLine.push(Ticket);
	}

	bool ServeClient()
	{
		if (!QueueLine.empty())
		{
			QueueLine.pop();
			return true;
		}
		return false;
	}

	int ServeNumber()
	{
		return _NumberTicket - QueueLine.size();
	}

	void printInfo()
	{
		cout << "\n \t\t\t_________________________________________\n";
		
		cout << "\t\t\t Number Ticket = " << _NumberTicket << endl;
		cout << "\t\t\t Serve  Client = " << ServeNumber() << endl;
		cout << "\t\t\t Wating Client = " << WaitingClient() << endl;
	}


	void printAll()
	{
		queue <clsTicket> Tem = QueueLine;

		while (!Tem.empty())
		{
			
			clsTicket Ticket =  Tem.front();
			
			Ticket.print();
			Tem.pop();

		}
	}
};

