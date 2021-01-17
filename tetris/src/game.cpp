/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 14:20:43
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 22:24:02
 * @Description: 
 */
#include "game.h"
#include "rand.h"
#include<pthread.h>


int num = 0;
static int count = 0;
static int stop_flag;
static Rand r;
Game::Game()
{
    graph_ = NULL;
    x = 1;
    y = 7;
    CubePoint p;
	string name;
	cout << "please input name of player:" << endl;
	cin >> name;
	s_.setName(name);
	s_.printMessage();
	mark_ = GAME_RUN;
    memset((void*)panel_,0,PANEL_SIZE);
	memset((void*)cr_,0,PANEL_SIZE);
   for(int i = 0; i < 24; i++)
   {
        p.setLocate(i,0);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(i,16);
        p.setColor(BLUE);
        p.printPoint();
        panel_[i][0] = 1;
        panel_[i][16] = 1;
   }
   for(int i = 0; i < 17; i++)
   {
        p.setLocate(23,i);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(0,i);
        p.setColor(RED);
        p.printPoint();
        panel_[23][i] = 1;
        panel_[0][i] = 1;
   }
   /*测试面板值是否正常
   for(int i = 0; i < 24; i++)
   {
        for(int j = 0; j < 17; j++)
            cout << panel_[i][j] <<" ";
        cout << endl;
   }
	*/
   fflush(stdout);
}

