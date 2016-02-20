// Room: /d/huijiang/goldroom.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "储藏室");
	set("long",@LONG
这是一间小屋子，地上干干净净，纤尘不染。南边靠墙角的地方放
着几个箱子，屋子两壁厢点满了粗如儿臂的红烛，照得四下如同白昼一
般。
LONG );
	set("exits", ([
		"east" : __DIR__"zongduo",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/xu-tianhong" : 1,
		__DIR__"obj/box" : 1,
	]));	
	set("coor/x", -50080);
	set("coor/y", 9150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
