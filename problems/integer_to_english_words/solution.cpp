class Solution {
public:
    string ones[20] = {"Zero", "One", "Two", "Three", "Four",
                       "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                      "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty",
                       "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string others[4] = {"Hundred", "Thousand", "Million", "Billion"};
    int billions = 1000000000;
    int millions = 1000000;
    int thousands = 1000;
    int hundreds = 100;
    //int tens = 20;
    string numberToWords(int num, int val, int otherIndex) {
        string ans = "";
        ans += numberToWords(num / val);
        ans += " ";
        ans += others[otherIndex];
        if(num % val != 0) {
            ans += " ";
            ans += numberToWords(num % val);
        }
        return ans;
    }
    string numberToWords(int num) {
        
        if(num >= billions)
            return numberToWords(num, billions, 3);
        if(num >= millions)
            return numberToWords(num, millions, 2);
        if(num >= thousands)
            return numberToWords(num, thousands, 1);
        if(num >= hundreds)
            return numberToWords(num, hundreds, 0);
        if(num < 20) 
            return ones[num];
        int n = num / 10;
        string ans = tens[n];
        if(num % 10 != 0) {
            ans += " ";
            ans += ones[num % 10];
        }
        return ans;
    }
};