Game::~Game()
{
	if( NULL != graph_ )
	{
		delete graph_;
		//graph_ = NULL;
	}

	if( NULL != nextGraph_ )
	{
		delete nextGraph_;
		//nextGraph_ = NULL;
	}
}
#if 1
GraphType Game::getShape()
{
	
	GraphType gt;
    switch(r.randNum(1,6))
    {
        case 1:gt = graphZ;break;
        case 2:gt = graphT;break;
        case 3:gt = graphO;break;
        case 4:gt = graphI;break;
        case 5:gt = graphL;break;
        default:
               cout<<"no this shape type"<<endl;
               gt = (GraphType)0;
               break;
    }
    return gt;
}
void Game::getColor()
{
    switch(r.randNum(1,9))
    {
        case 1:nextColor_ = BLACK;break;
        case 2:nextColor_ = RED;break;
        case 3:nextColor_ = GREEN;break;
        case 4:nextColor_ = YELLOW;break;
        case 5:nextColor_ = BLUE;break;
		case 6:nextColor_ = PURPLE;break;
		case 7:nextColor_ = DEEP_GREEN;break;
		case 8:nextColor_ = WHITE;break;
		
        default:
               cout<<"no this color"<<endl;
               nextColor_ = (Color)0;
               break;
    }	
}
bool Game::erasePanel()
{
    int i,j;
    int b[3][3] = {0};  //获取方块数组
    graph_->printG(CLEAR);
    memcpy(b,graph_->getArray(),CUBE_SIZE);
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            panel_[i + x][j + y] -= b[i][j];
			cr_[i][j] = CLEAR;
        }
    return true;
}
bool Game::recoverPanel()
{
    int i,j;
    int b[3][3] = {0};  //获取方块数组
    memcpy(b,graph_->getArray(),CUBE_SIZE);
    for(i = x; i < x + 3; i++)
        for(j = y; j < y + 3; j++)
        {
            panel_[i][j] += b[i-x][j-y];
			cr_[i][j] = color_;
        }
    return true;
}
bool Game::setPanel()
{
    int i,j;
    int b[3][3] = {0};  //获取方块数组
    graph_->getLocate(x,y);
    memcpy(b,graph_->getArray(),CUBE_SIZE);
    /*测试取到方块数组是否正常
    for(i = 0;i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            cout<<b[i][j]<< " ";
        cout<<endl;
    }
    */
    for(i = x; i < x + 3; i++)
        for(j = y; j < y + 3; j++)
        {
            panel_[i][j] += b[i-x][j-y];
            if(panel_[i][j] > 1)
            {
				s_.setScore(count);
				s_.printMessage();
				Cur cur;
				cur.saveCur();
				
				cur.moveCur(25,0);
                cout<<"game over"<<endl;
				cout << "total score is: " << s_.getScore() << endl;
                //加分数统计排行榜等
                system("stty icanon echo");
                exit(0);
            }
        }
    return true;
}
void Game::createCube()
{
    graph_ = nextGraph_;
    setPanel();
	color_ = nextColor_;
    graph_->printG(color_);
	nextGraph_ = new Context(getShape());
	getColor();
	nextGraph_->draw();
	nextGraph_->setLocate(1,7);
	printNextCube(nextGraph_);
    /*
   for(int i = 0; i < 24; i++)
   {
        for(int j = 0; j < 17; j++)
            cout << m_penal[i][j] <<" ";
        cout << endl;
   }
   */
}
void Game::move(Direction dir)
{
	if(mark_ != GAME_RUN)
		return;
    erasePanel();
	pthread_mutex_lock(&mutex_lock);
    switch(dir)
    {
        case DOWN:
            if(!isAttachBottom())
            {
                graph_->move(DOWN);
                setPanel();
                graph_->printG(color_);
            }
            else
            {
                recoverPanel();
                graph_->printG(color_);
                erase();
                stop();
            }
            break;
        case LEFT:
            if(!isAttachLeft())
            {
                graph_->move(LEFT);
                setPanel();
                graph_->printG(color_);
            }
            else
            {
                recoverPanel();
                graph_->printG(color_);
            }
                  
            break;
        case RIGHT:
            if(!isAttachRight())
            {
                graph_->move(RIGHT);
                setPanel();
                graph_->printG(color_);
            }
            else
            {
                recoverPanel();
                graph_->printG(color_);
            }
            break;
        default:
            break;
    }
pthread_mutex_unlock(&mutex_lock);	
}
void Game::roll()
{
    //取出方块的值，先放到一个数组中
    int i,j;
    int flag = 0;
    int b[3][3] = {0};  //获取方块数组
    int temp[3][3] = {0};
    graph_->getLocate(x,y);
    memcpy(b,graph_->getArray(),CUBE_SIZE);
    erasePanel();
    //旋转数组
	//graph_->roll();
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            temp[j][2-i] = b[i][j];
        }
    //判断旋转后是否会与面板重合
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if (temp[i][j] == 1 && panel_[x + i][y + j] == 1)  
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    //如果不重合则旋转方块，设置面板的值
    if(flag == 0)
    {
        graph_->roll();
    }
    setPanel();
    graph_->printG(color_);
}
void Game::stop()
{
    delete graph_;
	stop_flag = 1;
    createCube();
}
bool Game::isAttachBottom()
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //获取方块数组
    int flag = false;
    graph_->getLocate(cube_x,cube_y);
    memcpy(b,graph_->getArray(),CUBE_SIZE);
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
           if (b[i][j] == 1 && panel_[i + cube_x + 1][j + cube_y] == 1)
           {
                flag = true;
                break;
           }
        }
        if (flag == true)
            break;
    }
    return flag;
}
bool Game::isAttachLeft()
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //获取方块数组
    int flag = false;
    graph_->getLocate(cube_x,cube_y);
    memcpy(b,graph_->getArray(),CUBE_SIZE);
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
           if (b[i][j] == 1 && panel_[i + cube_x][j + cube_y - 1] == 1)
           {
                flag = true;
                break;
           }
        }
        if (flag == true)
            break;
    }
    return flag;
}
bool Game::isAttachRight()
{
    int i,j;
    int cube_x,cube_y;
    int b[3][3] = {0};  //获取方块数组
    int flag = false;
    graph_->getLocate(cube_x,cube_y);
    memcpy(b,graph_->getArray(),CUBE_SIZE);
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
           if (b[i][j] == 1 && panel_[i + cube_x][j + cube_y + 1] == 1)
           {
                flag = true;
                break;
           }
        }
        if (flag == true)
            break;
    }
    return flag;
}
void Game::erase()
{
   int i,j;
   int flag = 0;
   for(i = 22; i > 0; i--)
   {
        for(j = 1; j < 16; j++)
        {
            if(panel_[i][j] == 0)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
			//加分
			count++;
			s_.setScore(count);
			s_.printMessage();
            //该行上面的图形整体坐落
            down(i);
            i++;
        }
        flag = 0;
   }
}
void Game::down(int level)
{
    int i,j;
    int flag = 1;
    for(i = level; i > 1; i--)
        for(j = 1; j < 16; j++)
        {
            panel_[i][j] = panel_[i - 1][j];
        }
    //刷新面板
    CubePoint p;
    for(i = 1; i < 23; i++)
        for(j = 1; j < 16; j++)
        {
            if(panel_[i][j] == 1)
            {
                p.setLocate(i,j);
                //p.setColor(YELLOW);
				p.setColor(cr_[i][j]);
                p.printPoint();
            }
            if(panel_[i][j] == 0)
            {
                p.setLocate(i,j);
                p.setColor(CLEAR);
                p.printPoint();
            }
        }
}

