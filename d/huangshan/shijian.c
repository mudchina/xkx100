// Room: /d/huangshan/shijian.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "试剑石");
	set("long", @LONG
一块巨大的石头 （stone），孤处路中，中间一痕，深几近半，相
传这是一古代剑师试剑之处，铸剑千余，最后终于造出一把可以劈开此
石的剑，名为“苍穹神剑”，可惜剑师因心力憔悴而死。相传黄山剑庐
主人世代相传的便是此剑。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"zuishi",
	]));
	set("item_desc", ([
		"stone": "一块巨大的石头，中间一痕，裂缝深处似乎有一
东西闪闪发光。你似乎也可以在这里试一试（test）你的武器。\n"
	]) );
	set("outdoors", "huangshan");
	setup();
}
void init()
{
	add_action("do_test","test");
}
int do_test(string arg)
{
	object weapon, me = this_player();
	object piece;

	if(!arg ) return notify_fail("你要试一试你身上的哪样武器？\n");
	if(!(weapon = present(arg,me)))
		return notify_fail("你身上似乎没有这样东西！\n");
	if(!weapon->query("weapon_prop"))
		return notify_fail(weapon->name()+"似乎并不是一种武器！\n");
	if(!weapon->query("equipped"))
		return notify_fail("你并没有将"+weapon->name()+"握在手中。\n");
	message_vision("$N用尽全力，将手中的"+weapon->name()+"猛力向巨石挥去。。。。\n",me);
	weapon->unequip();
	weapon->set("weapon_prop",0);
	weapon->save();
	me->reset_action();
	message_vision("只听见”铛“的一声，$N手中的"+weapon->name()+"应声而断！\n",me);
	seteuid(getuid());
	piece = new("/clone/misc/piece");
	piece->set_name("断掉的" + weapon->query("name"),({weapon->query("id"),"piece"}));
	piece->move(this_player());
	destruct(weapon);
	if(random(500))
		tell_object(this_object(),"大石上的裂痕似乎又深了一些！\n");
	else
	{
		tell_object(this_object(),"一块黑黝黝的东西从石缝中掉了出来！\n");
		weapon = new(__DIR__"obj/banzhi");
		weapon->move(this_object());
	}
	me->start_busy(2);
	return 1;
}
