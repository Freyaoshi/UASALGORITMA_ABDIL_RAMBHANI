#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node struktur untuk pohon Huffman
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator untuk min-heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Traversal pohon untuk menghasilkan kode Huffman
void buildHuffmanCode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;

    buildHuffmanCode(root->left, str + "0", huffmanCode);
    buildHuffmanCode(root->right, str + "1", huffmanCode);
}

// Dekode string biner menggunakan pohon Huffman
string decodeHuffman(Node* root, string encodedStr) {
    string decodedStr = "";
    Node* current = root;

    for (char bit : encodedStr) {
        current = (bit == '0') ? current->left : current->right;

        if (!current->left && !current->right) {
            decodedStr += current->ch;
            current = root;
        }
    }

    return decodedStr;
}

void huffmanEncoding(string text) {
    // Hitung frekuensi setiap karakter
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    // Bangun min-heap
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Bangun pohon Huffman
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum));
        pq.top()->left = left;
        pq.top()->right = right;
    }

    Node* root = pq.top();

    // Bangun kode Huffman
    unordered_map<char, string> huffmanCode;
    buildHuffmanCode(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << endl;

    // Encoding teks
    string encodedStr = "";
    for (char ch : text)
        encodedStr += huffmanCode[ch];

    cout << "\nEncoded String: " << encodedStr << endl;

    // Decoding teks
    string decodedStr = decodeHuffman(root, encodedStr);
    cout << "Decoded String: " << decodedStr << endl;
}

int main() {
    cout << "Nama: Abdil Rambhani" << endl;
    cout << "NIM : 231011401210" << endl;
    cout << "Mata Kuliah: Algoritma Pemrograman 2" << endl;
    cout << "Soal 1: Huffman Encoding" << endl;
    
    string text;
    cout << "Masukkan string: ";
    getline(cin, text);

    huffmanEncoding(text);

    return 0;
}

