//
// Created by amartya on 23/10/21.
//

#include<iostream>

using namespace std;

class RoundRobin {
    int quantum;
    int np; //Number of process
    int burst[20];// burst time of processes
    int waiting[20];//Waiting time
    int remBurst[20];// keeps track of remaining burst time of the process
public:
    void input(); // Takes no. of processes and their burst time
    void wait();   // Calculates waiting time of the processes
    void avgWait(); // Calculate average waiting for the process
    void turnAround();
    void avgTurnAround();
};

void RoundRobin::input() {
    cout << "Enter the number of processes. " << endl;
    cin >> np;
    burst[np];
    waiting[np];
    remBurst[np];
    cout << "Enter the burst time for the respective process. " << endl;
    for (int i = 0; i < np; i++) {
        cout << "For Process P" << i + 1 << " :-";
        cin >> burst[i];
    }
    cout << "\n";
    cout << "Enter the quantum for the process. " << endl;
    cin >> quantum;

    // Now keeping a copy of burst time
    for (int i = 0; i < np; i++) {
        remBurst[i] = burst[i];
    }

}

void RoundRobin::wait() {
    int ct = 0; // cpu time

    while (true) {
        bool flag = false;
        for (int i = 0; i < np; i++) {
            if (remBurst[i] > 0) {
                flag = true;
                if (remBurst[i] > quantum) {
                    ct += quantum;
                    remBurst[i] = remBurst[i] - quantum;

                } else {
                    ct += remBurst[i];
                    remBurst[i] = 0;
                    waiting[i] = ct - burst[i];
                }
            }
        }
        if (!flag) {
            break;
        }
    }
    cout << "Waiting time  of process. " << endl;
    for (int i = 0; i < np; i++) {
        cout << "P" << i + 1 << " = " << waiting[i] << endl;
    }
}

void RoundRobin::avgWait() {
    cout << "Average waiting time :- ";
    float awt = 0.0;
    for (int i = 0; i < np; i++) {
        awt += waiting[i];
    }
    cout << awt / np << endl;
}

void RoundRobin::turnAround() {
    cout << "TurnAround time :- " << endl;
    for (int i = 0; i < np; i++) {
        float tt = 0.0;
        tt = waiting[i] + burst[i];
        cout << "For Process p" << i + 1 << ":- " << tt << endl;
    }
}

void RoundRobin::avgTurnAround() {
    cout << "Average Turn Around time :- ";
    float att = 0.0;
    for (int i = 0; i < np; i++) {
        att += waiting[i] + burst[i];
    }
    cout << att / np << endl;
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