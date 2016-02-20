//ROOM xiaodao2.c

inherit ROOM;

void create()
{
	set("short", "小道");
	set("long",@LONG
一条小道蜿延曲折地通向远方, 两旁是郁郁葱葱的树林，微风吹过，
树叶发出奚索的声音. 
LONG );
	set("outdoors", "lingjiu");
	set("exits", ([
		"north" : __DIR__"men3",
		"south" : __DIR__"xiaodao1",
	]));
	set("objects",([
		"/d/baituo/npc/cungu" : 2,
	]));
	set("coor/x", -51000);
	set("coor/y", 30170);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}