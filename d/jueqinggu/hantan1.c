// Room: /d/jueqinggu/hantan1.c
// Last Modified by winder on Feb. 17 2001
 
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "寒潭");
	set("long", @LONG
四周蓝森森的都是玄冰，冰冷的潭水，让人感到透骨的寒冷。远处
有一丝的亮光。
LONG
	);
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", -50);
	setup();
}
void init()
{
	add_action("do_fu", "fu");
	add_action("do_qian", "qian");
}
int do_fu(string arg)
{
	object me = this_player();

	if( !arg || arg == "" || arg !=  "up") return 0;
  
	message_vision("$N一个狗刨，浮了上去。\n", me);
	me->move(__DIR__"gudi1");
	tell_room(environment(me),me->name()+"湿淋淋地从潭中钻了出来。\n",({me}));
	return 1;
	
}
int do_qian(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "liang guang" && arg != "亮光") return 0;
	if ( !arg ) return 0;
	if (!living(me)) return 0;
	message_vision("$N向着亮光游了过去，越潜越深，过不多时，“波”的一响，冲出了水面。\n", me);
	me->move(__DIR__"gudi2");
	tell_room(environment(me), me->name()+"从潭水中冒了出来。\n", ({ me }));
	return 1;
}
