#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


struct DataStruct {
    int key1;
    int key2;
    std::string key3;
};


std::istream& operator>>(std::istream& is, DataStruct& ds) {
    is >> ds.key1 >> ds.key2 >> ds.key3;
    return is;
}


std::ostream& operator<<(std::ostream& os, const DataStruct& ds) {
    os << ds.key1 << " " << ds.key2 << " " << ds.key3;
    return os;
}

int main() {
    std::vector<DataStruct> data;

  
    DataStruct ds;
    while (std::cin >> ds) {
        data.push_back(ds);
    }


    std::sort(data.begin(), data.end(), [](const DataStruct& a, const DataStruct& b) {
        if (a.key1 != b.key1) return a.key1 < b.key1;
        if (a.key2 != b.key2) return a.key2 < b.key2;
        return a.key3.size() < b.key3.size();
    });

  
    std::copy(data.begin(), data.end(), std::ostream_iterator<DataStruct>(std::cout, "\n"));

    return 0;
}
