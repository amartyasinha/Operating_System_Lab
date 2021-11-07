//
// Created by amartya on 27/10/21.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Process {
    int processID;
    int burstTime;
    int priority;
    int waitingTime;
    int turnAroundTime;
};

bool comparison(Process a, Process b) {
    return (a.priority > b.priority);
}

int main() {
    float totalWaitingTime = 0.0, totalTurnAroundTime = 0.0;
    cout << "Enter the Number of Processes: ";
    int n;
    cin >> n;
    auto *p = new Process[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter the Burst Time for Process [" << i + 1 << "]: ";
        cin >> p[i].burstTime;
        cout << "Enter the Priority of Process [" << i + 1 << "]: ";
        cin >> p[i].priority;
        p[i].processID = i + 1;
    }

    sort(p, p+n, comparison);

    cout << "\nOrder in which processes gets executed \n";
    for (int i = 0; i < n; i++) {
        cout << p[i].processID << " ";
    }
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i-1].burstTime + p[i-1].waitingTime;
    }
    for (int i = 0; i < n; i++) {
        p[i].turnAroundTime = p[i].burstTime + p[i].waitingTime;
    }

    //printing waiting time, turnaround time for these processes
    cout << "\n-----------------------------------------------------\n";
    cout << "Process | Burst Time | Waiting Time | TurnAround Time\n";
    cout << "-----------------------------------------------------\n";
    for(int i = 0; i < n; i++) {
        totalWaitingTime += (float)p[i].waitingTime;
        totalTurnAroundTime += (float)p[i].turnAroundTime;
        cout << " " << p[i].processID << "\t\t\t" << p[i].burstTime << "\t\t\t" << p[i].waitingTime << "\t\t\t\t" << p[i].turnAroundTime << endl;
    }
    cout << "-----------------------------------------------------\n";
    cout << "Average Waiting Time: " << totalWaitingTime / (float)n;
    cout << "\nAverage Turnaround Time: " << totalTurnAroundTime / (float)n << endl;
    return 0;
}