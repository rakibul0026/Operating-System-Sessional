#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id, arrival, burst, priority;
    int remaining, completion, waiting, turnaround;
};

// SJF PREEMPTIVE
void sjfPreemptive(vector<Process> p) {
    int n = p.size();
    int time = 0, completed = 0;

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    while (completed != n) {
        int idx = -1;
        int min_bt = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0 && p[i].remaining < min_bt) {
                min_bt = p[i].remaining;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining--;
            time++;

            if (p[idx].remaining == 0) {
                completed++;
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
            }
        } else {
            time++;
        }
    }

    cout << "\nSJF Preemptive:\n";
    for (auto x : p) {
        cout << "P" << x.id << " WT=" << x.waiting << " TAT=" << x.turnaround << endl;
    }
}

// PRIORITY NON-PREEMPTIVE
void priorityNonPreemptive(vector<Process> p) {
    int n = p.size();
    int time = 0, completed = 0;
    vector<bool> done(n, false);

    while (completed != n) {
        int idx = -1;
        int highest = 1e9;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].priority < highest) {
                highest = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            time += p[idx].burst;
            p[idx].completion = time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            done[idx] = true;
            completed++;
        } else {
            time++;
        }
    }

    cout << "\nPriority Non-Preemptive:\n";
    for (auto x : p) {
        cout << "P" << x.id << " WT=" << x.waiting << " TAT=" << x.turnaround << endl;
    }
}

//  PRIORITY PREEMPTIVE 
void priorityPreemptive(vector<Process> p) {
    int n = p.size();
    int time = 0, completed = 0;

    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst;

    while (completed != n) {
        int idx = -1;
        int highest = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining > 0 && p[i].priority < highest) {
                highest = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remaining--;
            time++;

            if (p[idx].remaining == 0) {
                completed++;
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
            }
        } else {
            time++;
        }
    }

    cout << "\nPriority Preemptive:\n";
    for (auto x : p) {
        cout << "P" << x.id << " WT=" << x.waiting << " TAT=" << x.turnaround << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " Arrival Burst Priority: ";
        cin >> p[i].arrival >> p[i].burst >> p[i].priority;
        p[i].id = i + 1;
    }

    sjfPreemptive(p);
    priorityNonPreemptive(p);
    priorityPreemptive(p);

    return 0;
}
