//Room: jsjdg3.c 九十九道拐
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","九十九道拐");
	set("long",@LONG
这是著名的「九十九道拐」，道路纡曲陡竖，千折百回。据说过去曾有个
百余岁的疯僧至此，见一巨蟒挡路，便念咒驱蟒。但人们得知此处有巨蟒出没
后，便再也无人敢碰这里的草木，并以「龙居」名之。由此东可至千佛庵，西
达九老洞。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"northeast" : __DIR__"jsjdg2",
		"westup"    : __DIR__"jsjdg4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6160);
	set("coor/y", -1080);
	set("coor/z", 90);
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
			tell_object(me,"你沿九十九道拐又向上爬了一阵，觉得好累。\n");
		}
	}
	return 1;
}
