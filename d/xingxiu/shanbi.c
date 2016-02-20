// Room: /d/xingxiu/shanbi.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "山壁");
	set("long", @LONG
一条草草在山壁上人工开凿出来崎岖的小路，几个星宿弟子正在埋
头苦干。这里，寒风凛冽，西面是望浩浩百里方圆的星宿海。东边山壁
上，尽是星宿弟子用力砸出的坑凹(ao)。
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"xiaolu",
	]));
	set ("item_desc", ([
		"ao" : "是人用棍杖撞击(za)山壁(bi)留下的痕迹。\n"
	])) ;
	set("objects", ([
		__DIR__"npc/gushou"  : 1,
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -49900);
	set("coor/y", 20300);
	set("coor/z", 100);
	setup();
}

void init()
{
	add_action("do_za", "za");
}

int do_za(string arg)
{
	object  weapon, me = this_player();
	int ging_cost, qi_cost, jingli_cost;
	weapon = me->query_temp("weapon");
	ging_cost = 150 / (int)me->query("int");
	qi_cost = 200 / (int)me->query("con");
 
	if (!living(me)) return 0;
	if ( arg != "bi" ) return notify_fail("你要撞击什麽？\n");
	if (!weapon) return notify_fail("你用什么砸山壁来练功？\n");  
	if (weapon->query("skill_type") == "staff")
		if ((int)me->query_skill("staff", 1) >= 120) 
			return notify_fail("你已经不用再在这里费功夫了。\n");  
	if(weapon->query("skill_type") == "hammer")
		if ((int)me->query_skill("hammer", 1) >= 120) 
			return notify_fail("你已经不用再在这里费功夫了。\n");  
	if (random((int)me->query("kar")) < 3 )
	{
		message_vision("$N一不小心砸到自己脚上，痛得晕了过去。\n",me);
		me->unconcious();
		return 1;
	}
	if((me->query("jing") < ging_cost) || (me->query("qi") < qi_cost))
	{
		message_vision("$N猛地砸在山壁上，结果用力过度！\n", me);
		me->unconcious();
		return 1;
	}
	message_vision("$N使劲撞击山壁，在山壁上砸出一个坑凹。\n", me);
	if(weapon->query("skill_type") == "staff")
		me->improve_skill("staff", me->query_skill("staff", 1));
	else if(weapon->query("skill_type") == "hammer")
	me->improve_skill("hammer", me->query_skill("hammer", 1));
	me->receive_damage("jing", ging_cost );
	me->receive_damage("qi", qi_cost );
	return 1;     
}
