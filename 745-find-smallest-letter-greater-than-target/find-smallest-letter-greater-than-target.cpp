class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n=letters.size();
        int low=0;
        int high=n-1;
        int ind=0;
        while(low<=high)
        {
            int mid =(low+high)/2;

            if(letters[mid]-'a'>target-'a' )
            {

                ind=mid;
                high=mid-1;
            }
            else if(letters[mid]-'a'<=target-'a')
            {
                low=mid+1;
            }
        }

        return letters[ind];
    }
};