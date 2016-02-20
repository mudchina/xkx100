//TOHSQ3.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
这里快接近谷低了，但北面瀑布挡住了去路。瀑布如一匹银练奔流
而下，倾泻在一深潭之中，水声轰鸣，帘雾直上重霄。两旁山石高耸，
陡壁断崖，象是人工劈就而成。深潭前的青石被磨得锃亮，好象总有人
在这里来往。
LONG );
	set("exits", ([
		"southeast" :__DIR__"tohsq2",
	]));

	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 890);
	set("coor/z", 50);
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	if(!arg)
	{
message_vision("$N一闭眼，向潭中跳了下去，只觉冰冷刺骨，赶紧运气相抗。\n",me);
		me->move("/d/mingjiao/hsqtan1");
		return notify_fail("\n");
	}
}


	