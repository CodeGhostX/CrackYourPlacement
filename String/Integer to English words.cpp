class Solution {
public:
    string solveTwoOne(int num){
        string ones[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string twos[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if(num<=9) return ones[num-1];
        if(num>=10 && num<=19) return twos[num-10];
        string ans = "";
        if(num>=20){
            int second = num/10;
            ans += tens[second-2];
            num = num%10;
            if(num) ans += " ";
            if(num) {
                ans += ones[num-1];
            }
        }
        return ans;
    }
    string solveThree(int num){
        string ans = "";
        if(num==0) return ans;
        int one = num/100;
        int b = num%100;
        if(one) {
            ans += solveTwoOne(one);
            ans += " Hundred";
            if(b) ans += " ";
        }
        if(b){
            ans += solveTwoOne(b);
        }
        return ans;
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string threes[] = {"", "Thousand", "Million", "Billion"};
        int idx = 0;
        string ans = "";
        while(num){
            int threeDigits = num%1000;
            num = num/1000;
            string temp = "";
            if(threeDigits) {
                temp = solveThree(threeDigits);
                ans = temp + " " + threes[idx] + " " + ans;
            }
            idx++;
        }
        int i = ans.size()-1;
        int c = 0;
        while(ans[i]==' '){
            c++;
            i--;
        }
        while(c){
            ans.pop_back();
            c--;
        }
        return ans;
    }
};
