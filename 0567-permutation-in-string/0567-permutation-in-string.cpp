class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }
        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);
      
      //Build frequency arrays
        for (int i = 0; i < m; i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }
       //Check the first window
          if (s1Count == windowCount)
            return true;
        
        //Slide window

        for (int right = m; right < n; right++) {
            windowCount[s2[right] - 'a']++;    //Add new charector
            windowCount[s2[right - m] - 'a']--;//Remove the left charector

            if (s1Count == windowCount) 
                return true;
            
        }

        return false;
    }
};