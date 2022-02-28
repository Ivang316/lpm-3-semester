#include <iostream>
#include "HashMap.h"

using namespace std;

DataObject initialData[] = {
    {
        .directoryName = "First Directory",
        .fileName = "First File",
        .extension = ".png",
        .createdAt = {
            .day = "03",
            .month = "08",
            .year = "1998",
        },
        .size = 4096,
    },
    {
        .directoryName = "First Directory",
        .fileName = "Second File",
        .extension = ".docx",
        .createdAt = {
            .day = "01",
            .month = "01",
            .year = "2005",
        },
        .size = 2048,
    },
    {
        .directoryName = "Second Directory",
        .fileName = "Third File",
        .extension = ".mp4",
        .createdAt = {
            .day = "29",
            .month = "05",
            .year = "2022",
        },
        .size = 79872,
    },
};


string objToKey(const DataObject& obj) {
  return obj.directoryName + obj.fileName;
}


int main() {
  HashTable table(10);

  for (int i = 0; i < 3; ++i) {
    for (const DataObject& obj : initialData) {
      table.insert(objToKey(obj), obj);
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (const DataObject& obj : initialData) {
      try {
        cout << table.find(objToKey(obj)).fileName << endl;
      } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
      }
    }
  }

  return 0;
}

