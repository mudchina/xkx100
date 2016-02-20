// /d/meizhuang/senlin7.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "百木园");
	set("long", @LONG
这里是梅庄的百木园，你一走到这里，就象走到了一个连绵无尽的
小森林一样，这里无数的松树，柏树，白杨，还有很多叫不出来名字的
异种苗木，你走在其中，只想把这片树林尽情的欣赏一遍，永不出去才
好。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"senlin"+(random(8)+1),
		"west"  : __DIR__"senlin"+(random(8)+1),
		"south" : __DIR__"senlin"+(random(8)+1),
		"north" : __DIR__"senlin"+(random(8)+1),
	]));
	set("outdoors", "meizhuang");
	set("coor/x", 3500);
	set("coor/y", -1420);
	set("coor/z", 10);
	setup();
}

void init()
{
	object ob = this_player(), room = this_object();
	mapping fam;
	int i = random(2);

	if( i == 0) return;
	if (ob->query("id") == "jia ding" || !living(ob)) return;
	room->delete("exits");

	if ( (fam = ob->query("family")) &&
		fam["family_name"] == "黑木崖" &&
		ob->query("guilty") != 1 )
		ob->set("guilty",3);
	ob->set("startroom", "/d/meizhuang/jianyu");
	message_vision(HIR "\n$N脚下一滑，全身都埋进了厚厚的松针中！
$N只觉得天旋地转，呼吸也开始困难起来。\n\n" NOR, ob);
	message_vision(HIR "\n$N几乎就晕了过去......\n\n" NOR, ob);
	call_out("trapping", 20, ob, room);
}

void trapping(object ob, object room)
{
	if ( !living(ob) ) return;

	message_vision(HIY "\n家丁们把$N一把抓住，捆了个结实，扔进了监狱。\n\n\n" NOR, ob);
	ob->move(__DIR__"jianyu");
	room->set("exits/south", __DIR__"senlin"+(random(8)+3));
	room->set("exits/north", __DIR__"senlin"+(random(8)+3));
	room->set("exits/east",  __DIR__"senlin"+(random(8)+3));
	room->set("exits/west",  __DIR__"senlin"+(random(8)+3));
}
