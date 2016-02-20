// Room: /yangzhou/menting.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "门庭");
	set("long", @LONG
门庭北向，是一座高大的磨砖门楼，门楣上方嵌有「小玲珑山馆」
四字砖额。门内与穿廊相接，游廊逶迤北去，廊尽而门。
LONG );
	set("outdoors", "yangzhouw");
	set("no_fight", 1);

	set("exits", ([
		"north" : __DIR__"chuanlang",
		"east"  : __DIR__"caohenanjie",
	]));
	set("objects", ([
		__DIR__"npc/jiading2" : 2,
	]));
	set("coor/x", -11);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	if ( dir == "north" && !me->query_temp("enter_yang") 
		&& objectp( ob = present ( "jia ding", environment( me )  ) )
		&& living(ob) )
	{
		message_vision("家丁对$N说道：未经老爷邀请，你不能进去。\n",me);
		return notify_fail("你被家丁拦住了去路。\n");
	}
	return ::valid_leave(me, dir);
}