#include "npc.h"

int main() {

    WorldMap worldMap;

    worldMap.addNpc(0, 0, "girl", 0xFF0000, "/textures/girl/red");
    worldMap.addNpc(1, 0, "girl", 0xFF0000, "/textures/girl/red");
    worldMap.addNpc(2, 0, "boy", 0xFF0000, "/textures/boy/red");

    for(auto& npc : worldMap.npcs) {
        std::cout << npc;
    }

}