// Room: /d/tiezhang/wmfeng.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
void close_passage();
string look_bei();

void create()
{
	set("short", GRN"无名峰"NOR);
	set("long", @LONG
跨过路上的荆棘和荒草，你终于登上了无名峰的峰顶。由于这里地
处五峰之中，四周有其它山峰阻挡，因此风势很小，常年笼罩在一片云
雾之中。峰顶长满了齐腰的荒草，怪石嶙峋，一片荒凉景色。在峰顶的
正中，赫然矗立着一座岩石砌就的坟墓，坟墓的前面立着一块一人多高
的花岗岩的墓碑(bei)。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"hclu4",
	]));
	set("item_desc",([
		"bei" : (: look_bei :),
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2060);
	set("coor/y", -1860);
	set("coor/z", 80);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	object me=this_player();

	if ((int)this_player()->query_temp("marks/闹1")) 
	{
		if ( (int)me->query_str() < 30)
			return notify_fail("你的力量不够，无法将石碑推开。\n");
		if (arg !="bei") 
			return notify_fail("你要推什么？？\n");
		write("你扎下马步，深深的吸了口气，将墓碑缓缓的向旁推开。\n");
		message("vision", me->name() + "双膀用力，将墓碑向旁缓缓推开，下面露出一个黑洞洞的入口。\n", environment(me), ({me}) );
		set("exits/enter", __DIR__"shijie1");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
		return 1;
	}
	return notify_fail("你有病呀！没事推墓碑做什么？？\n");
}

void close_passage()
{
	object room;

	if( !query("exits/enter") ) return;
	message("vision", "墓碑发出隆隆的声音，缓缓移回原处。\n", this_object() );
	delete("exits/enter");
}

string look_bei()
{
    return
    "\n"
 "*****************\n"
 "*           铁  *\n"
 "*           掌  *\n"
 "*           帮  *\n"
 "*       上  第  *\n"
 "*           十  *\n"
 "*       官  三  *\n"
 "*           代  *\n"
 "*       剑  帮  *\n"
 "*           主  *\n"
 "*   不  南      *\n"
 "*   肖          *\n"
 "*   弟          *\n"
 "*   子  之      *\n"
 "*   裘  墓      *\n"
 "*   千          *\n"
 "*   仞          *\n"
 "*   谨          *\n"
 "*   立          *\n"
 "*****************\n";
    "\n";
}