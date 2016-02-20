//Room: /d/dali/hongsheng1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","塔基");
	set("long",@LONG
宏圣寺塔基座系用石板砌成，与千寻塔基为砖砌不同。基座西
面有塔门，可入内攀登而上。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "out"    : __DIR__"hongsheng",
	    "up"     : __DIR__"hongsheng2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -55900);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	if (dir == "up" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		if ( me->query("qi") < 20 )
			me->unconcious();
		else
		{
			me->add("qi", -20);
			if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
				me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			tell_object(me,"你爬上一层楼，有些累了。\n");
		}
	}
	return 1;
}
