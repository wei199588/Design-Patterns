/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 16:18:51
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 22:09:25
 * @Description: 
 */
#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <string>
using namespace std;

class Score{
private:
    string player_;
    int score_;
	

public:
    Score(){player_ = "stand";score_ = 0;};
    void setName(string name){player_ = name;};
    void setScore(int score){score_ = score;};
	int getScore(){return score_;}

    void printMessage();
};

#endif