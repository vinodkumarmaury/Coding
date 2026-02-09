
// Variables shared by all objects of the class. They belong to the class, not the instance.

#include<bits/stdc++.h>
using namespace std;

class Player {
public:
    static int playerCount; // Declaration

    Player() { playerCount++; }
    ~Player() { playerCount--; }
};

// Definition and Initialization (Must be outside class)
int Player::playerCount = 0;

int main() {
    Player p1;
    Player p2;
    cout << Player::playerCount; // Output: 2
}