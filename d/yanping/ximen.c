// Room: /d/yanping/ximen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "西门");
	set("long", @LONG
西门外便是群山了。极目西望，大溪东来，群峰苍茫。西门是通往
赣南湘南的要道，青砖城墙上挂着一些告示和海捕文书。延平府向来清
明，盖历任知府多为理学门生故也。
LONG );
	set("exits", ([
		"east"      : __DIR__"road3",
		"north"     : __DIR__"sixianci",
		"southwest" : __DIR__"gudao4",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
