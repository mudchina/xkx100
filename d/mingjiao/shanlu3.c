// Room: /d/mingjiao/shanlu3.c
// Date: Java 97/04/9

inherit ROOM;

void create()
{
	set("short", "悬天崖");
	set("long", @LONG
这里山路陡峭，仅有一人多宽，路左是峭壁高耸，路右紧临万丈深
渊，实在是一夫当关、万夫莫开的险要之处。继续上攀，就要到达明教
五行旗了。紧挨路右，天然生有一块巨石，高近三丈，名为“悬天石”，
常有侠客于上远观云海。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"northup"   : __DIR__"shanlu4",
		"up"        : __DIR__"xuantianshi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 810);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if ((random((int)me->query_skill("dodge")) <= 20) && dir=="up")
	{
		return notify_fail("你使劲儿一蹦，离石顶还有数丈远就掉了下来，摔的鼻青脸肿。\n");
	}
	if ((random((int)me->query_skill("dodge")) <= 35) && dir=="up")	
	{
		return notify_fail("你奋力一跃，却离石顶还有一丈多远，看来是白费力气。\n");
	}
	if ((random((int)me->query_skill("dodge")) <= 60) && dir=="up")	
	{
		return notify_fail("你纵身而起，离石顶只差一点点了，再加把劲。\n");
	}

	return ::valid_leave(me, dir);
}