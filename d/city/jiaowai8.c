// Room: /d/city/jiaowai8.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露夕光，沁
人心脾。呼朋唤友开怀欢乐正其时。
LONG );
	set("exits", ([
		"south" : __DIR__"jiaowai7",
		"west"  : __DIR__"jiaowai9",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/chuanshanjia" : random(2),
	]));
	set("outdoors", "yangzhoue");
	set("coor/x", 40);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}