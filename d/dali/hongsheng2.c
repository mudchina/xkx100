//Room: /d/dali/hongsheng2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","宏圣寺塔");
	set("long",@LONG
这里是宏圣寺塔内部，四面墙壁上都辟有佛龛，龛内置佛像。
抬头上望，可以看到中心柱、葫芦顶、伞盖、相轮及莲花座托等。
伞盖成八角形，角上挂有风铎。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "down"   : __DIR__"hongsheng1",
	    "up"     : __DIR__"hongsheng3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -55900);
	set("coor/z", 10);
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
                        if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<
101))
                 	me->improve_skill("dodge", (int)me->query_skill("dodge",1));
                        tell_object(me,"你爬上一层楼，有些累了。\n");
                }
	}
	return 1;
}
