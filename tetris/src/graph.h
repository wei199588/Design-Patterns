/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 12:50:28
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 15:04:37
 * @Description: 
 */
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cubePoint.h"
using namespace std;

enum Direction{DOWN, LEFT, RIGHT};
enum GraphType{graphZ = 1, graphT, graphO, graphI, graphL};
class Graph
{
public:
	Graph()
	{
		x= 0;
		y = 0;
		for(int j = 0; j < 3; j++)
		{
			for(int i = 0; i < 3; i++)
				form[i][j] = 0;
		}		
	}
	int move(Direction dir);
    virtual int roll();
    virtual void draw(){}
    void setLocate(int a,int b){x = a;y = b;}
    void getLocate(int& a,int& b){a = x;b = y;}
    void printG(int color);
    //获取数组首地址
    void* getArray(){return (void*)form;}

protected:
	int x;
	int y;
	int form[3][3];
};

class Zgraph : public Graph{
public:
    void draw(){
        form[0][0] = 1;
        form[0][1] = 1;
        form[0][2] = 0;
        form[1][0] = 0;
        form[1][1] = 1;
        form[1][2] = 1;
        form[2][0] = 0;
        form[2][1] = 0;
        form[2][2] = 0;
    }
};

class Tgraph : public Graph{
public:
    void draw(){
        form[0][0] = 1;
        form[0][1] = 1;
        form[0][2] = 1;
        form[1][0] = 0;
        form[1][1] = 1;
        form[1][2] = 0;
        form[2][0] = 0;
        form[2][1] = 0;
        form[2][2] = 0;
    }
};

class Ograph : public Graph{
public:
    void draw(){
        form[0][0] = 1;
        form[0][1] = 1;
        form[0][2] = 0;
        form[1][0] = 1;
        form[1][1] = 1;
        form[1][2] = 0;
        form[2][0] = 0;
        form[2][1] = 0;
        form[2][2] = 0;
    }
    virtual int roll(){};
};

class Igraph : public Graph{
public:
    void draw(){
        form[0][0] = 0;
        form[0][1] = 1;
        form[0][2] = 0;
        form[1][0] = 0;
        form[1][1] = 1;
        form[1][2] = 0;
        form[2][0] = 0;
        form[2][1] = 1;
        form[2][2] = 0;
    }
};

class Lgraph : public Graph{
public:
    void draw(){
        form[0][0] = 0;
        form[0][1] = 1;
        form[0][2] = 0;
        form[1][0] = 0;
        form[1][1] = 1;
        form[1][2] = 0;
        form[2][0] = 0;
        form[2][1] = 1;
        form[2][2] = 1;
    }
};

class Context
{
public:
	Context(GraphType gt)
	{
		switch (gt)
		{
		case graphZ:
			graph = new Zgraph();
			break;
		case graphT:
			graph = new Tgraph();
			break;
		case graphO:
			graph = new Ograph();
			break;
		case graphI:
			graph = new Igraph();
			break;
		case graphL:
			graph = new Lgraph();
			break;
		default:
			break;
		}
	}
	~Context()
	{
		delete graph;
	}
	
	int move(Direction dir){return graph->move(dir);}
    int roll(){return graph->roll();}
    void draw(){graph->draw();}
    void setLocate(int a,int b){graph->setLocate(a,b);}
    void getLocate(int &a,int &b){graph->getLocate(a,b);}
    void* getArray(){graph->getArray();}
    void printG(int color){graph->printG(color);}

private:
	Graph* graph;
};
#endif
