// Room: /d/huangshan/feilai.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "飞来石");
	set("long", @LONG
在平坦的山面之上，突然冒出一块石头，似乎除了飞来一说，别的
实在难以解释。石面光滑，上书三字“飞来石”，远看石头，上粗下细，
好象摇晃不止，实在令人匪夷所思。
LONG
	);
	set("exits", ([ 
		"east"  : __DIR__"guangming",
		"north" : __DIR__"paiyun",
	]));
	set("item_desc", ([
		"飞来石": "你可以试着推一推（push）\n",
		"stone" : "你可以试着推一推（push）\n"
	]) );
	set("outdoors", "huangshan");
	setup();
}
void init()
{
	add_action("do_push","push");
}
int do_push()
{
	object me = this_player();
	me->receive_damage("qi", 30);
	message_vision("$N用尽全身力气，用力推了推飞来石，飞来石似乎晃了晃！\n",me);
	return 1;
}
