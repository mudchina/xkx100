// /d/shenlong/datingkou 大厅口
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
});

void create()
{
	set("short", "大厅口");
	set("long", @LONG
这是大厅的门口，向内可进入神龙教的大厅，门口站着许多神龙教
的教徒，全副武装，警惕地注视四周，从厅内依稀传来一个浑厚的声音，
似乎里面正在召开什么重要会议。
LONG
	);
	set("valid_startroom",1);
	set("outdoors", "shenlong");
	set("exits", ([
		"west"  : __DIR__"changlang",
		"enter" : __DIR__"dating",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/first" : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]));
	setup();
	"/clone/board/shenlong_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping myfam = (mapping)me->query("family");
	object *inv;
	int haveguarder;

	if( !(me->query("sg/spy") ||
		me->query("family/family_name") == "神龙教") &&
		dir == "enter" )
	{
		inv = all_inventory(this_object());
		for(int i = 0; i < sizeof(inv); i++ )
			if( inv[i]->query("family/family_name") == "神龙教" ||
				inv[i]->query("sg/spy") )
			{
				 haveguarder++;
				 if( living(inv[i]) ) inv[i]->kill_ob(me);
			}
		if( haveguarder > 0 )
			return notify_fail("你也太目中无人了吧，这儿还有人守着呢。\n");
	 }

	 return ::valid_leave(me, dir);
}

