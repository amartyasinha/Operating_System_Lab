//
// Created by amartya on 23/10/21.
//

#include<iostream>

using namespace std;

class RoundRobin {
    int quantum;
    int n; //Number of process
    int burstTime[20];// burstTime time of processes
    int waitingTime[20];//Waiting time
    int remBurst[20];// keeps track of remaining burstTime time of the process
public:
    void input(); // Takes no. of processes and their burstTime time
    void wait();   // Calculates waitingTime time of the processes
    void avgWait(); // Calculate average waitingTime for the process
    void turnAround();
    void avgTurnAround();
};

void RoundRobin::input() {
    cout << "Enter the Number of Processes: " << endl;
    cin >> n;
    burstTime[n];
    waitingTime[n];
    remBurst[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process [" << i + 1 << "]: ";
        cin >> burstTime[i];
    }
    cout << "\n";
    cout << "Enter the Quantum for the Process: " << endl;
    cin >> quantum;

    // Now keeping a copy of burstTime time
    for (int i = 0; i < n; i++) {
        remBurst[i] = burstTime[i];
    }

}

void RoundRobin::wait() {
    int ct = 0; // cpu time

    while (true) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (remBurst[i] > 0) {
                flag = true;
                if (remBurst[i] > quantum) {
                    ct += quantum;
                    remBurst[i] = remBurst[i] - quantum;

                } else {
                    ct += remBurst[i];
                    remBurst[i] = 0;
                    waitingTime[i] = ct - burstTime[i];
                }
            }
        }
        if (!flag) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Waiting time  of Process [" << i + 1 << "]: " << waitingTime[i] << endl;
    }
}

void RoundRobin::avgWait() {
    float totalWaitingTime = 0.0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += (float)waitingTime[i];
    }
    cout << "Average Waiting Time: " << totalWaitingTime / (float)n << endl;
}

void RoundRobin::turnAround() {
    for (int i = 0; i < n; i++) {
        float turnAroundTime = 0.0;
        turnAroundTime = (float)waitingTime[i] + (float)burstTime[i];
        cout << "TurnAround time for Process [" << i + 1 << "]: " << turnAroundTime << endl;
    }
}

void RoundRobin::avgTurnAround() {
    float totalTurnAroundTime = 0.0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += (float)waitingTime[i] + (float)burstTime[i];
    }
    cout << "Average Turn Around Time: " << totalTurnAroundTime / (float)n << endl;
}

int main() {
    RoundRobin r;
    r.input();
    r.wait();
    r.avgWait();
    r.turnAround();
    r.avgTurnAround();
    return 0;
}