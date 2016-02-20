// Room: /city/mingren.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
string look_shu();

void create()
{
	set("short", "名人堂");
	set("long", @LONG
这里就是侠客行一百的名人堂。在这里供奉的有大侠，也有魔头，
也有不是大侠不是魔头的玩家。无论是哪一位，都曾冠绝一时，都有一
个长长而惊心动魄的故事，每一个故事都曾很深远地影响了一代甚至两
三代玩家。
    虽然他们都曾经轰轰烈烈掀起满江湖的风雨，如今，他们再也不会
在江湖出现了。他们都已经退出江湖，但他们的侠影魔踪很长时间以后
仍是一个传说。
LONG );

	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"wumiao2",
	]));
	set("objects", ([
		__DIR__"player/abab": 1,
		__DIR__"player/automan": 1,
		__DIR__"player/cnba": 1,
		__DIR__"player/eagleg": 1,
		__DIR__"player/fall": 1,
		__DIR__"player/geng": 1,
		__DIR__"player/laughing": 1,
		__DIR__"player/luoyz": 1,
		__DIR__"player/news": 1,
		__DIR__"player/qinqin": 1,
		__DIR__"player/rewj":1,
		__DIR__"player/shh": 1,
		__DIR__"player/top": 1,
		__DIR__"player/wuqing": 1,
		__DIR__"player/wuxiangxinmo": 1,
		__DIR__"player/xem": 1,
		__DIR__"player/xxqqf": 1,
		__DIR__"player/saite": 1,
		__DIR__"player/noodle": 1,	
	]));
	set("coor/x", 0);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}
