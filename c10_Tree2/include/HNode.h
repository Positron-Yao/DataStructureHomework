#pragma once

class HNode {
    public:
        HNode *l, *r;
        int w;

        HNode(int w): w(w) {}

        int WPL() {
            int sum = 0;
            WPL_helper(0, sum);
            return sum;
        }

        void WPL_helper(int h, int &sum) {
            if (l == nullptr && r == nullptr) {
                sum += w * h;
                return;
            }
            l->WPL_helper(h + 1, sum);
            r->WPL_helper(h + 1, sum);
        }
};

