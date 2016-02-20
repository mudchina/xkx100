// Room: /lingzhou/huangyangtan.c
// Java Sep.23 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "黄羊滩");
	set("long", @LONG
这里就是灵州西南著名的黄羊滩，本来是黄河边的一大片水泽盐
碱地，黄河水泛滥后退去形成了一大片低洼水滩，上面水草丰盛，春
秋两季吸引了大批塞北的野生黄羊到这里来饮水嬉戏，休养生息，成
为塞上一大景观。
LONG	);
	set("exits", ([
		"north"     : __DIR__"nanmen",
		"southwest" : __DIR__"xiaoba",
	]));
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/lamb": 1,
	]));
	set("outdoors", "lingzhou");
	set("coor/x", -17960);
	set("coor/y", 32040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}