#pragma once

#include "staticarray.h"
#include <iostream>

#define NL 30

typedef char Name[NL];

class SocialNetwork {
    public:
        struct Human {
            public:
                Human() : user_id(-1) {};
                Human(const Name _name, int _user_id) : user_id(_user_id) {
                    strcpy(name, _name);
                }
                // Конструктор копирования
                Human(const Human &other) {
                    strcpy(name, other.name);
                    user_id = other.user_id;
                }

                Human &operator =(const Human &other);
                bool operator== (const Human &other);

                Name name;

                friend class SocialNetwork;
            private:
                int user_id;
        };

        SocialNetwork() {
            for(int i = 0; i < SIZE; ++i) {
                for(int j = 0; j < SIZE; ++j) {
                    friend_matrix[i][j] = 0;
                }
            }
            for(int i = 0; i < SIZE; ++i) {
                busyids.add(false);
            }
        }
        // добавить нового юзера
        void addnewMan(const Name name);
        // удалить юзера
        void delMan(const Name name);
        // установить дружбу между юзерами
        void addFriendship(const Name name_1, const Name name_2);
        // алгоритм поиска знакомых по 3 рукопожатиям
        void showThreeHandshakes();
    private:
        // проверка существования рукопожатия(ребро)
        bool are_friends(const Human &man_1, const Human &man_2);
        bool man_exists_with_id(int man_id);
        // поиск юзера по имени в контенйнере
        Human findManByName(const Name name);

        int friend_matrix[SIZE][SIZE];
        StaticArray<Human> people;
        StaticArray<bool> busyids;
};