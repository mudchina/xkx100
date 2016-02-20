// ROOM xuanbing.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "玄兵古洞");
	set("long", @LONG
这里是玄兵古洞洞口，里面传来阵阵的捶打声。似乎正在锻造着什
么。隐隐的透着一股萧杀的气息。
LONG );
	set("exits", ([
		"east" : "/d/xingxiu/nanjiang2",
		"enter" : __DIR__"xuanbing1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41200);
	set("coor/y", 8980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
