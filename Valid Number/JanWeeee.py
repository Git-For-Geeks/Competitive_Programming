# list of the possible error conditions and then check for each one:
    # More than one exponent character ('e'/'E'), or seeing an 'e'/'E' when a number has not yet been seen.
    # More than one sign, or a sign appearing after a decimal or number have been seen. This gets reset when passing an 'e'/'E'.
    # More than one decimal, or a decimal appearing after an 'e'/'E' has been seen.
    # Any other non-number character appearing.
    # Reaching the end of S without an active number.
    # To help with this process, we can set up some boolean flags for the different things of which we're keeping track (num, exp, sign, dec). We'll also need to remember to reset all flags except exp when we find an 'e'/'E', as we're starting a new integer expression.

class Solution:
    def isNumber(self, S: str) -> bool:    
        num, exp, sign, dec = False, False, False, False
        for c in S:
            if c >= '0' and c <= '9': num = True     
            elif c == 'e' or c == 'E':
                if exp or not num: return False
                else: exp, num, sign, dec = True, False, False, False
            elif c == '+' or c == '-':
                if sign or num or dec: return False
                else: sign = True
            elif c == '.':
                if dec or exp: return False
                else: dec = True
            else: return False
        return num

