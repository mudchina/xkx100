//jingshifang.c

inherit ROOM;

void create()
{
	set("short", "敬事房");
	set("long", @LONG
这是宫内的监办处, 是宫中太监的管理机构, 太监总管都在此地.
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"qianqinggong",
	]));
	set("objects", ([
		__DIR__"npc/hai": 1,
		__DIR__"npc/xiaoguizi": 1,
	]));
	set("coor/x", -210);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}