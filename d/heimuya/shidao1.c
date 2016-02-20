// Room: /d/heimuya/shidao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "石道");
	set("long", @LONG
一路往北行，中间仅有一道宽约五尺的石道，两边石壁如墙，一路
上都有日月教徒模样的人物在走动，对往来的路人都严密监视。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "east" : __DIR__"guang",
	    "north" : __DIR__"shidao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3050);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}