#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findPairsWithSum(vector<int>& arr1, vector<int>& arr2, int K) {
    unordered_map<int, int> map;
    for (int num : arr1) {
        map[num]++;
    }

    cout << "Pasangan dengan jumlah " << K << ":\n";
    for (int num : arr2) {
        if (map[K - num] > 0) {
            cout << "(" << K - num << ", " << num << ")\n";
        }
    }
}

int main() {
    cout << "Nama: Abdil Rambhani" << endl;
    cout << "NIM : 231011401210" << endl;
    cout << "Mata Kuliah: Algoritma Pemrograman 2" << endl;
    cout << "Soal 2: Menemukan pasangan jumlah K" << endl;

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {5, 6, 7, 8, 9};
    int K = 10;

    findPairsWithSum(arr1, arr2, K);

    return 0;
}

