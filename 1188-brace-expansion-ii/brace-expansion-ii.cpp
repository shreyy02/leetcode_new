class Solution {
public:

    string s;
    int i = 0;

    // Union of two sets
    set<string> merge(set<string> a, set<string> b) {
        for (string x : b)
            a.insert(x);

        return a;
    }

    // Concatenation of two sets
    set<string> multiply(set<string> a, set<string> b) {
        set<string> res;

        for (string x : a) {
            for (string y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    // expression = term { , term }
    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++;  // skip comma
            res = merge(res, parseTerm());
        }

        return res;
    }

    // term = factor factor factor ...
    set<string> parseTerm() {
        set<string> res;
        res.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = parseFactor();
            res = multiply(res, cur);
        }

        return res;
    }

    // factor = letter OR { expression }
    set<string> parseFactor() {

        // If we find {
        if (s[i] == '{') {
            i++;  // skip {

            set<string> res = parseExpression();

            i++;  // skip }

            return res;
        }

        // Otherwise it is a letter
        set<string> res;
        res.insert(string(1, s[i]));

        i++;

        return res;
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        i = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};