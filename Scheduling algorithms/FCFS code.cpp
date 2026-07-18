#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Process {
    string name;
    int at, bt, st, ct, tat, wt;
};

bool compareArrival(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter Name, Arrival Time, and Burst Time for P" << i + 1 << ": ";
        cin >> p[i].name >> p[i].at >> p[i].bt;
    }

    // Sort by Arrival Time
    sort(p.begin(), p.end(), compareArrival);

    int currentTime = 0;
    float sumWT = 0, sumTAT = 0;

    for (int i = 0; i < n; i++) {
        // Calculate Starting Time
        // If CPU is idle, start at Arrival Time; else start when previous ends
        p[i].st = max(currentTime, p[i].at);

        // Use your specific formulas
        p[i].wt = p[i].st - p[i].at;     // Waiting time = Start - Arrival
        p[i].tat = p[i].wt + p[i].bt;    // Turnaround = Wait + Burst

        // Completion time for the Gantt Chart
        p[i].ct = p[i].st + p[i].bt;

        currentTime = p[i].ct; // Update clock for next process
        sumWT += p[i].wt;
        sumTAT += p[i].tat;
    }

    // Output Table
    cout << "\n" << left << setw(10) << "Process" << setw(5) << "AT" << setw(5) << "BT"
         << setw(5) << "ST" << setw(5) << "WT" << setw(5) << "TAT" << setw(5) << "CT" << endl;
    cout << "------------------------------------------------------------\n";
    for (const auto& proc : p) {
        cout << left << setw(10) << proc.name << setw(5) << proc.at << setw(5) << proc.bt
             << setw(5) << proc.st << setw(5) << proc.wt << setw(5) << proc.tat << setw(5) << proc.ct << endl;
    }

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << sumWT / n;
    cout << "\nAverage Turnaround Time: " << sumTAT / n << endl;

    // --- UPDATED GANTT CHART WITH IDLE CASE ---
    cout << "\nGantt Chart:\n|";
    int timeRunner = 0;
    vector<int> timeLabels;
    timeLabels.push_back(0);

    for (int i = 0; i < n; i++) {
        // If there's a gap between current time and next arrival, it's IDLE
        if (timeRunner < p[i].at) {
            cout << " IDLE |";
            timeLabels.push_back(p[i].at);
            timeRunner = p[i].at;
        }
        cout << "  " << p[i].name << "  |";
        timeRunner = p[i].ct;
        timeLabels.push_back(timeRunner);
    }

    // Printing the time labels under the chart
    cout << "\n";
    for (int t : timeLabels) {
        cout << left << setw(7) << t;
    }
    cout << endl;

    return 0;
}
