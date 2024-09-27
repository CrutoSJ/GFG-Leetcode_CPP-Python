// #Question:-

// Link-> https://leetcode.com/problems/my-calendar-ii/description/?envType=daily-question&envId=2024-09-27

// Date-> 27/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleBooking;
    vector<pair<int,int>> Bookings;

    bool ifOverlapping(int start1, int end1, int start2, int end2){
        return (max(start1, start2) < min(end1, end2));
    }

    pair<int, int> findOverlapping(int start1, int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int,int> region : doubleBooking){
            if(ifOverlapping(region.first, region.second, start, end)){
                return false;
            }
        }

        for(pair<int,int> booking : Bookings){
            if(ifOverlapping(booking.first, booking.second, start, end)){
                doubleBooking.push_back(findOverlapping(booking.first, booking.second, start, end));
            }
        }

        Bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */