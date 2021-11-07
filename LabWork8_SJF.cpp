//
// Created by amartya on 05/11/21.
//

#include <iostream>
using namespace std;

class SJF {
public:
    int processID;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

int main() {
    cout << "It is a Program to implement SJF scheduling algorithm \n";
    float totalWaitingTime = 0.0, totalTurnAroundTime = 0.0;

    //user input
    cout << "Enter the Number of Processes: ";
    int n;
    cin >> n;

    SJF *p = new SJF[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter the Burst Time for Process: [" << i + 1 << "]: ";
        cin >> p[i].burstTime;
        p[i].processID = i + 1;
    }

    //sorting processes
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burstTime > p[j + 1].burstTime)
                swap(p[j], p[j + 1]);
        }
    }

    cout << "Order in which process gets executed\n";
    for (int i = 0; i < n; i++)
        cout << p[i].processID << " ";

    //waiting time, turnaround time calculation
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].burstTime + p[i - 1].waitingTime;
        p[i].turnAroundTime = p[i].burstTime + p[i].waitingTime;
    }

    //printing waiting time, turnaround time for these processes
    cout << "\n-----------------------------------------------------\n";
    cout << "Process | Burst Time | Waiting Time | TurnAround Time\n";
    cout << "-----------------------------------------------------\n";
    for(int i = 0; i < n; i++) {
        totalWaitingTime += (float)p[i].waitingTime;
        totalTurnAroundTime += (float)p[i].turnAroundTime;
        cout << " " << p[i].processID<< "\t\t\t" << p[i].burstTime << "\t\t\t" << p[i].waitingTime << "\t\t\t\t" << p[i].turnAroundTime << endl;
    }
    cout << "-----------------------------------------------------\n";
    cout << "Average Waiting Time: " << totalWaitingTime / (float)n;
    cout << "\nAverage Turnaround Time: " << totalTurnAroundTime / (float)n << endl;
    return 0;
}