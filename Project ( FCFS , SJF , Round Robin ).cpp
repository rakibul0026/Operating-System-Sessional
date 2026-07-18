#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Process {
    int pid, arrival, burst;
    int remaining;
    int completion, turnaround, waiting;
    bool done;
};

// ================= FCFS =================
void FCFS(vector<Process> p, int n) {
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    cout << "\nGantt Chart:\n|";

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival) {
            cout << " IDLE |";
            current_time = p[i].arrival;
        }

        cout << " P" << p[i].pid << " |";

        p[i].completion = current_time + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        current_time = p[i].completion;

        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
    }

    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : p) {
        cout << "P" << pr.pid << "\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.completion << "\t" << pr.turnaround << "\t" << pr.waiting << endl;
    }

    cout << "\nAverage WT: " << total_wt / n;
    cout << "\nAverage TAT: " << total_tat / n << endl;
}

// ================= SJF =================
void SJF(vector<Process> p, int n) {
    int current_time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    cout << "\nGantt Chart:\n|";

    while (completed < n) {
        int idx = -1, min_burst = 1e9;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].arrival <= current_time) {
                if (p[i].burst < min_burst) {
                    min_burst = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            cout << " IDLE |";
            current_time++;
        } else {
            cout << " P" << p[idx].pid << " |";

            current_time += p[idx].burst;
            p[idx].completion = current_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            total_wt += p[idx].waiting;
            total_tat += p[idx].turnaround;

            p[idx].done = true;
            completed++;
        }
    }

    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : p) {
        cout << "P" << pr.pid << "\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.completion << "\t" << pr.turnaround << "\t" << pr.waiting << endl;
    }

    cout << "\nAverage WT: " << total_wt / n;
    cout << "\nAverage TAT: " << total_tat / n << endl;
}

// ================= Round Robin =================
void RoundRobin(vector<Process> p, int n) {
    int tq;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    vector<bool> inQueue(n, false);

    int current_time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    cout << "\nGantt Chart:\n|";

    while (completed < n) {

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !inQueue[i] && p[i].remaining > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (q.empty()) {
            cout << " IDLE |";
            current_time++;
            continue;
        }

        int i = q.front();
        q.pop();

        cout << " P" << p[i].pid << " |";

        if (p[i].remaining > tq) {
            current_time += tq;
            p[i].remaining -= tq;
        } else {
            current_time += p[i].remaining;
            p[i].remaining = 0;

            p[i].completion = current_time;
            p[i].turnaround = p[i].completion - p[i].arrival;
            p[i].waiting = p[i].turnaround - p[i].burst;

            total_wt += p[i].waiting;
            total_tat += p[i].turnaround;

            completed++;
        }

        for (int j = 0; j < n; j++) {
            if (p[j].arrival <= current_time && !inQueue[j] && p[j].remaining > 0) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if (p[i].remaining > 0) {
            q.push(i);
        }
    }

    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : p) {
        cout << "P" << pr.pid << "\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.completion << "\t" << pr.turnaround << "\t" << pr.waiting << endl;
    }

    cout << "\nAverage WT: " << total_wt / n;
    cout << "\nAverage TAT: " << total_tat / n << endl;
}

// ================= MAIN =================
int main() {
    int n, choice;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time and Burst Time for P" << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].done = false;
    }

    cout << "\n1. FCFS\n2. SJF\n3. Round Robin\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: FCFS(p, n); break;
        case 2: SJF(p, n); break;
        case 3: RoundRobin(p, n); break;
        default: cout << "Invalid choice!";
    }

    return 0;
}
