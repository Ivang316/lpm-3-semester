#pragma once
#include <string>
#include <vector>

using namespace std;

struct Date {
    string day;
    string month;
    string year;
};

struct DataObject {
    string directoryName;
    string fileName;
    string extension;
    Date createdAt;
    int size = 0;
};


class HashNode {
public:
    string key;
    DataObject value;
    bool isEmpty;

    HashNode(const string& key, const DataObject& value) {
      this->key = key;
      this->value = value;
      isEmpty = false;
    }

    HashNode() {
      key = "";
      value = DataObject();
      isEmpty = true;
    }
};


class HashTable {
    const short prime = 13;
    size_t size;
    size_t capacity;
    vector<HashNode> cells;

    static int sumCharCodes(const string& str) {
      int sum = 0;
      for(const char& c : str) {
        sum += int(c);
      }
      return sum;
    }

    size_t hashFunc1(const string& key) const {
      const int charsSum = sumCharCodes(key);
      return charsSum % capacity;
    }

    size_t hashFunc2(const string& key) const {
      const int charsSum = sumCharCodes(key);
      return prime - (charsSum % prime);
    }

public:
    explicit HashTable(size_t maxSize) {
      capacity = maxSize;
      size = 0;
      cells.resize(maxSize);
    }

    bool insert(const string& key, const DataObject& value) {
      if (size == capacity) return false;

      size_t idx = hashFunc1(key);

      if (cells[idx].isEmpty) {
        cells[idx] = *new HashNode(key, value);
      } else {
        size_t step = hashFunc2(key), newIndex;

        for (int i = 0;; ++i) {
          newIndex = (idx + i * step) % capacity;
          if (cells[newIndex].isEmpty) break;
        }

        cells[newIndex] = *new HashNode(key, value);
      }
      size++;
      return true;
    }

    DataObject& find(const string& key) {
      size_t initialIndex = hashFunc1(key), step = hashFunc2(key);
      size_t idx = 0;

      for (size_t i = 0; idx != initialIndex; ++i) {
        idx = (idx + i * step) % capacity;
        if (cells[idx].key == key) return cells[idx].value;
      }

      throw runtime_error("Element is not in the hash table");
    }
};
