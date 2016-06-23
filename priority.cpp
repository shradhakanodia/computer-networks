
//priority
#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

int main()
{
    int ch,nh,nl,pktno,pri;
    queue<int> hpq,lpq;
    cout<<"Enter the size of higher priority queue";
    cin>>nh;
    cout<<"Enter the size of lower priority queue";
    cin>>nl;
    while(1)
    {
        cout<<"\nEnter 1 to add message 2 to delete message\n";
        cin>>ch;
        switch(ch)
        {
         case 1:cout<<"Enter the packet no and priority";
            cin>>pktno>>pri;
            if(pri==0)
                if(hpq.size()<nh) hpq.push(pktno);
                else  cout<<"Queue full";
            else if(pri==1)
                if(lpq.size()<nl) lpq.push(pktno);
                else  cout<<"Queue full";
                break;
        case 2:
            if(!hpq.empty()) cout<<"the packet is sent from higher priority queue of packet no "<<hpq.front(),hpq.pop();
            else if(!lpq.empty()) cout<<"the packet is sent from lower priority queue of packet no "<<lpq.front(),lpq.pop();
            else cout<<"Queue is empty";
            break;
        case 3: exit(0);
        }
    }
}
