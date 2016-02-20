// Room: /d/gaochang/shulin9.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "高昌迷宫");
	set("long", @LONG
这是条黑沈沈的长甬道，甬道前出现了三条岔道。迷宫之内并无足
迹指引，你不知道要往哪条路走。俯身细看，见左首，右首和前方三条
路上都有淡淡的足迹。你似乎迷失了方向，象没头苍蝇般到处乱闯。
LONG
	);

	set("outdoors", "gaochang");
        set("no_drop",1);
	set("exits", ([
		"east" : __DIR__"shulin"+(random(8)+6),
		"west" : __DIR__"shulin"+(random(8)+6),
		"south" : __DIR__"shulin"+(random(8)+6),
		"north" : __DIR__"shulin"+(random(8)+6),
	]));
	set("coor/x", -38000);
	set("coor/y", 11000);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob, room;
	mapping fam;

	int i = random(2);
	if( i == 0) return;

	ob = this_player();
	room = this_object();

	if (ob->query("id") == "gui" || !living(ob)) return;

	message_vision(HIR "\n$N一不小心，触动了迷宫的机关！
$N只听得头上一阵巨响，原来是头上一块巨石落下。\n\n" NOR, ob);

	message_vision(HIR "\n$N痛得几乎失去了知觉......\n\n" NOR, ob);

	if((int)ob->query("qi")<250) ob->die(); else ob->unconcious();
}