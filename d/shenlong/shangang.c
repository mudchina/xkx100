// 山岗 /d/shenlong/shangang
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "山岗");
	set("long", @LONG
这是一个乱石岗，野草丛生，乱石成堆，显得很荒凉，石缝中有许
多小洞，四周是许多乱石。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"westdown"  : __DIR__"tiandi4",
		"northdown" : __DIR__"shulin1",
		"southwest" : __DIR__"shanqiu",
	]));
	set("objects", ([
		__DIR__"npc/mangshe" : 1,
	]));

	setup();
	replace_program(ROOM);
}

