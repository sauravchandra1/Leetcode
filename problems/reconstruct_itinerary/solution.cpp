class Solution {
public:
        struct graph {
        string name;
        vector < graph * > nb;
        graph(string s): name(s) {}
    };

    string func(unordered_map < string, graph * > & tmp, graph * node, int & pos, int & len) {
        string rz;
        pos++;
        for (int i = 0; i < node -> nb.size(); i++) {
            if (!node -> nb[i]) continue;
            else {
                graph * tt = node -> nb[i];
                node -> nb[i] = NULL;
                rz = func(tmp, tmp[tt -> name], pos, len);
                if (pos + rz.size() / 3 >= len) {
                    pos--;
                    return node -> name + rz;
                }
                node -> nb[i] = tt;
            }
        }
        pos--;
        return node -> name;
    }

    vector < string > findItinerary(vector < vector < string > > & tickets) {
        vector < string > rez;
        if (tickets.empty()) return rez;
        sort(tickets.begin(), tickets.end());
        unordered_map < string, graph * > tmp;

        for (int i = 0; i < tickets.size(); i++) {
            if (!tmp.count(tickets[i][0])) {
                graph * cur = new graph(tickets[i][0]);
                tmp[tickets[i][0]] = cur;
            }
            if (!tmp.count(tickets[i][1])) {
                graph * cur = new graph(tickets[i][1]);
                tmp[tickets[i][1]] = cur;
            }
            tmp[tickets[i][0]] -> nb.push_back(tmp[tickets[i][1]]);
        }
        graph * node = tmp["JFK"];
        int len = tickets.size(), pos = 0;
        string rz = func(tmp, node, pos, len);

        for (int i = 0; i < rz.size(); i = i + 3) {
            string t;
            t.assign(rz.begin() + i, rz.begin() + i + 3);
            rez.push_back(t);
        }
        return rez;
    }
};