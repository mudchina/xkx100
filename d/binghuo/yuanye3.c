// Room: /binghuo/yuanye2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "原野");
	set("long", @LONG
这里是一片空旷的原野。你走得口干舌燥，遍身大汗，但见身旁
已无一株树木花草，只余光秃秃、黄焦焦的岩石。火山口在北面还远
着呢。
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"south"  : __DIR__"yuanye2",
	]));
	set("objects", ([
		"/d/emei/obj/liuhuang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

