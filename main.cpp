#include "staticarray.h"
#include "socialnetwork.h"
#include "socialnetwork.cpp"
#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    SocialNetwork sn;
    sn.addnewMan("fedor");
    sn.addnewMan("maxim");
    sn.addnewMan("anna");
    sn.addnewMan("igor");
    sn.addnewMan("vetal");
    sn.addnewMan("albina");
    sn.addnewMan("geka");
    sn.addFriendship("fedor", "katy");
    sn.addFriendship("katy", "vetal");
    sn.addFriendship("vetal", "albina");
    sn.addFriendship("albina", "anna");
    sn.addFriendship("albina", "igor");
    sn.addFriendship("igor", "geka");
    sn.addFriendship("maxim", "albina");
    sn.showThreeHandshakes();
    sn.delMan("katy");
    std::cout << std::endl;
    sn.showThreeHandshakes();
    return 0;
}