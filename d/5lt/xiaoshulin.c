// Room: /d/5lt/xiaoshulin.c

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这是路边一片小松树林，面积算不上大。林中有块开阔地，习武的
村民们经常到这里来切磋武艺。
LONG );
	set("exits", ([
		"north" : __DIR__"eroad2",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -130);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}