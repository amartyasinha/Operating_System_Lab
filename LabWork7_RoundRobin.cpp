//
// Created by amartya on 23/10/21.
//

#include<iostream>
using namespace std;

class RoundRobin {
public:
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    int remainingBurstTime;
};

int main() {
    cout << "It is a program to implement Round Robin scheduling algorithm";
    float totalWaitingTime = 0.0, totalTurnAroundTime = 0.0;
    int cpuTime = 0;

    //user input
    cout << "Enter the Number of Processes: ";
    int n;
    cin >> n;

    auto *r = new RoundRobin[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process [" << i + 1 << "]: ";
        cin >> r[i].burstTime;
    }
    cout << "\nEnter the Quantum for the Process: ";
    int quantum;
    cin >> quantum;

    //creating remaining burst time for the processes
    for (int i = 0; i < n; i++) {
        r[i].remainingBurstTime = r[i].burstTime;
    }

    //while loop to run until all processes are completed
    //for loop to go through all processes
    //checking whether the process has got remaining burst time or not using the if condition
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (r[i].remainingBurstTime > 0) {
                done = false;
                if (r[i].remainingBurstTime > quantum) {
                    cpuTime += quantum;
                    r[i].remainingBurstTime = r[i].remainingBurstTime - quantum;

                } else {
                    cpuTime += r[i].remainingBurstTime;
                    r[i].remainingBurstTime = 0;
                    r[i].waitingTime = cpuTime - r[i].burstTime;
                }
            }
            r[i].turnAroundTime = r[i].waitingTime + r[i].burstTime;
        }
        if (done) {
            break;
        }
    }

    //printing waiting time, turnaround time for these processes
    cout << "---------------------------------------------------";
    for (int i = 0; i < n; i++) {
        totalWaitingTime += (float)r[i].waitingTime;
        totalTurnAroundTime += (float)r[i].turnAroundTime;
        cout << "\nThe Waiting time for Process [" << i + 1 << "]: " << r[i].waitingTime;
        cout << "\nThe TurnAround time of Process [" << i + 1 << "]: " << r[i].turnAroundTime << endl;
    }
    cout << "---------------------------------------------------\n";
    cout << "Average Waiting Time: " << totalWaitingTime / (float)n;
    cout << "\nAverage Turn Around Time: " << totalTurnAroundTime / (float)n << endl;
    return 0;
}