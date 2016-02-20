// Room: /d/nanshaolin/gulou1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓楼一层");
	set("long", @LONG
这里是塔楼的底层，一缕缕阳光从墙上的花砖缝隙里透射进来，在
青砖地上投下别致的光影，如同一格格棋盘相似。往上看，长长的木楼
梯盘绕而上，似乎永无尽头。墙角，梯级都相当洁净，看来经常有僧人
打扫。
LONG );
	set("exits", ([
		"up"  : __DIR__"gulou2",
		"out" : __DIR__"gulou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



