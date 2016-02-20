// /d/meizhuang/mishi2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "柳园");
	set("long", @LONG
这是一座小小的园子，里面种满了大大小小的柳树，柳枝有的长可
及地，有的还是新枝嫩叶，但中间有一株灌木(guanmu)低低矮矮的，长
在那里，非常惹人注目，你不禁朝那里多看了两眼。
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaoyuan",
	]));
	set("objects", ([
		__DIR__"obj/guanmu" : 1,
	]) );
	set("outdoors", "meizhuang");
	set("coor/x", 3520);
	set("coor/y", -1430);
	set("coor/z", 20);
	setup();
}
void reset()
{
	object *inv, con, item, guanmu;

	::reset();

	guanmu= present("guanmu", this_object());
	inv = all_inventory(guanmu);

	if( !sizeof(inv))
	{
		con = new(__DIR__"obj/honghua");
		item = new(NOSTRUM_DIR"zhuguo");
		item->move(con);
		con->move(guanmu);
	}
}
