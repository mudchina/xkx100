// liufuwest.c
// Date: Nov.1997 by Venus

#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "西厢房");
	set("long", @LONG
这儿是西厢房，这儿整理得干干净净，窗外露出点绿绿的枝叶，家
具上一尘不染，地上铺着很大块的青砖，一点灰尘也不沾。刘府的小孩
们不知在这里悄悄说着什么。
LONG);
	set("exits", ([
	    "east"   : __DIR__"liufudating",
	]));
	set("objects", ([
		__DIR__"npc/liujing" : 1,
		__DIR__"npc/liuqin" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -410);
	set("coor/y", -1170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
