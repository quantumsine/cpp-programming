#include <iostream>
#include <vector>
using namespace std;

double Notendurchschnitt(const vector<double>& noten) {
    double sum = 0;
    // range-based loop
    for (auto it : noten) {
        sum += it;
    }
    return sum / noten.size();
}

int main(int argc, char *argv[]) {
    int size;
    cout << "Wieviele Noten möchtest du eingeben? ";
    cin >> size;
    vector<double> noten(size);

    for (int i = 0; i < size; i++) {
        cin >> noten[i];
    }

    double avg = Notendurchschnitt(noten);
    cout << "Dein Durchschnitt ist: " << avg << endl;
}


