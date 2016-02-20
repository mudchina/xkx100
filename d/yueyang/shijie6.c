// Room: /d/yueyang/shijie6.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "青石阶");
	set("long", @LONG
这是酒香亭傍的石阶，这里往南，就是悬崖。北面是酒香亭。悬崖
下，有龙虎猴三洞，崖的高处，有一座石台。每年的丐帮君山大会，都
是在那台上举行。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"jiuxiangting",
		"westup" : __DIR__"xuanyuantai",
	]));
	set("coor/x", -1780);
	set("coor/y", 2270);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
