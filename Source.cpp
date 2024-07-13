#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class ModifyValue {
    T delta;
public:
    ModifyValue(T d) : delta(d) {}

    T operator()(T value) const {
        return value + delta;
    }
};

template<typename T>
class RemoveValue {
    T value;
public:
    RemoveValue(T v) : value(v) {}

    bool operator()(T elem) const {
        return elem == value;
    }
};

int main() {
    vector<int> container = { 5, 3, 8, 1, 9, 7, 2, 5 };
    cout << "Original: ";
    for (auto val : container) cout << val << " ";
    cout << endl;

    auto minValue = min_element(container.begin(), container.end());
    cout << "Minimum value: " << *minValue << endl;

    auto maxValue = max_element(container.begin(), container.end());
    cout << "Maximum value: " << *maxValue << endl;

    vector<int> sortedDesc = container;
    sort(sortedDesc.begin(), sortedDesc.end(), greater<int>());
    cout << "Sorted in descending order: ";
    for (auto val : sortedDesc) cout << val << " ";
    cout << endl;

    vector<int> sortedAsc = container; 
    sort(sortedAsc.begin(), sortedAsc.end());
    cout << "Sorted in ascending order: ";
    for (auto val : sortedAsc) cout << val << " ";
    cout << endl;

    vector<int> increasedValues = container;
    transform(increasedValues.begin(), increasedValues.end(), increasedValues.begin(), ModifyValue<int>(3));
    cout << "Values increased by 3: ";
    for (auto val : increasedValues) cout << val << " ";
    cout << endl;

    vector<int> decreasedValues = container;
    transform(decreasedValues.begin(), decreasedValues.end(), decreasedValues.begin(), [](int value) { return value - 2; });
    cout << "Values decreased by 2: ";
    for (auto val : decreasedValues) cout << val << " ";
    cout << endl;

    vector<int> removedValues = container;
    removedValues.erase(remove_if(removedValues.begin(), removedValues.end(), RemoveValue<int>(5)), removedValues.end());
    cout << "After removing values equal to 5: ";
    for (auto val : removedValues) cout << val << " ";
    cout << endl;

    return 0;
}

