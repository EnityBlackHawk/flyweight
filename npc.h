#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <iostream>


using Color = double;
using Texture = std::string;

struct Npc {


    struct Type {
        std::string name;
        Color color;
        Texture texture;

        Type(const std::string& name, const Color& color, const Texture& texture) : name(name), color(color), texture(texture) {}

    };

    Npc(int posX, int posY, std::shared_ptr<Npc::Type> type) : posX(posX), posY(posY), type(type) {} 

    int posX;
    int posY;
    std::shared_ptr<Npc::Type> type;


    friend std::ostream &operator<<(std::ostream &os, const Npc &npc) {
        os << "[( " << npc.posX << ", " << npc.posY << "), &type: " << npc.type.get() << " ]" << std::endl;
        return os;
    }

};


class NpcFactory {

public:
    NpcFactory() = default;

    static std::shared_ptr<Npc::Type> getType(const std::string& name, const Color& color, const Texture& texture) {

        auto result = types.find(name);
        if(result == types.end()) {
            auto type = std::make_shared<Npc::Type>(name, color, texture);
            types[name] = type;
            return type;
        }
        return result->second;
    } 

private:
    static std::unordered_map<std::string, std::shared_ptr<Npc::Type>> types;


};
std::unordered_map<std::string, std::shared_ptr<Npc::Type>> NpcFactory::types;

class WorldMap {

public:

    WorldMap() = default;

    void addNpc(int posX, int posY, const std::string& name, const Color& color, const Texture& texture) {

        auto type = NpcFactory::getType(name, color, texture);
        npcs.emplace_back(posX, posY, type);
    }

    
    std::vector<Npc> npcs;

};