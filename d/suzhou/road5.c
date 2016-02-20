// Room: /d/suzhou/road5.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "湖畔大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。北面就是苏州城了。西南边岸边，波光粼闪，白帆点缀，便是
周遭五百里的太湖了。湖面绿波上漂着一叶叶的小舟, 一阵阵悦耳的小
曲儿随着湖上的轻风不时飘入你的耳中。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"road6",
		"southwest" : "/d/yanziwu/hupan",
	]));
	set("coor/x", 850);
	set("coor/y", -1130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
