#include <iostream>
#include <vector>
using namespace std;

// Fungsi Quick Sort dalam gaya fungsional
vector<int> quickSortFunctional(vector<int> arr) {
    if (arr.size() <= 1) 
        return arr; // Basis rekursi: jika array hanya memiliki 0 atau 1 elemen, sudah terurut

    int pivot = arr[0]; // Pilih elemen pertama sebagai pivot
    vector<int> less, greater;

    // Pisahkan elemen yang lebih kecil dan lebih besar dari pivot
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] <= pivot)
            less.push_back(arr[i]);
        else
            greater.push_back(arr[i]);
    }

    // Rekursi untuk bagian yang lebih kecil dan lebih besar
    vector<int> sorted = quickSortFunctional(less);
    sorted.push_back(pivot);
    vector<int> sortedGreater = quickSortFunctional(greater);
    sorted.insert(sorted.end(), sortedGreater.begin(), sortedGreater.end());

    return sorted;
}

int main() {
    // Informasi soal
    cout << "Nama: Abdil Rambhani" << endl;
    cout << "NIM : 231011401210" << endl;
    cout << "Mata Kuliah: Algoritma Pemrograman 2" << endl;
    cout << "Soal 3: Quick Sort Fungsional" << endl;

    // Data yang akan diurutkan
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};

    // Panggil fungsi Quick Sort
    vector<int> sortedArr = quickSortFunctional(arr);

    // Cetak hasil pengurutan
    cout << "Array setelah diurutkan: ";
    for (int num : sortedArr)
        cout << num << " ";
    cout << endl;

    return 0;
}

