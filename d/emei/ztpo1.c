//Room: ztpo1.c 钻天坡
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","钻天坡");
	set("long",@LONG
莲花石与洗象池之间，道路陡绝，石栈若齿，直上蓝天，石蹬达一千三百
多级，是在陡峭山壁上开凿出来的坡道。人行其上，前后顶踵相接，一如登天。
这段路叫「鹁鸽钻天」，这段陡坡也因此而叫「钻天坡」。这里西上坡顶便到
洗象池，东下可达莲花石。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"eastdown" : __DIR__"lianhuashi",
		"westup"   : __DIR__"ztpo2",  
	]));
	set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1080);
	set("coor/z", 110);
	setup();
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "westup" && userp(me))
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		if ( me->query("qi") < 10 ) me->unconcious();
		else
		{
			me->receive_damage("qi", 10);
			if (((c_skill*c_skill*c_skill/10)< c_exp) &&
				(c_skill < 101))
				me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			tell_object(me,"你在钻天坡往上爬了一阵，好累人。\n");
		}
	}
	return 1;
}

