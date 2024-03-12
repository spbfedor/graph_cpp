#include "socialnetwork.h"

SocialNetwork::Human &SocialNetwork::Human::operator=(const Human &other) {
    strcpy(name, other.name);
    user_id = other.user_id;
    return *this;
}

bool SocialNetwork::Human::operator==(const Human &other) {
    return other.user_id == this->user_id;
}

void SocialNetwork::addnewMan(const Name name) {
    Human man = findManByName(name);
    if(man.user_id >= 0) {
        return;
    }
    int i = 0;
    for(; i < SIZE; ++i) {
        if(!busyids[i]) {
            break;
        }
    }
    busyids[i] = true;
    people.add(Human(name, i));
}

void SocialNetwork::delMan(const Name name) {
    Human man = findManByName(name);
    if(man.user_id < 0) {
        return;
    }
    busyids[man.user_id] = false;
    int index = people.find(man);
    for(int i = 0; i < people.size(); ++i) {
        friend_matrix[i][man.user_id] = 0;
        friend_matrix[man.user_id][i] = 0;
    }
    people.del(index);
}

void SocialNetwork::addFriendship(const Name name_1, const Name name_2) {
    Human man_1 = findManByName(name_1);
    Human man_2 = findManByName(name_2);
    if(man_1.user_id < 0 || man_2.user_id < 0) {
        return;
    }
    friend_matrix[man_1.user_id][man_2.user_id] = 1;
    friend_matrix[man_2.user_id][man_1.user_id] = 1;
}

bool SocialNetwork::are_friends(const Human &man_1, const Human &man_2) {
    return friend_matrix[man_1.user_id][man_2.user_id] == 1;
}

bool SocialNetwork::man_exists_with_id(int man_id) {
    for(int i = 0; i < people.size(); ++i) {
        if(people[i].user_id == man_id) {
            return true;
        }
    }
    return false;
}

SocialNetwork::Human SocialNetwork::findManByName(const Name name) {
    for(int i = 0; i < people.size(); ++i) {
        if(!strcmp(name, people[i].name)) {
            return people[i];
        }
    }
    return Human();
}

void SocialNetwork::showThreeHandshakes() {
    int wavesLevels[SIZE]; // массив очереди
    for(int i = 0; i < SIZE; ++i) { // заполняем массив значением -1
        wavesLevels[i] = -1;
    }
    wavesLevels[0] = 0;

    StaticArray<int> queue;
    queue.add(0);

    while (queue.size()) {
        int currentManIndex = queue[0];
        queue.del(0);
        for(int i = 0; i < people.size(); ++i) {
            if(are_friends(people[currentManIndex], people[i]) && wavesLevels[i] == -1) {
                wavesLevels[i] = wavesLevels[currentManIndex] + 1;
                queue.add(i);
            }
        }
    }
    for(int i = 0; i < people.size(); ++i) {
        for(int j = i + 1; j < people.size(); ++j) {
            if(abs(wavesLevels[i] - wavesLevels[j]) <= 3) {
                std::cout << people[i].name << " " << people[j].name << std::endl;
            }
        }
    }
    
}