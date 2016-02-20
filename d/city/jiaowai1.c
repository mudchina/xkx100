// Room: /d/city/jiaowai1.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露夕光，沁
人心脾。真是好时光。偶有几对小男女结伴踏青，莺声丽影，嬉闹动人。
LONG );

	set("exits", ([
		"north" : __DIR__"dongmen",
		"south" : __DIR__"jiaowai2",
		"east"  : __DIR__"deshengshan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}