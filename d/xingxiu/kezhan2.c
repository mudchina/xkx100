// Room: /d/xingxiu/kezhan2.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "客栈二楼");
	set("long", @LONG
这里是伊犁城最大客栈的二楼，楼下人声沸腾，不时飘上来一阵阵香喷
喷的烤羊肉味。你如果累了可以在床上舒舒服服地睡一觉。
LONG);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	     "down" : __DIR__"kezhan",
	]));
	set("objects", ([
		__DIR__"npc/yin": 1,
	]));
	set("coor/x", -39000);
	set("coor/y", 13100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
