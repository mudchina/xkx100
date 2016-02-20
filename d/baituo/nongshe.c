// Room: /d/baituo/nongshe.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "农舍");
	set("long", @LONG
这里是一间小农舍，家具很新。门边挂着长庆对联，屋檐下挂着一
串串辣椒。屋内壁上挂着犁和猎枪，看来主人比较富裕。
LONG );
	set("exits", ([
		"west" : __DIR__"guangchang",
	]));
	set("objects",([
		__DIR__"npc/woman" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
