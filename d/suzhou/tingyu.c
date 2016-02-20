// Room: /d/suzhou/tingyu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "听雨轩");
	set("long", @LONG
听雨轩是苏州城内的一处唯一的一家书店了。这里有着各种各样的
书籍，什么小说啦、风光旅游啦、手艺制作啦、基本武功啦，等等等等。
只须花几两银子就可买到你想要的书。
LONG );
//	set("outdoors", "suzhou");
	set("exits", ([
		"west"  : __DIR__"nandajie2",
	]));
	set("objects", ([
		__DIR__"npc/bookboss" : 1,
	]));
	set("coor/x", 860);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
