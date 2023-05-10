class FrequencyTracker {
public:
    int cnt[100001] = {}, freq[100001] = {};
    void add(int number) {
        --freq[cnt[number]];
        ++freq[++cnt[number]];
    }    
    void deleteOne(int number) {
        if (cnt[number]) {
            --freq[cnt[number]];
            ++freq[--cnt[number]];
        }
    }
    bool hasFrequency(int frequency) {
        return freq[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */