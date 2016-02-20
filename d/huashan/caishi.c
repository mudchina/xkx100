// caishi.c
// Last Modified by winder on Aug. 1 2002

#include <ansi.h>
inherit ROOM;

int do_cai(string arg);

void create()
{
	set("short", "采石场");
	set("long", @LONG
这里是位于华山脚下的采石场，一群群人不停地来回穿梭忙碌着，
累得满头大汗，远处有个大柜台，一个老板模样的人坐在台前，仔细的
打着算盘给人结帐，身边围了一些人。
LONG);
	set("exits", ([
		"north" : __DIR__"path1",
	]));
	set("objects",([
		__DIR__"npc/zhanggui":1,
	]));
	set("coor/x", -920);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_cai","cai");
}

int do_cai(string arg)
{
	int i;
	object weapon,me = this_player();
	if (!arg || (arg != "stone" && arg != "石头"))
		return notify_fail("你要采什么？\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("name") != "铁锤")
		return notify_fail(RED"你手都磨破了，却什么也没做成。\n"NOR);
	if (me->query_temp("caishi/count")<1)
		return notify_fail("这里不关你的事，还是走远点吧！\n");
	if (me->query_temp("caishi/count")>4) 
	{
		me->set_temp("caishi/finish",1);
		return notify_fail("你已经采得差不多了，该向老板交工了！\n");
	}
	if (me->query("qi")<30)
		return notify_fail("你快支持不住了，先歇会儿吧！\n");
	if (me->is_busy()) return notify_fail ("（你上个动作还没完成，不能进行下一个动作！）\n");
	me->add("qi",-15);
	me->add_temp("caishi/count",1);
	i=random(4);
	message_vision(YEL"$N举起铁锤，对准石头狠狠地砸了下去。\n"NOR,me);
	if (i<1)
		tell_object(me,"你用力过猛，震得虎口发麻，险些摔了一交。\n");
	else if (i==2) tell_object(me, "你狠狠一锤，腾腾腾倒退了几步，差点没站稳。\n");
	else tell_object(me, "你用力一锤砸下，“喀”地应声落下一块石头来。\n");
	me->start_busy(1);
	return 1;
}
