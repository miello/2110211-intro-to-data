#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};

class CompareOne {
  public:
  bool operator()(const Song& a, const Song& b) {
    if(a.artist < b.artist) return false;
    if(a.artist > b.artist) return true;

    if(a.title < b.title) return false;
    if(a.title > b.title) return true;

    if(a.count < b.count) return false;
    if(a.count > b.count) return true;

    return false;
  }  
};

class CompareTwo {
  public:
  bool operator()(const Song& a, const Song& b) {
    if(a.count > b.count) return false;
    if(a.count < b.count) return true;

    if(a.artist < b.artist) return false;
    if(a.artist > b.artist) return true;

    if(a.title < b.title) return false;
    if(a.title > b.title) return true;


    return false;
  }  
};

//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song, CompareOne> pq1;
CP::priority_queue<Song, CompareTwo> pq2;

#endif
