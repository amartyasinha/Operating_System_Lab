//
// Created by amartya on 26/10/21.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 10;

class Process {
public:
    int processID;
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
};

int main() {
    cout << "It is a program to perform Preemptive Priority Scheduling\n";
    float totalWaitingTime = 0.0, totalTurnAroundTime = 0.0, totalResponseTime = 0.0, totalIdleTime = 0.0;
    //input
    cout << "Enter the Number of Processes: ";
    int n;
    cin >> n;
    auto *p = new Process[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the Arrival Time for Process [" << i + 1 << "]: ";
        cin >> p[i].arrivalTime;
        cout << "\nEnter the Burst Time for Process [" << i + 1 << "]: ";
        cin >> p[i].burstTime;
        cout << "Enter the Priority of Process [" << i + 1 << "]: ";
        cin >> p[i].priority;
        p[i].processID = i + 1;
    }
    int currentTime = 0;
    int completed = 0;
    int prev = 0;
    int remainingBurstTime[SIZE]{0};
    // making a copy of burst time
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = p[i].burstTime;
    }
    int isCompleted[SIZE]{0};
    cout << setprecision(2) << fixed;
    int idx, mx;
    while (completed != n) {
        idx = -1;
        mx = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && isCompleted[i] == 0) {
                if (p[i].priority > mx) {
                    mx = p[i].priority;
                    idx = i;
                } else if (p[i].priority == mx) {
                    if (p[i].arrivalTime < p[idx].arrivalTime) {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1) {
            if (remainingBurstTime[idx] == p[idx].burstTime) {
                p[idx].startTime = currentTime;
                totalIdleTime += (float) p[idx].startTime - (float) prev;
            }
            remainingBurstTime[idx] -= 1;
            currentTime++;
            prev = currentTime;
            if (remainingBurstTime[idx] == 0) {
                p[idx].completionTime = currentTime;
                p[idx].turnAroundTime = p[idx].completionTime - p[idx].arrivalTime;
                p[idx].waitingTime = p[idx].turnAroundTime - p[idx].burstTime;
                p[idx].responseTime = p[idx].startTime - p[idx].arrivalTime;
                totalTurnAroundTime += (float) p[idx].turnAroundTime;
                totalWaitingTime += (float) p[idx].waitingTime;
                totalResponseTime += (float) p[idx].responseTime;
                isCompleted[idx] = 1;
                completed++;
            }
        } else {
            currentTime++;
        }
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Process | Arrival Time | Burst Time | Priority | Start Time | Completion Time | TurnAround Time | Waiting Time | Response Time\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].processID << "\t\t\t" << p[i].arrivalTime << "\t\t\t\t" << p[i].burstTime << "\t\t\t"
             << p[i].priority << "\t\t\t" << p[i].startTime << "\t\t\t\t" << p[i].completionTime << "\t\t\t\t"
             << p[i].turnAroundTime << "\t\t\t\t\t" << p[i].waitingTime << "\t\t\t\t" << p[i].responseTime << "\n";
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Average Turn Around Time: " << totalTurnAroundTime / (float) n << "\n";
    cout << "Average Waiting Time: " << totalWaitingTime / (float) n << "\n";
    cout << "Average Response Time: " << totalResponseTime / (float) n << "\n";
    return 0;
}