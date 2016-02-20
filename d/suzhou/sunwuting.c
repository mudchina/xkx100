// Room: /d/suzhou/sunwuting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "孙武亭");
	set("long", @LONG
在真娘幕后的土丘上，有一座小亭子，名为孙武亭。相传春秋时，
兵家孙武曾在此训练两队宫女，由吴王的两个宠姬分别担任队长，由于
宠姬与宫女们不听军令，虽三令五申，仍置若罔闻，孙武遂下令，先斩
两姬于军前以整军纪。后人遂筑此亭。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"zhenniang",
	]));
	set("coor/x", 810);
	set("coor/y", -990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
