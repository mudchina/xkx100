// Room: /d/chengdu/shuijing.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "水井");
	set("long", @LONG
有一眼清澈见底的水井，井旁搭着小土房。有几个妇人在这里边洗
衣，一边说说笑笑，还有个老人，挑着溜满的两桶清水，颤颤悠悠地朝
外走去。你可以在这喝口水。
LONG	);
	set("resource/water", 1);
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"dongjie3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

