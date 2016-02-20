// Room: /wuliang/shanlu1.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条通向深山的小路。两边都是茂密的长草和树林。偶尔有
小鸟飞过。林间时而传出一阵野兽的嘶嚎或呦呦的鹿鸣。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : "/d/dali/shanlu4",
		"westup"   : __DIR__"shanlu2",
	]));
	set("coor/x", -70000);
	set("coor/y", -80000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}