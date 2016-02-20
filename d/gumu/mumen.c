// mumen.c 墓门
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
	set("short", "墓门");
	set("long", @LONG
你走过了草地，发现自己已身处深谷之中，雾气蒙蒙，寒意逼人。
四下是片不小的开阔地，突兀地耸立着一座一人高的白色球型圆冢，墓
上砌的石头已经班驳了，看的出来这是座古墓。墓前没有立碑，也没有
任何的标记。墓后是阴森森的松林古木，更平添十分凄清落寞的萧瑟之
意。墓门仅齐肩高，往内是古墓派所在。墓门口被一块黑黝黝的大石头
(shi)封闭得丝毫不透。
    古墓传人历来不轻出江湖，但不少痴情男女仰慕杨龙二人双剑合壁
快意江湖的豪情，历尽千般磨难后终成眷属惊世恋情。不远千里往来投
拜。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"east"  : __DIR__"xuanya",
		"west"  : __DIR__"huangshalin",
		"north" : __DIR__"caodi",
		"south" : __DIR__"mudao01",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : 1+random(3),
	]));
	set("item_desc", ([
		"shi": "这是块巨石，怕不有万斤上下，好象锩着‘"+YEL"降龙石"NOR+"’几个字。\n"
	]) );
	set("coor/x", -3220);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_move", "move");
	add_action("do_move", "luo");
	add_action("do_move", "tui");
}

int do_move(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "shi" )
	{
		return notify_fail("你要移动什么？\n");
	}
	if( !query("exits/south"))
	{
		return notify_fail("降龙石已经落下，你还能移动什么？\n");
	}
	if((int)me->query_str()>33)
	{
		message_vision("$N站在降龙石前，双掌发力推动降龙石，只听得降龙石吱吱连声，缓缓向下落去，封住了墓门。\n", me);
		delete("exits/south");
		if( !(room = find_object(__DIR__"mudao01")) )
			room = load_object(__DIR__"mudao01");
		room->delete("exits/north");
		tell_room(room,"只听得降龙石吱吱连声，缓缓向下落去，封住了墓门。\n");
	}
	else
		message_vision("$N试着推了推巨石，巨石纹丝不动，只得罢了。\n", this_player());
	return 1;
}

