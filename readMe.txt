 How to Compile:
 Compile: g++ -std=c++17 Inventory.cpp Map.cpp Merchant.cpp Party.cpp Player.cpp dungeonEscape.cpp 
 Run: ./a.out

 Dependencies:
 Inventory.h, Map.h, Merchant.h, Party.h, and Player.h must be in the same directory to Compile

 Submission Information:
 CSCI1300 Fall 2022
 Author: Louis Blanc
 Recitation: 106 - Chanheum Park
 Date: December 1, 2022

 About this project:
 This project consists of a game which progresses based on the user's input. At the start of the game, the user is able to buy
 objects and ingredients from the merchant, which will also decide how the game will progress. Once the user finishes shopping,
 they will be able to move around the map, exploring different spaces and rooms that are on the map. When approaching a room or
 NPC character, you have a chance to fight a monster and gain extra materials. Based on the weapons and armour in your inventory, 
 you will either win or lose against the monster. With a total of 5 rooms, if you beat every single monster in each room, you are 
 able to fight the Sorcerer at the end. 