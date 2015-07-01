class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        set<int> s;
        for (int i = 0; i < length; i++) {
            if (s.find(numbers[i]) == s.end()) {
                s.insert(numbers[i]);
            } else {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};
