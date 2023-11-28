// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
// #include "../code_1/<HEADER FILE>.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include "test_helpers.hpp"

using namespace std;

class test_x : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}
	}


	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
			std::cout << "Total Grade is : " << (int)std::ceil(100*total_grade/max_grade) << std::endl;
		}
	}

	void add_points_to_grade(double points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after every TEST_F function
	void TearDown() override {
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
		}
	}
	
	static double total_grade;
	static double max_grade;
};

double test_x::total_grade = 0;
double test_x::max_grade = 100;



/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

TEST_F(test_x, TestInsert){
    
    
    string result;
    string expected;
       
    int len = 5;
    
    string commits[] = {"computer", "science", "fun", "difficult", "science"};
    int tabSize = 5;
    
    result = test_insert(commits, len, tabSize);
    
    expected = "0|| science(1,4)\n1|| \n2|| \n3|| \n4|| difficult(3)-->fun(2)-->computer(0)\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(6);

	int len1 = 5;
    string commits1[] = {"hydrogen", "carbon", "aluminum", "cobalt", "plutonium"};
    int tabSize1 = 5;
    
    result = test_insert(commits1, len1, tabSize1);
    
    expected = "0|| plutonium(4)\n1|| \n2|| aluminum(2)\n3|| \n4|| cobalt(3)-->carbon(1)-->hydrogen(0)\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(6);

}

TEST_F(test_x, TestSearch){
	string result;
	string expected;

	int len = 5;

	string commits[] = {"computer", "science", "fun", "difficult", "science"};

	result = test_search(commits, len, "computer", 5);

	expected = "Commit IDs with 'computer': 0\n";

	ASSERT_EQ(result, expected);
	add_points_to_grade(5);

	result = test_search(commits, len, "science", 5);
	
	expected = "Commit IDs with 'science': 1, 4\n";

	ASSERT_EQ(expected, result);
	add_points_to_grade(6);

	string commits1[] = {"hydrogen", "carbon", "carbon", "carbon", "mietnerium"};
	result = test_search(commits1, len, "carbon", 5);

	expected = "Commit IDs with 'carbon': 1, 2, 3\n";

	ASSERT_EQ(expected, result);
	add_points_to_grade(6);
}

TEST_F(test_x, TestAdd){ //note that this test uses files that have known directories, if the ./run_tests is moved then it won't work
	string result;
	string expected;

	string files[] = {"CMakeCache.txt", ".gitkeep", "../tests/test_helpers.cpp", "../tests/test_helpers.hpp", "../tests/test.cpp"};
	result = test_add(files, 5);
	expected = readFileIntoString("../tests/output/add_1.txt");

	ASSERT_EQ(result, expected);
	add_points_to_grade(6);

	string files1[] = {"CMakeCache.txt", ".gitkeep", "CMakeCache.txt", "../tests/test_helpers.cpp", "../tests/test.cpp"};
	result = test_add(files1, 5);
	expected = readFileIntoString("../tests/output/add_2.txt");

	ASSERT_EQ(result, expected);
	add_points_to_grade(6);

	string files2[] = {"asldkfjlaskjdf", ".gitkeep", "CMakeCache.txt", "../tests/test_helpers.cpp", "../tests/test.cpp"};
	result = test_add(files2, 5);
	expected = readFileIntoString("../tests/output/add_3.txt");

	ASSERT_EQ(result, expected);
	add_points_to_grade(6);
}

TEST_F(test_x, TestRM){
    string delmsg;
    string result;
    string addfiles[]= {"CMakeCache.txt", ".gitkeep", "../tests/test_helpers.cpp", "../tests/test_helpers.hpp", "../tests/test.cpp"};
    
	result = test_rm(addfiles, 5, ".gitkeep");
	delmsg = readFileIntoString("../tests/output/rm_1.txt");

	ASSERT_EQ(result, delmsg);
	add_points_to_grade(6);
	
	result = test_rm(addfiles, 5, "CMakeCache.txt");
    delmsg = readFileIntoString("../tests/output/rm_2.txt");

	ASSERT_EQ(result, delmsg);
	add_points_to_grade(6);

	result = test_rm(addfiles, 5, "../tests/test.cpp");
	delmsg = readFileIntoString("../tests/output/rm_3.txt");

	ASSERT_EQ(result, delmsg);
	add_points_to_grade(6);
}

TEST_F(test_x, TestCommit){
	string result;
	string expected;

	string files[] = {"CMakeCache.txt", ".gitkeep", "../tests/test_helpers.cpp", "../tests/test_helpers.hpp", "../tests/test.cpp"};
	result = test_commit(files, 5, "new commit message test");

	expected = readFileIntoString("../tests/output/commit_1.txt");

	ASSERT_EQ(result, expected); //create new asset
	add_points_to_grade(5);
}



TEST_F(test_x, TestMain){
	string result;
	string expected;

	result = exec("./run_app_1 ../tests/input/main_1.txt");
	expected = readFileIntoString("../tests/output/main_1.txt");

	ASSERT_EQ(result, expected);
	add_points_to_grade(15);

	result = exec("./run_app_1 ../tests/input/main_2.txt");
	expected = readFileIntoString("../tests/output/main_2.txt");

	ASSERT_EQ(result, expected);
	add_points_to_grade(15);
}