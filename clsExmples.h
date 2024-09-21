#pragma once

#include <iostream>
#include "clsDate.h"
#include <queue>;
#include <stack>
#include <string>
using namespace std;



class clsExmples
{

private:
    string _Prev;
    int    _NumberTicket;
    int    _TimeWaiting;
    int    _ServeClient;
    int    _ClientWaiting;

    class clsTicket
    {
    private:
        string _Prev;
        int    _NumberTicket;
        int    _TimeWaiting;
        int    _ServeClient;
        int    _ClientWaiting;

    public:
        clsTicket(string prev,int NumberTicket,int WaitingTime,int ClientWaiting)
        {
            _Prev = prev;
            _NumberTicket = NumberTicket;
            _TimeWaiting = WaitingTime;
            _ClientWaiting = ClientWaiting;
        }

        string FullName()
        {
            return _Prev + to_string(_NumberTicket);
        }

        int Waiting()
        {
            return _TimeWaiting * _ClientWaiting;
        }

        void print()
        {
            cout << "\n\t\t____________________________________\n";
            cout << "\t\t\t prefix :" << FullName() << endl;
            cout << "\t\t\t NumberT:" << _NumberTicket << endl;
            cout << "\t\t\t WaitCli:" << _ClientWaiting << endl;
            cout << "\t\t\t Waiting In \n";
            cout << "\t\t\t\t " << Waiting() << "Minutes\n";
            cout << "\n\t\t____________________________________\n";

        }

    };

public:
    queue <clsTicket> QueueList;
    clsExmples(string prev,int Time)
    {
        _Prev = prev;
        _TimeWaiting = Time;
        _NumberTicket = 0;
    }

    void Issue()
    {
        _NumberTicket++;
        clsTicket Ticket(_Prev, _NumberTicket, _TimeWaiting, ClientWait());
        QueueList.push(Ticket);
    }


    int ClientWait()
    {
        return QueueList.size();
    }

    bool ServeClient()
    {
        if (QueueList.empty())
        {
            return false;
        }
        else
        {
            QueueList.pop();
            return true;
        }
    }

    int NumberServe()
    {
       return  _NumberTicket - QueueList.size();
    }

    void printInfo()
    {
        cout << "\n\t\t\t prev " << _Prev << endl;
        cout << "\t\t_____________________________________\n";
        cout << "\t\t\t NumberT : " << _NumberTicket << endl;
        cout << "\t\t\t WatingCl: " << ClientWait() << endl;
        cout << "\t\t\t ServeCli: " << NumberServe() << endl;
        cout << "\t\t_____________________________________\n";
    }

    void printFromRToL()
    {
        queue <clsTicket> Tem = QueueList;
        stack <clsTicket> TS;
        cout << endl;
        while (!Tem.empty())
        {
            cout << Tem.front().FullName() << "--->";
            Tem.pop();
        }
        cout  << endl;
    }

    void printFromLToR()
    {

        queue <clsTicket> Tem = QueueList;
        stack <clsTicket> TS;
        cout << endl;

        while (!Tem.empty())
        {
            clsTicket Ticket = Tem.front();
            TS.push(Ticket);
            Tem.pop();
        }
        while (!TS.empty())
        {
            cout << TS.top().FullName() << "<---";
            TS.pop();
        }
        cout << endl;
    }




    void printAllTicket()
    {
        queue <clsTicket> Tem = QueueList;

        if (Tem.empty())
        {
            return;
        }
        else
        {
            while (!Tem.empty())
            {
                clsTicket Ticket = Tem.front();
                Ticket.print();
                Tem.pop();
            }
        }
    }
};

