/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 14:38:10
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 21:57:56
 * @Description: 
 */
#include "game.h"
#include <unistd.h>
#include <pthread.h>

int main()
{

	#if 1
    pthread_t t1;
	pthread_mutex_t	mutex_lock1;
	//pthread_mutex_init(&mutex_lock, NULL);
	system("clear");
    Game g;
	g.mutex_lock = mutex_lock1;
	pthread_mutex_init(&(g.mutex_lock), NULL);
    //g.createCube();
	g.gameInit();
    pthread_create(&t1,NULL,listenKey,(void*)(&g));

    while(1)
    {
        fflush(stdout);
        usleep(SPEED);
        g.move(DOWN);
    }
	#endif
	#include <iostream>
	using namespace std;
	#if 0
	Game g;
	while(1);
	#endif
	

	return 0;
}




