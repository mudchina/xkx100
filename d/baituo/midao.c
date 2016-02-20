// Room: /d/baituo/midao.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","密道");
	set("long", @LONG
这里是漆黑的密道，当年白驼山弟子为了直达中原而挖凿的。
LONG	);
	set("exits" , ([
		"east" : "/d/city/ganquanjie",
	]));
	set("objects",([
		__DIR__"obj/shenshe" : 1 ,
	]));
	set("coor/x", -50020);
	set("coor/y", 20060);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_get", "get");
}
int do_get(string arg)
{

	object me = this_player();
	object ob;
	if ((arg != "shenshe") || !arg)
		return notify_fail("你要拿什么？\n");
	if(!objectp(ob=present("shenshe",environment(me))))
		return notify_fail("这里没有「引路神蛇」.\n");
	if(me->query("family/family_name") != "白驼山派")
		return notify_fail("这是只有白驼山派弟子才能使唤的「引路神蛇」。\n");
	ob->move(me);
	message_vision("$N拿起「引路神蛇」揣在怀里。\n",me);
	return 1;
}
