#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

#include "Player.h"
#include "Wall.h"
#include "Walls.h"
#include "Mob.h"
#include "Mobs.h"
#include "SnakeMob.h"
#include "SnakeMobs.h"
#include "BOSSMOB.h"
#include "BOSSMOBS.h"
#include "Box.h"
#include "Boxs.h"
#include "Coin.h"
#include "Coins.h"
#include "Key.h"
#include "Keys.h"
#include "Teleport.h"
#include "Teleports.h"

bool gameOver;
const int width = 250;
const int height = 50;
int level = 0, room = 0;
void setCursor(int x, int y) {
    COORD position = { x,y };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);
}
BOOL ShowConsoleCursor(BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;
    if (!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    cci.bVisible = bShow;
    if (!SetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    return TRUE;
}
void Draw()
{
    system("cls");
    Coins coins;
    for (int i = 0; i < width + 2; i++) {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "|";
            else
            {
                bool print = false;
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "|";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
    cout << "-";
    cout << endl;
    cout << "Level:" << room << endl;
    cout << "by Vnukov & Bazilevich" << endl;
   
}
bool directionCollision(Player player, string direction, int x, int y, int width, int height) {
    if (direction == "right") {
        if (player.getX() + player.getWidth() == x && player.getY() + player.getHeight() > y && player.getY() < y + height) {
            return true;
        }
    }
    if (direction == "top") {
        if (player.getY() == y + height && player.getX() + player.getWidth() > x && player.getX() < x + width) {
            return true;
        }
    }
    if (direction == "left") {
        if (player.getX() == x + width && player.getY() + player.getHeight() > y && player.getY() < y + height) {
            return true;
        }
    }
    if (direction == "bottom") {
        if (player.getY() + player.getHeight() == y && player.getX() + player.getWidth() > x && player.getX() < x + width) {
            return true;
        }
    }
    return false;
}
bool collision(Player& player, int x, int y, int width, int height) {
    if (directionCollision(player, "right", x, y, width, height)) {
        player.setEnemtyColliders("right", true);
        return true;
    }
    if (directionCollision(player, "top", x, y, width, height)) {
        player.setEnemtyColliders("top", true);
        return true;
    }
    if (directionCollision(player, "left", x, y, width, height)) {
        player.setEnemtyColliders("left", true);
        return true;
    }
    if (directionCollision(player, "bottom", x, y, width, height)) {
        player.setEnemtyColliders("bottom", true);
        return true;
    }
    return false;
}
Keys keys;
Boxs boxs;
Walls walls;
Mobs mobs;
Coins coins;
SnakeMobs sn;
BOSSMOBS boss;
Teleports teleports;
Player player(80, 35);

string coinss[3] = { "---", "$$$", "---" };

string keyss[3] = { "---","|K|","---" };

string box2[4] = { "----", "|  |", "----" };
//string mobui[3] = { "!@#", "#@!", "!#@" };
string telui[3] = { "~^~", "|#|", "~*~" };

string mobui[3] = { "###", "-_-", "###" };
string mobui1[3] = { "###", "-o-", "###" };
string mobui2[3] = { "###", "-0-", "###" };
string mobui3[3] = { "---", "0-0", "---" };
string mobui4[3] = { "---", "---", "0-0" };
string mobui5[3] = { "---", "I-I", "---" };

string mobZombi[3] = { "###", "???", "###" };

string mobSnake[3] = { "~~~~~", "~-0-~", "~~~~~" };
string mob2[4] = { "####################", "######(-(00)-)######", "####################" , "####################" };


void LevelDraw(int level, int room) {
    system("CLS");
    walls.deleteAll();
    mobs.deleteAll();
    teleports.deleteAll();
    boxs.deleteAll();
    sn.deleteAll();
    coins.deleteAll();
    keys.deleteAll();
    boss.deleteAll();
    Draw();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  
   
    if (level == 0) {
        walls.addItem(new Wall("       $$       ", 10, 4, 16, 1));
        walls.addItem(new Wall("      $  $      ", 10, 5, 16, 1));
        walls.addItem(new Wall("     $    $     ", 10, 6, 16, 1));
        walls.addItem(new Wall("    $      $    ", 10, 7, 16, 1));
        walls.addItem(new Wall("   $        $   ", 10, 8, 16, 1));

        walls.addItem(new Wall("       $$       ", 25, 4, 16, 1));
        walls.addItem(new Wall("      $  $      ", 25, 5, 16, 1));
        walls.addItem(new Wall("     $    $     ", 25, 6, 16, 1));
        walls.addItem(new Wall("    $$$$$$$$    ", 25, 7, 16, 1));
        walls.addItem(new Wall("   $        $   ", 25, 8, 16, 1));
       
        walls.addItem(new Wall("     $$$$$$     ", 40, 4, 16, 1));
        walls.addItem(new Wall("    $           ", 40, 5, 16, 1));
        walls.addItem(new Wall("    $           ", 40, 6, 16, 1));
        walls.addItem(new Wall("    $           ", 40, 7, 16, 1));
        walls.addItem(new Wall("     $$$$$$     ", 40, 8, 16, 1));
        
        
        walls.addItem(new Wall("    $  $        ", 55, 4, 16, 1));
        walls.addItem(new Wall("    $ $         ", 55, 5, 16, 1));
        walls.addItem(new Wall("    $$          ", 55, 6, 16, 1));
        walls.addItem(new Wall("    $ $         ", 55, 7, 16, 1));
        walls.addItem(new Wall("    $  $        ", 55, 8, 16, 1));

        walls.addItem(new Wall("       $$       ", 67, 4, 16, 1));
        walls.addItem(new Wall("      $  $      ", 67, 5, 16, 1));
        walls.addItem(new Wall("     $    $     ", 67, 6, 16, 1));
        walls.addItem(new Wall("    $$$$$$$$    ", 67, 7, 16, 1));
        walls.addItem(new Wall("   $        $   ", 67, 8, 16, 1));

        walls.addItem(new Wall("    $$$$        ", 82, 4, 16, 1));
        walls.addItem(new Wall("    $   $       ", 82, 5, 16, 1));
        walls.addItem(new Wall("    $$$$        ", 82, 6, 16, 1));
        walls.addItem(new Wall("    $   $       ", 82, 7, 16, 1));
        walls.addItem(new Wall("    $$$$        ", 82, 8, 16, 1));

        walls.addItem(new Wall("     $$$$$$     ", 95, 4, 16, 1));
        walls.addItem(new Wall("    $      $    ", 95, 5, 16, 1));
        walls.addItem(new Wall("    $      $    ", 95, 6, 16, 1));
        walls.addItem(new Wall("    $      $    ", 95, 7, 16, 1));
        walls.addItem(new Wall("     $$$$$$     ", 95, 8, 16, 1));


        walls.addItem(new Wall("   $$$$$$$$$$   ", 130, 4, 16, 1));
        walls.addItem(new Wall("   $$      $$   ", 130, 5, 16, 1));
        walls.addItem(new Wall("   $$      $$   ", 130, 6, 16, 1));
        walls.addItem(new Wall("   $$      $$   ", 130, 7, 16, 1));
        walls.addItem(new Wall("   $$      $$   ", 130, 8, 16, 1));

        walls.addItem(new Wall("    $$$$   ", 145, 4, 11, 1));
        walls.addItem(new Wall("    $   $  ", 145, 5, 11, 1));
        walls.addItem(new Wall("    $$$$   ", 145, 6, 11, 1));
        walls.addItem(new Wall("    $      ", 145, 7, 11, 1));
        walls.addItem(new Wall("    $      ", 145, 8, 11, 1));

        walls.addItem(new Wall("     $$$$$$     ", 155, 4, 16, 1));
        walls.addItem(new Wall("    $      $    ", 155, 5, 16, 1));
        walls.addItem(new Wall("    $      $    ", 155, 6, 16, 1));
        walls.addItem(new Wall("    $      $    ", 155, 7, 16, 1));
        walls.addItem(new Wall("     $$$$$$     ", 155, 8, 16, 1));

        walls.addItem(new Wall("     $$$$$$     ", 167, 4, 16, 1));
        walls.addItem(new Wall("    $           ", 167, 5, 16, 1));
        walls.addItem(new Wall("    $           ", 167, 6, 16, 1));
        walls.addItem(new Wall("    $           ", 167, 7, 16, 1));
        walls.addItem(new Wall("     $$$$$$     ", 167, 8, 16, 1));

        walls.addItem(new Wall("    $    $$    ", 180, 4, 16, 1));
        walls.addItem(new Wall("    $   $ $    ", 180, 5, 16, 1));
        walls.addItem(new Wall("    $  $  $    ", 180, 6, 16, 1));
        walls.addItem(new Wall("    $ $   $    ", 180, 7, 16, 1));
        walls.addItem(new Wall("    $$    $    ", 180, 8, 16, 1));

        walls.addItem(new Wall("   $$$    $$$   ", 195, 4, 16, 1));
        walls.addItem(new Wall("   $$ $  $ $$   ", 195, 5, 16, 1));
        walls.addItem(new Wall("   $$  $$  $$   ", 195, 6, 16, 1));
        walls.addItem(new Wall("   $$      $$   ", 195, 7, 16, 1));
        walls.addItem(new Wall("   $$      $$   ", 195, 8, 16, 1));

        walls.addItem(new Wall("     $$$$$$     ", 210, 4, 16, 1));
        walls.addItem(new Wall("    $      $    ", 210, 5, 16, 1));
        walls.addItem(new Wall("    $      $    ", 210, 6, 16, 1));
        walls.addItem(new Wall("    $      $    ", 210, 7, 16, 1));
        walls.addItem(new Wall("     $$$$$$     ", 210, 8, 16, 1));

        walls.addItem(new Wall("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------", 1, 23, 33, 1));
         
        walls.addItem(new Wall("     $$$$$$     ", 10, 14, 16, 1));
        walls.addItem(new Wall("    $      $    ", 10, 15, 16, 1));
        walls.addItem(new Wall("    $      $    ", 10, 16, 16, 1));
        walls.addItem(new Wall("    $      $    ", 10, 17, 16, 1));
        walls.addItem(new Wall("     $$$$$$     ", 10, 18, 16, 1));

        walls.addItem(new Wall("     $$$$       ", 25, 14, 16, 1));
        walls.addItem(new Wall("     $          ", 25, 15, 16, 1));
        walls.addItem(new Wall("     $$$$       ", 25, 16, 16, 1));
        walls.addItem(new Wall("     $   $      ", 25, 17, 16, 1));
        walls.addItem(new Wall("     $$$$       ", 25, 18, 16, 1));

        walls.addItem(new Wall("    $$$$$$$     ", 40, 14, 16, 1));
        walls.addItem(new Wall("    $           ", 40, 15, 16, 1));
        walls.addItem(new Wall("    $$$$$$$     ", 40, 16, 16, 1));
        walls.addItem(new Wall("    $           ", 40, 17, 16, 1));
        walls.addItem(new Wall("    $$$$$$$     ", 40, 18, 16, 1));


        walls.addItem(new Wall("    $$$$   ", 55, 14, 11, 1));
        walls.addItem(new Wall("    $   $  ", 55, 15, 11, 1));
        walls.addItem(new Wall("    $$$$   ", 55, 16, 11, 1));
        walls.addItem(new Wall("    $      ", 55, 17, 11, 1));
        walls.addItem(new Wall("    $      ", 55, 18, 11, 1));

        walls.addItem(new Wall("       $$       ", 67, 14, 16, 1));
        walls.addItem(new Wall("                ", 67, 15, 16, 1));
        walls.addItem(new Wall("       $$       ", 67, 16, 16, 1));
        walls.addItem(new Wall("       $$       ", 67, 17, 16, 1));
        walls.addItem(new Wall("       $$       ", 67, 18, 16, 1));

        walls.addItem(new Wall("   $$$$$$$$$$   ", 82, 14, 16, 1));
        walls.addItem(new Wall("       $$       ", 82, 15, 16, 1));
        walls.addItem(new Wall("       $$       ", 82, 16, 16, 1));
        walls.addItem(new Wall("       $$       ", 82, 17, 16, 1));
        walls.addItem(new Wall("       $$       ", 82, 18, 16, 1));

        walls.addItem(new Wall("     $          ", 95, 14, 16, 1));
        walls.addItem(new Wall("     $          ", 95, 15, 16, 1));
        walls.addItem(new Wall("     $$$$       ", 95, 16, 16, 1));
        walls.addItem(new Wall("     $   $      ", 95, 17, 16, 1));
        walls.addItem(new Wall("     $$$$       ", 95, 18, 16, 1));


        walls.addItem(new Wall("    $$$$   ", 130, 14, 11, 1));
        walls.addItem(new Wall("    $   $  ", 130, 15, 11, 1));
        walls.addItem(new Wall("    $$$$   ", 130, 16, 11, 1));
        walls.addItem(new Wall("    $      ", 130, 17, 11, 1));
        walls.addItem(new Wall("    $      ", 130, 18, 11, 1));

        walls.addItem(new Wall("       $$       ", 141, 14, 16, 1));
        walls.addItem(new Wall("                ", 141, 15, 16, 1));
        walls.addItem(new Wall("       $$       ", 141, 16, 16, 1));
        walls.addItem(new Wall("       $$       ", 141, 17, 16, 1));
        walls.addItem(new Wall("       $$       ", 141, 18, 16, 1));

        walls.addItem(new Wall("    $$$$        ", 155, 14, 16, 1));
        walls.addItem(new Wall("    $   $       ", 155, 15, 16, 1));
        walls.addItem(new Wall("    $$$$        ", 155, 16, 16, 1));
        walls.addItem(new Wall("    $   $       ", 155, 17, 16, 1));
        walls.addItem(new Wall("    $$$$        ", 155, 18, 16, 1));

        walls.addItem(new Wall("    $$$$$$$     ", 167, 14, 16, 1));
        walls.addItem(new Wall("    $           ", 167, 15, 16, 1));
        walls.addItem(new Wall("    $$$$$$$     ", 167, 16, 16, 1));
        walls.addItem(new Wall("    $           ", 167, 17, 16, 1));
        walls.addItem(new Wall("    $$$$$$$     ", 167, 18, 16, 1));

        walls.addItem(new Wall("    $     $    ", 180, 14, 16, 1));
        walls.addItem(new Wall("    $     $    ", 180, 15, 16, 1));
        walls.addItem(new Wall("    $$$$$$$    ", 180, 16, 16, 1));
        walls.addItem(new Wall("    $     $    ", 180, 17, 16, 1));
        walls.addItem(new Wall("    $     $    ", 180, 18, 16, 1));

        walls.addItem(new Wall("     $          ", 195, 14, 16, 1));
        walls.addItem(new Wall("     $          ", 195, 15, 16, 1));
        walls.addItem(new Wall("     $$$$       ", 195, 16, 16, 1));
        walls.addItem(new Wall("     $   $      ", 195, 17, 16, 1));
        walls.addItem(new Wall("     $$$$       ", 195, 18, 16, 1));

        

        walls.addItem(new Wall("~~~~~~~~~~~~~~~~", 40, 24, 15, 1));
        walls.addItem(new Wall("~~~~LEVEL№1~~~~~", 40, 25, 15, 1));
        walls.addItem(new Wall("&&&&", 56, 24, 4, 7));
        walls.addItem(new Wall("&&&&", 36, 24, 4, 7));

        walls.addItem(new Wall("~~~~~~~~~~~~~~~~", 80, 24, 15, 1));
        walls.addItem(new Wall("~~~~LEVEL№2~~~~~", 80, 25, 15, 1));
        walls.addItem(new Wall("&&&&", 96, 24, 4, 7));
        walls.addItem(new Wall("&&&&", 76, 24, 4, 7));


        walls.addItem(new Wall("~~~~~~~~~~~~~~~~", 120, 24, 15, 1));
        walls.addItem(new Wall("~~~~LEVEL№3~~~~~", 120, 25, 15, 1));
        walls.addItem(new Wall("&&&&", 136, 24, 4, 7));
        walls.addItem(new Wall("&&&&", 116, 24, 4, 7));


        walls.addItem(new Wall("~~~~~~~~~~~~~~~~", 160, 24, 15, 1));
        walls.addItem(new Wall("~~~~LEVEL№4~~~~~", 160, 25, 15, 1));
        walls.addItem(new Wall("&&&&", 176, 24, 4, 7));
        walls.addItem(new Wall("&&&&", 156, 24, 4, 7));


        walls.addItem(new Wall("~~~~~~~~~~~~~~~~", 200, 24, 15, 1));
        walls.addItem(new Wall("~~~~LEVEL№5~~~~~", 200, 25, 15, 1));
        walls.addItem(new Wall("&&&&", 216, 24, 4, 7));
        walls.addItem(new Wall("&&&&", 196, 24, 4, 7));
        //mobs.addItem(new Mob(mobui, 120, 20, 3, 3, 100, 10, 15, 15));
        
        teleports.addItem(new Teleport(telui, 46, 27, 3, 3, 1, 1));
        teleports.addItem(new Teleport(telui, 87, 27, 3, 3, 2, 2));
        teleports.addItem(new Teleport(telui, 127, 27, 3, 3, 3, 3));
        teleports.addItem(new Teleport(telui, 167, 27, 3, 3, 4, 4));
        teleports.addItem(new Teleport(telui, 207, 27, 3, 3, 5, 5));
        player.setPlayerPosition(140, 35);
    }
    if (level == 1 && room == 1) {
        //mobs.addItem(new Mob(mobui, 120, 20, 3, 3, 100, 10, 15, 5));

        boxs.addItem(new Box(box2, 12, 32, 4, 4, 100, 10, 5));
        boxs.addItem(new Box(box2, 189, 25, 4, 4, 100, 10, 5));

        coins.addItem(new Coin(coinss, 189, 32, 3, 3, 100, 10, 100));

        mobs.addItem(new Mob(mobui, 12, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 85, 37, 3, 3, 100, 50, 50, 50));
        sn.addItem(new SnakeMob(mobSnake, 120, 20, 3, 3, 100, 50, 50, 50));

        walls.addItem(new Wall("||||||", 25, 1, 6, 16));
        walls.addItem(new Wall("||||||", 25, 35, 6, 16));

        walls.addItem(new Wall("Початок->", 33, 5, 9, 1));
        //sn.addItem(new SnakeMob(mobSnake, 120, 20, 3, 3, 100, 10, 15,10));
        walls.addItem(new Wall("<-Скриня", 25, 34, 8, 1));
        walls.addItem(new Wall("<-Моб", 25, 17, 5, 1));
        walls.addItem(new Wall("||||||", 60, 10, 6, 41));

        walls.addItem(new Wall("||||||", 110, 1, 6, 38));
        walls.addItem(new Wall("<-Щоб вбити цього моба,", 100, 39, 22, 1));
        walls.addItem(new Wall("<-натисніть (у)", 100, 40, 5, 1));
        

        walls.addItem(new Wall("------------------------------------------------------", 116, 36, 54, 3));
        walls.addItem(new Wall("||||||", 170, 16, 6, 23));
        walls.addItem(new Wall("Заберіть коїн->", 168, 39, 15, 1));
        walls.addItem(new Wall("----------------------------------", 176, 16, 34, 3));
        walls.addItem(new Wall("||||||", 210, 16, 6, 23));

        walls.addItem(new Wall("Фініш", 138, 33, 5, 1));
        teleports.addItem(new Teleport(telui, 140, 30, 3, 3, 0, 0));
        
        player.setPlayerPosition(40, 45);
        player.showHp();
        player.inventar();
        //player.setCatana();
    }
    if (level == 2 && room == 2) {
        walls.addItem(new Wall("||||||", 25, 1, 6, 16));
        walls.addItem(new Wall("||||||", 25, 35, 6, 16));
        coins.addItem(new Coin(coinss, 12, 32, 3, 3, 100, 10, 100));
        walls.addItem(new Wall("Заберіть коїн", 6, 40, 13, 1));
        walls.addItem(new Wall("щоб відкрити стіну", 6, 41, 18, 1));
        
        boxs.addItem(new Box(mobui1, 141, 18, 3, 3, 100, 10, 50));
        boxs.addItem(new Box(mobui2, 141, 33, 3, 3, 100, 10, 50));
        mobs.addItem(new Mob(mobui3, 80, 28, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 95, 28, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui3, 125, 43, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 140, 43, 3, 3, 100, 50, 50, 50));
      
        mobs.addItem(new Mob(mobui, 43, 16, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 45, 20, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 43, 25, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 12, 16, 3, 3, 100, 50, 50, 50));

        walls.addItem(new Wall("||||||", 60, 10, 6, 41));
        walls.addItem(new Wall("||||||", 110, 16, 6, 23));
        walls.addItem(new Wall("------------------------------------------------------", 116, 16, 51, 2));
        walls.addItem(new Wall("------------------------------------------------------", 116, 22, 51, 2));
        walls.addItem(new Wall("------------------------------------------------------", 116, 36, 54, 2));
        walls.addItem(new Wall("------------------------------------------------------", 116, 31, 54, 2));
        
        
        walls.addItem(new Wall("||||||", 170, 1, 6, 39));
        
        walls.addItem(new Wall("||||||", 210, 1, 6, 39));

        boxs.addItem(new Box(box2, 150, 5, 4, 4, 100, 10, 5));

        walls.addItem(new Wall("--------------------------------------------", 66, 36, 5, 2));
        teleports.addItem(new Teleport(telui, 190, 10, 3, 3, 0, 0));
        walls.addItem(new Wall("Меню", 190, 8, 4, 1));
        teleports.addItem(new Teleport(telui, 220, 10, 3, 3, 3, 3));
        walls.addItem(new Wall("Наступный рівень", 220, 8, 16, 1));
        player.setPlayerPosition(144, 27);
        player.showHp();
        player.inventar();
    }
    if (level == 3 && room == 3) {
        
        mobs.addItem(new Mob(mobui, 125, 43, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 140, 43, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 155, 43, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 170, 43, 3, 3, 100, 50, 50, 50));
        boxs.addItem(new Box(box2, 30, 45, 4, 4, 100, 10, 5));


        mobs.addItem(new Mob(mobui3, 125, 33, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 140, 33, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 155, 33, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 170, 33, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui, 70, 33, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 85, 33, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 100, 33, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 115, 33, 3, 3, 100, 50, 50, 50));

        boxs.addItem(new Box(box2, 30, 33, 4, 4, 100, 10, 5));


        boxs.addItem(new Box(box2, 220, 33, 4, 4, 100, 10, 5));

        mobs.addItem(new Mob(mobui3, 125, 23, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 140, 23, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 155, 23, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 170, 23, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui, 70, 23, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 85, 23, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 100, 23, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 115, 23, 3, 3, 100, 50, 50, 50));

        boxs.addItem(new Box(box2, 220, 23, 4, 4, 100, 10, 5));


        mobs.addItem(new Mob(mobui3, 125, 11, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 140, 11, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 155, 11, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 170, 11, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui, 70, 11, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 85, 11, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 100, 11, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 115, 11, 3, 3, 100, 50, 50, 50));

        boxs.addItem(new Box(box2, 30, 11, 4, 4, 100, 10, 5));

        sn.addItem(new SnakeMob(mobSnake, 90, 3, 3, 3, 100, 50, 50, 50));

        walls.addItem(new Wall("------------------------------------------------------", 1, 16, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 52, 16, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 103, 16, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 155, 16, 51, 3));

        walls.addItem(new Wall("------------------------------------------------------", 43, 27, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 95, 27, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 146, 27, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 196, 27, 51, 3));

        walls.addItem(new Wall("------------------------------------------------------", 1, 38, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 52, 38, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 103, 38, 51, 3));
        walls.addItem(new Wall("------------------------------------------------------", 155, 38, 51, 3));

        walls.addItem(new Wall("------------------------------------------------------", 43, 7, 51, 1));
        walls.addItem(new Wall("------------------------------------------------------", 95, 7, 51, 1));
        walls.addItem(new Wall("------------------------------------------------------", 146, 7, 51, 1));
        walls.addItem(new Wall("------------------------------------------------------", 196, 7, 51, 1));


        teleports.addItem(new Teleport(telui, 220, 3, 3, 3, 4, 4));
        teleports.addItem(new Teleport(telui, 5, 42, 3, 3, 0, 0));
        walls.addItem(new Wall("Наступный рівень", 220, 1, 16, 1));
        player.setPlayerPosition(20, 45);
        player.showHp();
        player.setCatanaANDhilka();
    }
    if (level == 4 && room == 4) {
        
        boxs.addItem(new Box(box2, 189, 25, 4, 4, 100, 10, 5));
        boxs.addItem(new Box(box2, 12, 39, 4, 4, 100, 10, 5));

        coins.addItem(new Coin(coinss, 189, 32, 3, 3, 100, 10, 100));
        
        mobs.addItem(new Mob(mobui, 12, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 85, 37, 3, 3, 100, 50, 50, 50));
        sn.addItem(new SnakeMob(mobSnake, 130, 20, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui2, 40, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 40, 17, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 40, 22, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui4, 85, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 85 ,17, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui2, 85, 22, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui2, 140, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 140, 17, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 140, 22, 3, 3, 100, 50, 50, 50));
        sn.addItem(new SnakeMob(mobSnake, 150, 20, 3, 3, 100, 50, 50, 50));
        walls.addItem(new Wall("||||||", 25, 17, 6, 18));
        walls.addItem(new Wall("||||||", 25, 1, 6, 16));
        walls.addItem(new Wall("||||||", 25, 35, 6, 16));
        walls.addItem(new Wall("||||||", 60, 10, 6, 41));
        walls.addItem(new Wall("||||||", 110, 1, 6, 38));
        walls.addItem(new Wall("------------------------------------------------------", 116, 36, 54, 3));
        walls.addItem(new Wall("||||||", 170, 16, 6, 23));
        
        walls.addItem(new Wall("----------------------------------", 176, 16, 34, 3));
        walls.addItem(new Wall("||||||", 210, 16, 6, 23));

        
        teleports.addItem(new Teleport(telui, 140, 30, 3, 3, 0, 0));
        teleports.addItem(new Teleport(telui, 12, 6, 3, 3, 44, 44));
        player.setPlayerPosition(12, 32);
        player.showHp();
        player.inventar();
        //player.setCatana();
    }
    if (level == 5 && room == 5) {


        boxs.addItem(new Box(box2, 179, 48, 4, 4, 100, 10, 5));
        boxs.addItem(new Box(box2, 12, 39, 4, 4, 100, 10, 5));

        coins.addItem(new Coin(coinss, 189, 48, 3, 3, 100, 10, 100));

        mobs.addItem(new Mob(mobui, 12, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 85, 38, 3, 3, 100, 50, 50, 50));
        sn.addItem(new SnakeMob(mobSnake, 130, 14, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui3, 110, 14, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui2, 100, 14, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui5, 155, 39, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 155, 12, 3, 3, 100, 50, 50, 50));
        boxs.addItem(new Box(box2, 130, 7, 4, 4, 100, 10, 5));

        mobs.addItem(new Mob(mobui, 12, 22, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 12, 32, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui2, 55, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui2, 55, 22, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui2, 55, 32, 3, 3, 100, 50, 50, 50));

        walls.addItem(new Wall("----------------------------------------", 90, 20, 40, 1));
        walls.addItem(new Wall("|", 110, 24, 1, 8));
        walls.addItem(new Wall("|", 130, 20, 1, 12));
        walls.addItem(new Wall("--------------------", 110, 32, 20, 1));
        walls.addItem(new Wall("|", 90, 21, 1, 17));
        walls.addItem(new Wall("------------------------------------------------------------", 90, 37, 60, 1));
        walls.addItem(new Wall("|", 150, 11, 1, 27));
        walls.addItem(new Wall("--------------------------------------------------------------------------------", 70, 11, 80, 1));
        walls.addItem(new Wall("|", 70, 11, 1, 33));
        walls.addItem(new Wall("----------------------------------------------------------------------------------------------------", 70, 44, 100, 1));
        walls.addItem(new Wall("|", 170, 6, 1, 38));
        walls.addItem(new Wall("----------------------------------------------------------------------------------------------------------------------------------------------------------------", 10, 6, 160, 1));
        walls.addItem(new Wall("|", 10, 6, 1, 45));
        walls.addItem(new Wall("--------------------------------------------------------------------------------", 16, 11, 80, 1));
        walls.addItem(new Wall("----------------------------------------", 11, 16, 40, 1));
        walls.addItem(new Wall("----------------------------------------", 30, 21, 40, 1));
        walls.addItem(new Wall("----------------------------------------", 11, 26, 40, 1));
        walls.addItem(new Wall("----------------------------------------", 30, 31, 40, 1));
        walls.addItem(new Wall("----------------------------------------", 11, 36, 40, 1));
        walls.addItem(new Wall("----------------------------------------", 30, 41, 40, 1));

        boss.addItem(new BOSSMOB(mob2, 220, 14, 3, 3, 100, 50, 50, 50));
        boss.addItem(new BOSSMOB(mob2, 190, 21, 3, 3, 100, 50, 50, 50));

        teleports.addItem(new Teleport(telui, 3, 45, 3, 3, 0, 0));
        walls.addItem(new Wall("Меню", 3, 48, 4, 1));
        
        player.setPlayerPosition(120, 29);
        player.showHp();
        player.setCatanaANDhilka();
    }

    if (level == 44 && room == 44) {

        boxs.addItem(new Box(box2, 189, 25, 4, 4, 100, 10, 5));
        boxs.addItem(new Box(box2, 12, 39, 4, 4, 100, 10, 5));

        coins.addItem(new Coin(coinss, 189, 32, 3, 3, 100, 10, 100));

        mobs.addItem(new Mob(mobui, 12, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui, 85, 37, 3, 3, 100, 50, 50, 50));
        sn.addItem(new SnakeMob(mobSnake, 130, 20, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui2, 40, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 40, 17, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 40, 22, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui4, 85, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 85, 17, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui2, 85, 22, 3, 3, 100, 50, 50, 50));

        mobs.addItem(new Mob(mobui2, 140, 12, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui3, 140, 17, 3, 3, 100, 50, 50, 50));
        mobs.addItem(new Mob(mobui4, 140, 22, 3, 3, 100, 50, 50, 50));
        sn.addItem(new SnakeMob(mobSnake, 150, 20, 3, 3, 100, 50, 50, 50));
        walls.addItem(new Wall("||||||", 25, 17, 6, 18));
        walls.addItem(new Wall("||||||", 25, 1, 6, 16));
        walls.addItem(new Wall("||||||", 25, 35, 6, 16));
        walls.addItem(new Wall("||||||", 60, 10, 6, 41));
        walls.addItem(new Wall("||||||", 110, 1, 6, 38));
        walls.addItem(new Wall("------------------------------------------------------", 116, 36, 54, 3));
        walls.addItem(new Wall("||||||", 170, 16, 6, 23));

        walls.addItem(new Wall("----------------------------------", 176, 16, 34, 3));
        walls.addItem(new Wall("||||||", 210, 16, 6, 23));


        teleports.addItem(new Teleport(telui, 140, 30, 3, 3, 0, 0));
        teleports.addItem(new Teleport(telui, 12, 6, 3, 3, 4, 4));
        player.setPlayerPosition(35, 40);
        player.showHp();
        player.inventar();
        //player.setCatana();
        
    }

    keys.addItem(new Key(NULL, 1000, 1000, 0, 0, 1, 0, 0));
    coins.addItem(new Coin(NULL, 1000, 1000, 0, 0, 1, 0, 0));
    sn.addItem(new SnakeMob(NULL, 1000, 1000, 0, 0, 1, 0, 0, 0));
    boss.addItem(new BOSSMOB(NULL, 1000, 1000, 0, 0, 1, 0, 0, 0));
    boxs.addItem(new Box(NULL, 1000, 1000, 0, 0, 1, 0, 0));
    mobs.addItem(new Mob(NULL, 1000, 1000, 0, 0, 1, 0, 0, 0));
    teleports.addItem(new Teleport(NULL, 1000, 1000, 0, 0, 0, 0));
    walls.draw();
    mobs.draw();
    teleports.draw();
    boxs.draw();
    sn.draw();
    coins.draw();
    keys.draw();
    boss.draw();
}
int main()
{
    srand((unsigned)time(0));
    setlocale(LC_CTYPE, "ukr");
    ShowConsoleCursor(FALSE);//скрыть курсор
    
    LevelDraw(level, room);

    ofstream out;
    out.open("E:\\!repos\\FinalExem\\Exam2.0\\exam.txt");
    if (out.is_open())
    {
        out << "0" << endl;
    }
    out.close();

    player.showHp();
    player.inventar();

    while (!gameOver) {
        player.movement(width, height);
        player.setEnemtyColliders("bottom", false);
        player.setEnemtyColliders("left", false);
        player.setEnemtyColliders("top", false);
        player.setEnemtyColliders("right", false);
        for (int i = 0; i < walls.getIndex() + mobs.getIndex() + teleports.getIndex() + boxs.getIndex()+sn.getIndex()+ coins.getIndex(); i++) {
            if (i < walls.getIndex()) {
                collision(player, walls[i]->getX(), walls[i]->getY(), walls[i]->getWidth(), walls[i]->getHeight());
            }
            if (i < mobs.getIndex()) {
                if (mobs[i]->getHp() <= 0) {
                    mobs[i]->clear();
                    mobs.deleteItem(i);
                }
                if (collision(player, mobs[i]->getX(), mobs[i]->getY(), mobs[i]->getWidth(), mobs[i]->getHeight())) {
                    mobs[i]->Mob_vision(player, 4);
                    break;
                }
                
                mobs[i]->Mob_vision(player, 4);
                mobs[i]->WalkTimer(player, 20);
            }
            if (i < boxs.getIndex()) {
                if (boxs[i]->getHp() <= 0) {
                    boxs[i]->clear();
                    boxs.deleteItem(i);
                }
                if (collision(player, boxs[i]->getX(), boxs[i]->getY(), boxs[i]->getWidth(), boxs[i]->getHeight())) {
                    boxs[i]->Box_vision(player, 4);
                    break;
                }

                boxs[i]->Box_vision(player, 4);
                
            }
            if (i < coins.getIndex()) {
                if (coins[i]->getHp() <= 0) {
                    coins[i]->clear();
                    coins.deleteItem(i);
                }
                if (collision(player, coins[i]->getX(), coins[i]->getY(), coins[i]->getWidth(), coins[i]->getHeight())) {
                    coins[i]->Coin_vision(player, 4);
                    break;
                }

                coins[i]->Coin_vision(player, 4);

            }
            if (i < keys.getIndex()) {
                if (keys[i]->getHp() <= 0) {
                    keys[i]->clear();
                    keys.deleteItem(i);
                }
                if (collision(player, keys[i]->getX(), keys[i]->getY(), keys[i]->getWidth(), keys[i]->getHeight())) {
                    keys[i]->Key_vision(player, 4);
                    break;
                }

                keys[i]->Key_vision(player, 4);

            }
            if (i < sn.getIndex()) {
                if (sn[i]->getHp() <= 0) {
                    sn[i]->clear();
                    sn.deleteItem(i);
                }
                if (collision(player, sn[i]->getX(), sn[i]->getY(), sn[i]->getWidth(), sn[i]->getHeight())) {
                    sn[i]->Mob_vision(player, 4);
                    break;
                }

                sn[i]->Mob_vision(player, 4);
                sn[i]->WalkTimer(player, 20);
            }
            if (i < boss.getIndex()) {
                if (boss[i]->getHp() <= 0) {
                    boss[i]->clear();
                    boss.deleteItem(i);
                }
                if (collision(player, boss[i]->getX(), boss[i]->getY(), boss[i]->getWidth(), boss[i]->getHeight())) {
                    boss[i]->BOSSMOB_vision(player, 4);
                    break;
                }

                boss[i]->BOSSMOB_vision(player, 4);
                boss[i]->WalkTimer(player, 20);
            }
            if (i < teleports.getIndex()) {
                if (teleports[i]->vision(player, 3)) {
                    level = teleports[i]->getLevel();
                    room = teleports[i]->getRoom();
                    setCursor(0, 30);
                    cout << "Level: " << level << " room: " << room;
                    teleports.deleteItem(i);
                    LevelDraw(level, room);
                }
            }
        }
        Sleep(1);
    }
    return 0;
}