// Room: /d/quanzhou/xuetang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "学堂");
	set("long", @LONG
这是城里的一所学堂，城中的子弟便在此上课。学堂里的柜子里摆
满了书籍。教书先生便是响誉泉州的欧阳詹先生。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"guitangxiang",
	]));
	set("objects", ([
		__DIR__"npc/ouyangzhan" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
