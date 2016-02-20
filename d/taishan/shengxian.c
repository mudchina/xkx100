// Room: /d/taishan/shenxian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "升仙坊");
	set("long", @LONG
这里是十八盘的中间，从这里直上南天门的一段就是紧十八盘了。
由此刻攀石而上，后面的人可以看到前面的人的鞋底，前面的人回头则
可见到后面的人的发顶。在这里一般人每走十来步便要稍一休息。
LONG );
	set("exits", ([
		"northup"   : __DIR__"jin18",
		"southdown" : __DIR__"jinman18",
	]));
	set("objects", ([
		__DIR__"npc/jianchu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 750);
	set("coor/z", 180);
	setup();
	replace_program(ROOM);
}
