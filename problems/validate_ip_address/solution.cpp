class Solution {
public:
       string validateIPv4(const string & IP) {
        string temp = "";
        int count = 0;
        for (unsigned int i = 0; i < IP.length(); i++) {
            if (!isdigit(IP[i])) return "Neither";
            while (i < IP.length() && IP[i] != '.') {
                if (!isdigit(IP[i])) return "Neither";
                temp += IP[i];
                ++i;
                if ((temp[0] == '0' && temp.length() > 1) || temp.length() > 4)
                    return "Neither";
            }
            if (stoi(temp) >= 0 && stoi(temp) < 256) {
                ++count;
                temp = "";
            } else return "Neither";
        }
        if (count != 4 || !isdigit(IP[IP.length() - 1])) return "Neither";
        return "IPv4";
    }
    string validateIPv6(const string & IP) {
        string valid = "0123456789aAbBcCdDeEfF";
        string temp = "";
        int count = 0;
        for (unsigned int i = 0; i < IP.length(); i++) {
            if (count > 7 || valid.find(IP[i]) == string::npos) return "Neither";
            while (i < IP.length() && IP[i] != ':') {
                if (valid.find(IP[i]) == string::npos || temp.length() >= 4)
                    return "Neither";
                temp += IP[i];
                ++i;
            }
            if (temp.length() <= 4) {
                ++count;
                temp = "";
            } else return "Neither";
        }
        if (count != 8 || valid.find(IP[IP.length() - 1]) == string::npos)
            return "Neither";
        return "IPv6";
    }
    string validIPAddress(string IP) {
        if (!IP.length()) return "Neither";
        int pos1 = IP.find_first_of('.');
        int pos2 = IP.find_first_of(':');
        if (pos1 && pos2 && pos1 != string::npos && pos2 != string::npos)
            return "Neither";
        if (pos1 > 0 && pos1 != string::npos) return validateIPv4(IP);
        if (pos2 > 0 && pos2 != string::npos) return validateIPv6(IP);
        return "Neither";
    }
};