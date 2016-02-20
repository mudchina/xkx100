// Room: /d/wizard/wizard_jail.c
// Last modified by winder 2002/10/18

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "天牢");
	set("long", @LONG
这里就是本泥潭的巫师监狱。这里南边有门，可四面无窗，被关在
这里的巫师，将被剥夺法力。既然在这里，你就什么也别想，还是静心
思过吧。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : "/d/death/god2",
	]));
	setup();
}

void init()
{
	object me = this_player();

	if(me->query("id") != "winder")
	{
		write(HIC"天牢"NOR
"这里就是本泥潭的巫师监狱。这里南边有门，可四面无窗，被关在
这里的巫师，将被剥夺法力。既然在这里，你就什么也别想，还是静心
思过吧。
    这里唯一的出口是 "HIW"south"NOR"。\n");
		me->set("startroom",base_name(environment(me)));
		add_action("block_cmd","",1);
	}
}

int block_cmd(string arg)
{
	if(arg != "l") return 1;
}

