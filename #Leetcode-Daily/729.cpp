// #Question:-

// Link-> https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26

// Date-> 26/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
private:
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        const pair<int, int> event{start, end};
        const auto nextEvent = calendar.lower_bound(event);
        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;
        }

        if (nextEvent != calendar.begin()) {
            const auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }
};