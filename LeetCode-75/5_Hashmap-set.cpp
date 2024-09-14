// 1657. Determine if Two Strings Are Close

  bool closeStrings(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int>arr1(26,0);
        vector<int>arr2(26,0);

        if(m!=n){
            return false;
        }

        for(int i=0;i<n;i++){
            char ch1 = word1[i];
            char ch2 = word2[i];

            arr1[ch1-'a']++;
            arr2[ch2-'a']++;
            
        }

        for(int i=0;i<26;i++){
            if(arr1[i]!=0 && arr2[i]==0 || arr1[i]==0 && arr2[i]!=0){
                return false;
            }
        }

        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        for(int i=0;i<26;i++){
            if(arr1!=arr2){
                return false;
            }
        }
        return true;
    }

    