// Room: /d/lingxiao/jiugu.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","绝谷");
	set("long",@LONG
还好，你运气好，从万丈深渊上摔下来，居然摔到厚厚的雪堆上，
不但没断腿少胳膊，连皮都没伤到一点。但是，到了这绝谷之下，如何
上去呢？攀攀(pan)看呢？
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
	]));
	set("coor/x", -31000);
	set("coor/y", -8980);
	set("coor/z", 60);
	set("no_clean_up", 0);
	setup();
} 
void init()
{
	add_action("do_pan","pan");
}
int do_pan()
{
	object me = this_player();
	message("vision", me->name() + "手脚并用，猫着腰往上爬。\n", environment(me), ({me}) );
	me->move(__DIR__"shiya");
	message("vision", me->name() + "从石崖下猫着腰爬了上来。\n", environment(me), ({me}) );
	return 1;
}

