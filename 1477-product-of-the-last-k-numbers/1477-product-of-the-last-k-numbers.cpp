class ProductOfNumbers {
public:
    vector<int> pref;

    ProductOfNumbers() {
        pref.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            pref.clear();
            pref.push_back(1);
        }
        else {
            pref.push_back(pref.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= pref.size()) return 0;

        return pref.back() / pref[pref.size() - 1 - k];
    }
};