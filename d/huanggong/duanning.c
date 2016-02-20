// Room: /d/huanggong/duangning.c

inherit ROOM;

void create()
{
	set("short", "端凝殿");
	set("long", @LONG
这是皇上贮存冠袍带履和轿舆的端凝殿.
LONG
	);
	set("exits", ([
		"west" : __DIR__"qianqinggong",
	]));
	set("objects", ([
		__DIR__"npc/wenyoudao" :1,
	]));
	set("coor/x", -190);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}