#include <bits/stdc++.h>

using namespace std;

vector<string> ep_list;
vector<pair<int, int> > change_list;
int NUM_STRINGS = 300;


void print_list(int N, int C, bool rev, string suffix) {
    if(ep_list.size() > NUM_STRINGS)
        return;

    if(C == 0) {
        ep_list.push_back(string(N, '0') + suffix);
        // printf("%d %d %d: %s\n", N, C, rev, suffix.c_str());
        return;
    }
    else if(C == N) {
        ep_list.push_back(string(N, '1') + suffix);
        // printf("%d %d %d: %s\n", N, C, rev, suffix.c_str());
        return;
    }

    if(rev) {
        print_list(N - 1, C, false, "0" + suffix);
        print_list(N - 1, C - 1, true, "1" + suffix);
    } 
    else {
        print_list(N - 1, C - 1, false, "1" + suffix);
        print_list(N - 1, C, true, "0" + suffix);
    }
    return;
}


void print_changes(int N, int C, bool rev) {
    if(change_list.size() > NUM_STRINGS - 1)
        return;

    if(C == N || C == 0)
        return;
    // else if(C == 1 && N == 2) {
    //     change_list.push_back(make_pair(2, 1));
    //     return;
    // }
    
    if(rev) {
        print_changes(N - 1, C, false);
        if(N == 2 && C == 1) // both parents are end nodes
            change_list.push_back(make_pair(1, 2));
        else if(C - 1 == 0) { // left parent is end node (all zeroes with 1 at end)
            change_list.push_back(make_pair(N - 2, N));
        }
        else if(N - 1 == C) { // right parent is end node (all ones with 0 at end)
            change_list.push_back(make_pair(N - 1, N));
        }
        else {
            change_list.push_back(make_pair(N - C - 1, N));
        }
        print_changes(N - 1, C - 1, true);
    }
    else {
        print_changes(N - 1, C - 1, false);
        if(N == 2 && C == 1) // both parents are end nodes
            change_list.push_back(make_pair(2, 1));
        else if(C - 1 == 0) { // left parent is end node (all zeroes with 1 at end)
            change_list.push_back(make_pair(N, N-2));
        }
        else if(N - 1 == C) { // right parent is end node (all ones with 0 at end)
            change_list.push_back(make_pair(N, N-1));
        }
        else {
            change_list.push_back(make_pair(N, N - C - 1));
        }
        print_changes(N - 1, C, true);
    }
    return;
}

bool proper_change(string a, string b) {
    int changed = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i])
            changed++;
    }

    return changed == 2;
}

int main() {
    int testcases;
    scanf(" %d", &testcases);
    for(int tc = 0; tc < testcases; tc++) {
        change_list.clear();
        int A, G, N;
        scanf(" %d %d %d", &G, &N, &A);

        set<string> first_guests;
        vector<string> actors;
        vector<string> new_list;

        char buffer[10] = {};
        for(int i = 0; i < A; i++) {
            scanf(" %s", buffer);
            actors.push_back(string(buffer));
        }
        for(int i = 0; i < G; i++) {
            scanf(" %s", buffer);
            first_guests.insert(string(buffer));
        }
        for(int i = 0; i < A; i++) {
            if(first_guests.find(actors[i]) == first_guests.end())
                new_list.push_back(actors[i]);
        }
        for(set<string>::iterator it = first_guests.begin(); it != first_guests.end(); ++it) {
            new_list.push_back(*it);
        }

        // for(int i = 0; i < A; i++)
        //     printf("%s\t", new_list[i].c_str());
        // printf("\n");

        NUM_STRINGS = N;
        print_changes(A, G, false);

        if(tc > 0)
            printf("\n");
        for(int i = 0; i < NUM_STRINGS - 1; i++) {
            printf("%s %s\n", new_list[change_list[i].first - 1].c_str(), new_list[change_list[i].second - 1].c_str());
        }
    }
}