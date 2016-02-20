// Room: /d/yueyang/shijie2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条青石阶，连接山上的朗吟亭和山下的二妃墓。石阶两边茶
树连绵，竹响随人，真是个清幽所在。远望洞庭，湖水簇拥君山，白浪
抱青山，好一片风光。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"westup"    : __DIR__"langyinting",
		"northeast" : __DIR__"erfeimu",
		"southwest" : __DIR__"xiaolu3",
	]));
	set("coor/x", -1680);
	set("coor/y", 2290);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
