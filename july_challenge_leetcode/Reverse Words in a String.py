# Problem
  
# Given an input string, reverse the string word by word.
  
# Example
  
# Input: "the sky is blue"
# Output: "blue is sky the"

# Input: "  hello world!  "
# Output: "world! hello"

# Input: "a good   example"
# Output: "example good a"
  
  
# Constraints:
  
# A word is defined as a sequence of non-space characters.
# Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
# You need to reduce multiple spaces between two words to a single space in the reversed string.
  
#-----------------------------------------------------------------------------------------------------
# Solution

class Solution:
    def reverseWords(self, s: str) -> str:
        ans = ""
        for w in s.split():
            ans = " "+w+ans
        return ans[1:]
        

