// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         map<int, int> numToRank;
//         vector<int> sortedArr(arr);
//         sort(sortedArr.begin(), sortedArr.end());
//         int rank = 1;
//         for (int i = 0; i < sortedArr.size(); i++) {
//             if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
//                 rank++;
//             }
//             numToRank[sortedArr[i]] = rank;
//         }
//         for (int i = 0; i < arr.size(); i++) {
//             arr[i] = numToRank[arr[i]];
//         }
//         return arr;
//     }
//};

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> numToIndices;

        for (int i = 0; i < arr.size(); i++) {
            numToIndices[arr[i]].push_back(i);
        }

        int rank = 1;
        for (auto& pair : numToIndices) {
            for (int index : pair.second) {
                arr[index] = rank;
            }
            rank++;
        }
        return arr;
    }
};