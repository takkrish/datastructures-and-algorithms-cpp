// You are given a binary array possible of length n.

// Danielchandg and Bob are playing a game that consists of n levels. Some of the levels in the game are impossible to clear while others can always be cleared. In particular, if possible[i] == 0, then the ith level is impossible to clear for both the players. A player gains 1 point on clearing a level and loses 1 point if the player fails to clear it.

// At the start of the game, Danielchandg will play some levels in the given order starting from the 0th level, after which Bob will play for the rest of the levels.

// Danielchandg wants to know the minimum number of levels he should play to gain more points than Bob, if both players play optimally to maximize their points.

// Return the minimum number of levels danielchandg should play to gain more points. If this is not possible, return -1.

// Note that each player must play at least 1 level.

 

// Example 1:

// Input: possible = [1,0,1,0]

// Output: 1

// Explanation:

// Let's look at all the levels that Danielchandg can play up to:

// If Danielchandg plays only level 0 and Bob plays the rest of the levels, Danielchandg has 1 point, while Bob has -1 + 1 - 1 = -1 point.
// If Danielchandg plays till level 1 and Bob plays the rest of the levels, Danielchandg has 1 - 1 = 0 points, while Bob has 1 - 1 = 0 points.
// If Danielchandg plays till level 2 and Bob plays the rest of the levels, Danielchandg has 1 - 1 + 1 = 1 point, while Bob has -1 point.
// Danielchandg must play a minimum of 1 level to gain more points.

// Example 2:

// Input: possible = [1,1,1,1,1]

// Output: 3

// Explanation:

// Let's look at all the levels that Danielchandg can play up to:

// If Danielchandg plays only level 0 and Bob plays the rest of the levels, Danielchandg has 1 point, while Bob has 4 points.
// If Danielchandg plays till level 1 and Bob plays the rest of the levels, Danielchandg has 2 points, while Bob has 3 points.
// If Danielchandg plays till level 2 and Bob plays the rest of the levels, Danielchandg has 3 points, while Bob has 2 points.
// If Danielchandg plays till level 3 and Bob plays the rest of the levels, Danielchandg has 4 points, while Bob has 1 point.
// Danielchandg must play a minimum of 3 levels to gain more points.

// Example 3:

// Input: possible = [0,0]

// Output: -1

// Explanation:

// The only possible way is for both players to play 1 level each. Danielchandg plays level 0 and loses 1 point. Bob plays level 1 and loses 1 point. As both players have equal points, Danielchandg can't gain more points than Bob.

 

// Constraints:

// 2 <= n == possible.length <= 105
// possible[i] is either 0 or 1.

// Leetcode

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int total = 0;
        for(auto &x : possible) {
            if(x) total++;
            else total--;
        }
        int curr = 0;
        int n = possible.size();
        for(int i = 0;i<n;i++) {
            if(possible[i]) curr++;
            else curr--;
            if((total - curr) < curr && i!=n-1) return i+1;
        }
        return -1;
    }
};