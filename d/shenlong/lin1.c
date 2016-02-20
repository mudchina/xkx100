// /d/shenlong/lin1.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;
string* npcs = ({
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/fushe",
});
 
void create()
{
	set("short", "灌木林");
	set("long",@LONG
峰顶北坡是一片阴郁潮湿的灌木林，小路隐没在罐木林中。你对这
样一个孤岛上竟有这样大一片灌木林(bush)感到非常吃惊。四周的密林
中长满了不知名的杂草。
LONG);
	set("exits", ([
		"southup" : __DIR__"fengding",
	]));
	set("item_desc", ([
		"bush" : "这片灌木林太深了，要想过去恐怕只有砍出一条路了(kan)。\n",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 1+random(2),
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]) );
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan ( string arg )
{
	object ob, weapon, me = this_player();
	string dir;

	if( !arg || arg !="bush" ) return notify_fail("你要砍什么？\n" ) ;
	if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("不用武器恐怕不行吧！\n");
	message_vision("$N抽出兵刃，对着灌木丛一阵乱砍。\n", me);
	if(me->query("neili")>100)
	{
		set("exits/north", __DIR__"lin2");
		message_vision( "$N累得气喘吁吁，终于砍出一条小路。\n", me);
		me->add("neili",-50);
		remove_call_out("close");
		call_out("close", 20, this_object());
	}
	else	
	{
		message_vision("$N累得气喘吁吁，也没砍开一条路来。\n", me);
		me->set("neili",0);
	}
	return 1;
}

void close(object room)
{
	message("vision","灌木丛渐渐合拢起来，终于又恢复了原状。\n", room);
	room->delete("exits/north");
}
