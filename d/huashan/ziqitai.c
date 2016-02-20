// Roon: ziqitai.c
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short", "紫气台");
	set("long", @LONG
紫气台终年云遮雾掩，迷蒙不见天日，更为怪异的是：每逢下雨天，
山谷之中就隐隐有紫气出现。
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"eastdown": __DIR__"chaopath2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -870);
	set("coor/y", 220);
	set("coor/z", 130);
	setup();
}
void init()
{
	object me = this_player();

	if (me->query_dex() > 40)
		this_object()->set("exits/down", "/d/jinshe/shanbi");
	else this_object()->delete("exits/down");
	remove_call_out("close");
	call_out("close", 5, this_object());
	return;
}
void close(object room)
{
	this_object()->delete("exits/down");
	return;
}
