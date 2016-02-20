// Room: /d/yanziwu/dukou.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "茶花渡");
	set("long", @LONG
这里是蔓陀山庄的茶花渡。山庄主王夫人平生挚爱茶花，可是却不
识货，虽然庄里茶花遍野，甚至不惜渡名茶花。不承望满庄茶花仍是株
株怀才不遇模样，没一枝长得精神点。
    由此可乘船离开蔓陀山庄。湖面正系着一尾小舟(zhou)。
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north"  : __DIR__"chalin6",
		"south"  : __DIR__"chalin7",
		"east"   : __DIR__"path1",
	]));
	set("objects", ([
		__DIR__"npc/xiaocui" : 1,
	]));
	set("item_desc", ([
		"zhou" : "这是蔓陀山庄和湖外联系的小舟。舟上一个绿衫少女。岛上的客人只要\n登舟(enter)就可以出湖了。\n",
	]));
	set("coor/x", 1200);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_enter", "enter");
}
int do_enter(string arg)
{
	object ob ;
	string dir;
	if( !arg || arg !="zhou" ) 
	{
		tell_object(this_player() , "你要投水？\n");
	 	return 1 ;
	}
	ob = this_player();
message_vision("船上一个秀美温柔的江南少女看到$N登舟，竹篙轻点，舟已
离岸，蔓陀山庄渐渐在视野里远去。\n", ob);
	ob ->move(__DIR__"taihu") ;
	tell_object(ob, HIG "你在湖上飘流，四周看不尽的江南美景。\n" NOR ) ;
	call_out("home", 10 , ob );
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "小舟终于恋恋不舍地靠岸了。你走下小舟来。少女挥手依依道别。\n" ) ;
	ob->move (__DIR__"hupan") ;
}