void Game::printNextCube(Context* graph_)
{
	int x = 7;
	int y = 19;
	int i,j;
    Cur c;
    CubePoint p;   

	c.saveCur();
	c.moveCur(6,19);
	cout<<"next : ";
	c.resumeCur();

    int a[3][3] = {0};  //获取方块数组
    memcpy(a,graph_->getArray(),CUBE_SIZE);
    for(i = x; i < x+3; i++)
        for(j = y; j < y+3; j++)
        {       
			p.setLocate(i,j);
			p.setColor(CLEAR);
            p.printPoint();
            if(a[i - x][j - y] == 1)
            {

                p.setColor(nextColor_);
                p.printPoint();
            }
        }
}

void Game::printHelep()
{
   	Cur c;
	c.saveCur();
   	c.moveCur(10,19);
   	cout<<"a: go to left" << endl;
	c.resumeCur();
	c.saveCur();
   	c.moveCur(11,19);
   	cout<<"d: go to right" << endl;
	c.resumeCur();
	c.saveCur();
   	c.moveCur(12,19);
   	cout<<"w: roll cube" << endl;
	c.resumeCur();
	c.saveCur();
   	c.moveCur(13,19);
   	cout<<"s: go to down" << endl;
	c.resumeCur();
	c.saveCur();
   	c.moveCur(14,19);
   	cout<<"p: run or pause" << endl;
	c.resumeCur();
}

void Game::gameInit()
{
	printHelep();
	nextGraph_ = new Context(getShape());
	nextGraph_->draw();
	nextGraph_->setLocate(1,7);
	getColor(); //nextcolor
	createCube();
}

MARK Game::getMark()
{
	return mark_;
}

void Game::setMark( MARK mark )
{
	this->mark_ = mark;
}

void* listenKey(void *ptr)
{
	Game* ptrg = (Game*)ptr;
    char key;
    while(1)
    {
        system("stty -icanon -echo");
        key = getchar();
        system("stty icanon echo");
        switch(key)
        {
            case 'a':
                ptrg->move(LEFT);break;
            case 'd':
                ptrg->move(RIGHT);break;
            case 'w':
                ptrg->roll();break;
            case 's':
                //速降
                while(1)
                {
                    if(stop_flag == 1)
                    {
                        stop_flag = 0;
                        break;
                    }
                    ptrg->move(DOWN);
                }
                break;
            case 68:
                ptrg->move(LEFT);
                break;
            case 67:
                ptrg->move(RIGHT);
                break;
            case 65:
                ptrg->roll();
                break;
            case 66:
                while (1) {
                    if (stop_flag == 1) {
                        stop_flag = 0;
                        break;
                    }
                    ptrg->move(DOWN);
                }
                break;

            case 'p':
		if(GAME_RUN == ptrg->getMark())
			ptrg->setMark(GAME_PAUSE);
		else ptrg->setMark(GAME_RUN);
                break;

            default:
                break;
        }
    }
    
}
#endif