/*#include "../interquartile_range.h"
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <random>


	To check output (At the interquartile_range directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test


TEST_CASE("Function: IQR 1", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "[given]") {
	std::vector<int> v = {1, 2, 3, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// large numbers
TEST_CASE("Function: IQR 6", "[given]") {
	std::vector<int> v = {1, 2, 3, 456235, 58964131, 68315656, 1648646313};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 68315654.00);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

// large list
TEST_CASE("Function: IQR 7", "[given]") {
	std::vector<int> v = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99, };
	for (int i = 0; i < 1000; i++) {
		v.push_back(rand() % 500);
	}
	sort(v.begin(), v.end());

	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 50.00);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

// negative numbers
TEST_CASE("Function: IQR 8", "[given]") {
	std::vector<int> v = { -1, -2, -3, -456235, -58964131, -68315656, -1648646313 };
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 68315654.00);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

//empty set
TEST_CASE("Function: IQR 9", "[given]") {
	std::vector<int> v = {};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 0.00);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

// wrong input
TEST_CASE("Function: IQR 10", "[given]") {
	std::vector<char> v = {'d', 'f', 'g', 'h'};
	Node* head = nullptr;
	for (int i : v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 0.00);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}*/

 /*TEST_CASE("Function: IQR 3", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == ?);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
} */

 /*TEST_CASE("Function: IQR 4", "[output_hidden]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8, 9, 10};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == ?);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
} */

/* TEST_CASE("Function: IQR 5", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556, 137576};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == ?);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
} */

