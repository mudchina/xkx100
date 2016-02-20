// ROOM lianbangshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "铸棒院");
	set("long", @LONG
这里是玄兵古洞的打造的地方。处在成都丐帮分舵的小院里。一个
粗壮的汉子守着一个烈焰腾腾的大铁炉，拿着一个大铁锤不停地敲打着
什么。
LONG );
	set("exits", ([
		"south" : "/d/chengdu/ruin1",
	]));
	set("objects", ([
		__DIR__"npc/shibang" :1,
	]));
	set("coor/x", -8070);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
