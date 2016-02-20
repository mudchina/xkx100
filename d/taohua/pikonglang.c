// Room: /d/taohua/pikonglang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "劈空栏");
	set("long", @LONG
这是一个里面廊窗的小阁。透过窗缝，可以看到南面的试剑峰。东
面望去，是白浪滔滔的大海，海面上白鸥自由飞来飞去，真是“天高任
鸟飞”啊。栏的一端摆着一张长桌，桌上放着一列烛台，点着一排的蜡
烛(lazhu)。
LONG
	);
        set("item_desc", ([ 
		"lazhu" : "蜡烛在海风中摇曳着一点昏黄的光，好象举手一拍(pai)就会灭的样子。\n",
	]));
        set("exits", ([ 
		"north" : __DIR__"zoulang4",
	]));
	set("outdoors","taohua");
	set("no_clean_up", 0);
	set("coor/x", 9020);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_pai", "pai");
}
int do_pai(string arg)
{       
        mapping fam;
	object me = this_player();

	if (arg != "lazhu")
		return notify_fail("你拍什么拍？拍蚊子啊？\n");
	if (!living(me)) return 0;
	if (!(fam = me->query("family")) || fam["family_name"] != "桃花岛")
		return notify_fail("你非本岛弟子，不能在此练功！\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("你挥掌向着烛台虚劈，嗤的一声，烛火应手而灭。\n");
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("挥掌向着烛台虚劈，结果烛火连晃都没晃一晃！\n");
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	write( "挥掌向着烛台虚劈，嗤的一声，烛火摇摇晃晃居然没灭！\n");
	return 1;
}