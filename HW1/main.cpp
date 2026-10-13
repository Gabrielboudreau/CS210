#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== My scene ==" << std::endl;
    std::unique_ptr<List<Player>> players = makeList<Player>();
    players->addFront(new Player(1, "Gabe"));
    players->addFront(new Player(2, "Nic"));
    players->addFront(new Player(3, "Elliot"));
    std::cout << "The first table forms:" << std::endl;
    players->print();

    std::cout << "Aiden joins!" << std::endl;
    players->addAnywhere(1, new Player(4, "Aiden"));
    players->print();

    std::cout << "A Reverse card is played by Gabe!:" << std::endl;
    players->reverse();
    players->print();

    std::cout << "Nic is out and leaves the table:" << std::endl;
    players->deleteAnywhere(2);
    players->print();

    std::unique_ptr<List<Player>> secondTable = makeList<Player>();
    secondTable->addFront(new Player(5, "Landon"));
    secondTable->addFront(new Player(6, "Alex"));
    std::cout << "A second table joins in:" << std::endl;
    secondTable->print();
    std::cout << "The tables combine!" << std::endl;
    players->concat(secondTable.get());
    players->print();
    std::cout << "Second table after ownership transfers (empty):" << std::endl;
    secondTable->print();
    return 0;
}
