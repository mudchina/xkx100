// Room: /d/chengdu/xiaojie.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "小街");
	set("long", @LONG
这是一条青石板铺成的小街，路面非常干净。朝北边看，天气好的
话，还可以隐约看到风雨亭的一角。
LONG	);
	set("outdoor","chengdu");
	set("exits", ([
		"north"     : __DIR__"dongjie2",
		"southeast" : __DIR__"xiaojie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

