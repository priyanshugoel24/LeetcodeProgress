// Last updated: 02/05/2026, 22:32:24
class Solution {
public:
    int score(vector<string>& cards, char x) {
        array<int,26> L{}; L.fill(0);
        array<int,26> R{}; R.fill(0);
        int B = 0;

        for (const string& s : cards) {
            char a = s[0], b = s[1];
            if (a == x && b == x) B++;
            else if (a == x && b != x) L[b - 'a']++;
            else if (b == x && a != x) R[a - 'a']++;
            // ignore cards without x
        }

        auto maxPairsSide = [](const array<int,26>& cnt) -> pair<int,int> {
            int total = 0, mx = 0;
            for (int c : cnt) { total += c; mx = max(mx, c); }
            int pairs = min(total - mx, total / 2);
            return {pairs, total};
        };

        auto [PL, TL] = maxPairsSide(L);
        auto [PR, TR] = maxPairsSide(R);

        int PLR = PL + PR;     // max internal pairs possible
        int T = TL + TR;       // total singles (non-"xx") containing x

        // Choose internal-pair count t* to best use B wildcards.
        int tStar = (T - B) / 2;                // floor
        tStar = max(0, min(PLR, tStar));

        int leftovers = T - 2 * tStar;
        int useB = min(B, leftovers);

        return tStar + useB;
    }
};