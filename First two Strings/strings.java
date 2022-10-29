class Solution {
    public int strStr(String haystack, String needle) {
         int l1=haystack.length();
    int l2=needle.length();
  
    int FL=l1-l2;
 
   
    
    
    
    for(int i=0;i<=FL;)
    {
        
        if(needle.equals(haystack.substring(i,l2)))
        {
            return i;
        }
        i++;
        l2++;
    }
    
    