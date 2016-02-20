// Last Modified by Sir on 9/17/2001
// wg_guanmen.c

inherit ROOM;

void create()
{
	set("short", "武馆大门");
	set("long", @LONG
这里是一个大宅子，门口高悬一个大匾“扬州武馆”，立了两个石
狮，你从大门口瞧进去，好象里面人来人往，都很繁忙的样子，门口站
着两个门卫，神情威严。
LONG);
	set("exits", ([
		"enter" : __DIR__"wg_dayuan",
		"west" : "/d/city/shilijie7",
	]));	
	set("objects", ([
		__DIR__"npc/wg_menwei" : 2,
	]));
	set("coor/x", 11);
	set("outdoors", "wuguan");
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "west" )
	{
		if(me->query("combat_exp") > 50000)
		{
			if(present("men wei", environment(me)) &&
				living(present("men wei", environment(me))))
			{
				return notify_fail("武馆门卫喝道：本馆只收留江湖新手，这位" + RANK_D->query_respect(me) + "请止步。\n");
			}
			else return ::valid_leave(me, dir);
		}
		else return ::valid_leave(me, dir);		
	}
	else return ::valid_leave(me, dir);
}

