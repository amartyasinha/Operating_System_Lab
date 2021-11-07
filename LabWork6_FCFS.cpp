//
// Created by amartya on 16/10/21.
//

#include <iostream>
using namespace std;

class Processes {
public:
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;

    Processes() {
        arrivalTime = 0;
        burstTime = 0;
        waitingTime = 0;
        turnAroundTime = 0;
    }
};

int main() {
    cout << "It is a Program to implement FCFS scheduling algorithm\n";
    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    cout << "\nEnter the Number of Processes: ";
    int n;
    cin >> n;
    cout << endl;

    Processes tmp;
    Processes *p = new Processes[n];

    for(int i = 0; i<n; i++) {
        cout<<"Enter the Arrival Time for Process ["<< i+1 <<"]: ";
        cin>>p[i].arrivalTime;
        cout<<"Enter the Burst Time for Process ["<< i+1 <<"]: ";
        cin>>p[i].burstTime;
        cout << endl;
    }

    for(int i=0; i < n; i++) {
        for(int j=i+1; j < n; j++)
            if(p[i].arrivalTime <= p[j].arrivalTime) {
                p[j].waitingTime= p[i].arrivalTime + p[i].waitingTime + p[i].burstTime - p[j].arrivalTime;
                if(p[j].waitingTime < 0)
                    p[j].waitingTime=0;
            }
            else {
                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        p[i].turnAroundTime = p[i].burstTime + p[i].waitingTime;
    }
    cout << "---------------------------------------------------\n";
    for(int i=0; i < n; i++) {
        totalWaitingTime += float(p[i].waitingTime);
        totalTurnAroundTime += float(p[i].turnAroundTime);
        cout << "The Waiting Time for Process [" << i+1 << "]: " << p[i].waitingTime;
        cout << "\nThe Turnaround Time for Process [" << i+1 << "]: " << p[i].turnAroundTime << endl << endl;
    }
    cout << "---------------------------------------------------\n";
    cout << "Average Waiting Time: " << totalWaitingTime / (float)n;
    cout << "\nAverage Turnaround Time: " << totalTurnAroundTime / (float)n << endl;
    return 0;
}