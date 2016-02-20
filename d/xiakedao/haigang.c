// Room: /d/xiakedao/xkroad5.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "渔港");
	set("long", @LONG
这里是个小小渔港。南面海面漂浮着几艘小船，抬眼望，海天相
连，无边无际。海鸥掠过浪尖，悠悠翩然。
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"east"    : __DIR__"xkroad4",
	]));
	set("objects", ([
		__DIR__"npc/shizhe" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}