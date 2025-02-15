/*
//#include "../main.cpp"
#define CATCH_CONFIG_MAIN
#include "../AVL.h"
#include "catch.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

// Austin Hall
// 90207943

To check output(At the Project1 directory) :
g++ -std=c++14 -Werror -Wuninitialized -o build\test test-unit\test.cpp AVL.cpp && build\test -s
g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp AVL.cpp && build/test -s	



TEST_CASE("Invalid names and ufids", "[given]") {
    // Create an instance of AVLTree
    AVLTree avlTree;

    // Insert the five nodes with invalid names or UFIDs
    avlTree.insert("Invalid ufid", "1234567");  // 7 digit ufid
    avlTree.insert("Invalid ufid", "1234567a");  // non-digit ufid
    avlTree.insert("Invalid ufid", "");  // empty ufid
    avlTree.insert("", "12345678"); // empty name
    avlTree.insert("au5tin", "12345679"); // name with digit
    avlTree.insert("aust!n", "12345670"); // name with special character

    // Check if the insertions were unsuccessful
    REQUIRE(avlTree.inTree("Invalid ufid") == false);
    REQUIRE(avlTree.inTree("Invalid ufid") == false);
    REQUIRE(avlTree.inTree("Invalid ufid") == false);
    REQUIRE(avlTree.inTree("") == false);
    REQUIRE(avlTree.inTree("au5tin") == false);
    REQUIRE(avlTree.inTree("aust!n") == false);
}
TEST_CASE("Edge Cases", "[given]") {
    // Create an instance of AVLTree
    AVLTree avlTree;

    avlTree.insert("Arandon", "45674567");
    avlTree.insert("Brandon", "55674567");
    avlTree.insert("Crandon", "65674567");
    avlTree.insert("Drandon", "75674567");
    
    // Capture the output
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    // Commands
    avlTree.remove("Erandon"); // removing a node that doesn't exist
    avlTree.removeInorder(5); // removing a node that is greater than the number of nodes in the tree
    avlTree.removeInorder(-1); // removing a node with a negative number
    avlTree.insert("Erandon", "45674567"); // inserting a node with the same ufid

    std::cout.rdbuf(p_cout_streambuf); // restore

    // Check that the output is what you expect
    REQUIRE(oss.str() == "unsuccessful\nunsuccessful\nunsuccessful\nunsuccessful\n");

    // Check that the size of the tree is still 4
    REQUIRE(avlTree.size() == 4);
}

TEST_CASE("The Four Rotations", "[given]") {
    // Create an instance of AVLTree
    AVLTree avlTree1, avlTree2, avlTree3, avlTree4;

    // left left 
    avlTree1.insert("Austin", "30000000");
    avlTree1.insert("Bustin", "20000000");
    avlTree1.insert("Custin", "10000000");
   

    // Capture the output
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    
    // print in order then verify order
    avlTree1.printInorder();
    std::cout.rdbuf(p_cout_streambuf); // restore

    REQUIRE(oss.str() == "Custin, Bustin, Austin\n");

   
    // left right 
    avlTree2.insert("Austin", "30000000");
    avlTree2.insert("Bustin", "20000000");
    avlTree2.insert("Custin", "21000000");

    // Capture the output
    std::ostringstream oss2;
    std::streambuf* p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());

    avlTree2.printInorder();
    std::cout.rdbuf(p_cout_streambuf2); // restore

    REQUIRE(oss2.str() == "Bustin, Custin, Austin\n");

   
    // right right 
    avlTree3.insert("Austin", "10000000");
    avlTree3.insert("Bustin", "20000000");
    avlTree3.insert("Custin", "30000000");

    // Capture the output
    std::ostringstream oss3;
    std::streambuf* p_cout_streambuf3 = std::cout.rdbuf();
    std::cout.rdbuf(oss3.rdbuf());

    avlTree3.printInorder();
    std::cout.rdbuf(p_cout_streambuf3); // restore

    REQUIRE(oss3.str() == "Austin, Bustin, Custin\n");
   
    // right left 
    avlTree4.insert("Austin", "10000000");
    avlTree4.insert("Bustin", "20000000");
    avlTree4.insert("Custin", "11000000");

    // Capture the output
    std::ostringstream oss4;
    std::streambuf* p_cout_streambuf4 = std::cout.rdbuf();
    std::cout.rdbuf(oss4.rdbuf());

    avlTree4.printInorder();
    std::cout.rdbuf(p_cout_streambuf4); // restore

    REQUIRE(oss4.str() == "Austin, Custin, Bustin\n");

}

TEST_CASE("Deletion Cases", "[given]") {
    // 2 children
    AVLTree avlTree;
    avlTree.insert("Austin", "30000000");
    avlTree.insert("Bustin", "20000000");
    avlTree.insert("Custin", "10000000");
    avlTree.remove("20000000");

    // capture output
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    avlTree.printInorder();
    std::cout.rdbuf(p_cout_streambuf); // restore

    REQUIRE(oss.str() == "Custin, Austin\n");


    // left child
    AVLTree avlTree2;
    avlTree2.insert("Austin", "30000000");
    avlTree2.insert("Bustin", "20000000");
    avlTree2.insert("Custin", "11000000");
    avlTree2.insert("Dustin", "10000000");
    avlTree2.remove("11000000");

    // capture output
    std::ostringstream oss2;
    std::streambuf* p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());

    avlTree2.printInorder();
    std::cout.rdbuf(p_cout_streambuf2); // restore

    REQUIRE(oss2.str() == "Dustin, Bustin, Austin\n");

    // right child
    AVLTree avlTree3;
    avlTree3.insert("Austin", "30000000");
    avlTree3.insert("Bustin", "20000000");
    avlTree3.insert("Custin", "31000000");
    avlTree3.insert("Dustin", "23000000");
    avlTree3.remove("20000000");

    // capture output
    std::ostringstream oss3;
    std::streambuf* p_cout_streambuf3 = std::cout.rdbuf();
    std::cout.rdbuf(oss3.rdbuf());

    avlTree3.printInorder();
    std::cout.rdbuf(p_cout_streambuf3); // restore

    REQUIRE(oss3.str() == "Dustin, Austin, Custin\n");

}
#include <vector>
#include <string>
TEST_CASE("100 Nodes", "[given]") {
    // Create an instance of AVLTree
    AVLTree avlTree;
    std::vector<std::string> ufidList;

    // Initialize random seed
    srand(time(0));

    // Create 100 nodes with random 8-digit UFIDs
    int i = 0;
    while (i < 100) {
        // Generate random 8-digit UFID
        std::string ufid = std::to_string(rand() % 90000000 + 10000000);
        
        if (!avlTree.inTree(ufid)) {
            avlTree.insert("Node", ufid);
            i++;
            if (i % 10 == 0)
                ufidList.push_back(ufid);
        }
    }

    // Check that the size of the tree is 100
    REQUIRE(avlTree.size() == 100);

    // Remove 10 nodes Inorder
    for (int i = 0; i < 10; i++) {
        avlTree.remove(ufidList[i]);
    }

    // Check that the size of the tree is 90
    REQUIRE(avlTree.size() == 90);
   
}
*/


