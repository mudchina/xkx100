// Room: /heizhao/dongxiang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "东厢房");
	set("long", @LONG
这里是一灯大师的弟子们休息的地方。靠东窗户下安放着一排
矮榻上，整整齐齐摆叠着四套铺盖，窗台上一尘不染。窗外群山点
点，雾海生灭，流云往返。在此一宿，俗念顿消。门边的洗漱用具
也收拾得很干净，青砖地面想来也是天天打扫，绝无点尘。
LONG );
	set("no_clean_up", 0);
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
	set("exits", ([
		"west"       : __DIR__"chanyuan",
	]));
	set("coor/x", -5010);
	set("coor/y", -1200);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}