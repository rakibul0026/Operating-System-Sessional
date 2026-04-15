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

    cout << "\nSelect Scheduling Algorithm:\n";
    cout << "1. FCFS\n2. SJF (Non-Preemptive)\n3. Round Robin\n";
    cout << "Enter choice: ";
    cin >> choice;

    int current_time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    cout << "\nGantt Chart:\n|";

    switch (choice) {

    // ================= FCFS =================
    case 1: {
        sort(p.begin(), p.end(), [](Process a, Process b) {
            return a.arrival < b.arrival;
        });

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
        break;
    }

    // ================= SJF =================
    case 2: {
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
        break;
    }

    // ================= Round Robin =================
    case 3: {
        int tq;
        cout << "Enter Time Quantum: ";
        cin >> tq;

        queue<int> q;
        vector<bool> inQueue(n, false);

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
        break;
    }

    default:
        cout << "Invalid choice!";
        return 0;
    }

    // ================= Output =================
    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].arrival << "\t"
             << p[i].burst << "\t"
             << p[i].completion << "\t"
             << p[i].turnaround << "\t"
             << p[i].waiting << endl;
    }

    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n;

    return 0;
}