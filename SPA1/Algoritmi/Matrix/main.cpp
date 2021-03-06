#include <iostream>
#include <vector>
using namespace std;

int main() {

    cout << "Unesite red kvadratnih matrica A i B: ";
    int n;
    cin >> n;
    vector<vector <int>> A(n, vector<int>(n));
    vector<vector <int>> B(n, vector<int>(n));
    vector<vector <int>> C(n, vector<int>(n));
    cout << "Unesite elemente matrice A: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }
    cout << "Unesite elemente matrice B: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> B[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}