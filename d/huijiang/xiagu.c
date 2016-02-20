// Room: /d/huijiang/xiagu.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","峡谷");
	set("long",@LONG
这里是一道峡谷，两旁石壁峨然笔立，有如用刀削成，抬头望天，
只觉天色又蓝又亮，宛如潜在海底仰望一般。峡内岩石全系深黑，乌光
发亮。道路弯来弯去，异常曲折。
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"southeast" : __DIR__"caoyuan6",
		"north"     : __DIR__"damen",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/yang-chengxie" : 1,
	]));
	set("coor/x", -50060);
	set("coor/y", 9130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
