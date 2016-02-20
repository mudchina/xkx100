// Room: /d/fuzhou/biaojuzf.c
// Date: may.12 1998 Java

inherit ROOM;

void create()
{
	set("short", "账房");
	set("long", @LONG
这里是福威镖局的账房，地上铺着大红地毯，壁上字画高悬。上首
一张红木交椅，上坐一个老先生。一古木书案横于椅前，上面整齐的堆
着一卷卷镖局押镖的货票。
LONG );
	set("no_fight", 1);
	set("exits", ([
		"west"   : __DIR__"biaojuzt",
		"south"  : __DIR__"biaojuhc",
	]));
	set("objects", ([
		__DIR__"npc/huang" : 1,
	]));
	set("coor/x", 1831);
	set("coor/y", -6297);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
