// Room: /d/gaochang/dadian.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "高昌大殿");
	set("long", @LONG
这里就是传说中埋藏着无数宝藏高昌迷宫的大殿，四壁供的都是泥
塑木雕的佛像。大殿之上有一个大大的龙椅，大堂之上透着一股威严，
有一块大匾，上书：

                ****************
                *              * 
                *   文成武德   *
                *              *
                ****************

东西两面都是殿堂。
LONG
	);
	set("exits", ([
		"west" : __DIR__"wroom1",
		"east" : __DIR__"eroom1", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -36500);
	set("coor/y", 10050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}