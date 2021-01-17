/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 14:11:41
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 19:55:23
 * @Description: 
 */
#ifndef GAME_H
#define GAME_H
#include "graph.h"
#include  "string.h"
#include "score.h"
//#include <unistd.h>
#define SPEED 500000
#define PANEL_SIZE (17*24*sizeof(int))
#define CUBE_SIZE (3*3*sizeof(int))


enum MARK{
	GAME_STOP = -1,
	GAME_PAUSE = 0,
	GAME_RUN = 1
};

class Game
{
private:
    int panel_[24][17];
	Color cr_[24][17];
	Color color_;
	Color nextColor_;
    Context* graph_;
	Context* nextGraph_;
	MARK mark_;
	Score s_;
    int x;
    int y;//当前方块的位置，方块移动或者旋转成功后才可以设置这个值
private:
    //恢复设置（方块会探索下一个位置是否合法，不合法需恢复面板）
    bool recoverPanel();
    //是否着陆(是否碰到下边)
    bool isAttachBottom();
    //是否碰到左边
    bool isAttachLeft();
    //是否碰到右边
    bool isAttachRight();
    //随机获取方块形状
    GraphType getShape();
	//随机获取方块颜色
	void getColor();
    //用方块数组给面板数组赋值
    bool setPanel();
    //方块动过后要把遗留面板信息擦除
    bool erasePanel();
public:
	pthread_mutex_t	mutex_lock;
    Game();
	~Game();
    //随机创建方块的方法
    void createCube();
    //移动的方法,移动的过程中对penal_的改变
	void move(Direction dir);
    //旋转的方法。。。
    void roll();
    //方块停止
    void stop();
    //擦除满行
    void erase();
    //擦除完上面的图形整块坠落
    void down(int level);
	
	void printNextCube(Context* graph_);
	void gameInit();
	
	MARK getMark();
	void setMark(MARK mark);
	void printHelep();
};
void* listenKey(void *ptr);
#endif
