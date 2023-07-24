class RandomizedSet {
private:
    map<int, int> m; // A map to store the value-to-index mapping
    vector<int> v;   // A vector to store the elements of the set

public:
    RandomizedSet() {
        // Constructor for the RandomizedSet class
    }

    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false; // If 'val' already exists in the set, return false (no duplicates allowed)
        } else {
            m[val] = v.size(); // Insert 'val' into the map with its index in the vector 'v'
            v.push_back(val);  // Insert 'val' into the vector 'v'
            return true;       // Return true to indicate successful insertion
        }
    }

    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false; // If 'val' doesn't exist in the set, return false (cannot remove a non-existent element)
        } else {
            int last = v.back();       // Get the last element of the vector 'v'
            v[m[val]] = v.back();      // Replace the element at the index of 'val' with the last element
            v.pop_back();              // Remove the last element from the vector 'v'
            m[last] = m[val];          // Update the index of the last element in the map
            m.erase(val);              // Erase 'val' from the map
            return true;               // Return true to indicate successful removal
        }
    }

    int getRandom() {
        return v[rand() % v.size()]; // Return a random element from the set using the vector 'v'
    }
};
