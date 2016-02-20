// Room: /d/yanziwu/jinfeng.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "金风庄");
	set("long", @LONG
这里是金风庄。庄上庄主就是包三先生了。不过太庄主却另有其人，
想知道是谁，就请进去看看。
    庄外湖面正系着一尾小舟(zhou)。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west"  : __DIR__"guifang",
	]));
	set("objects", ([
		CLASS_D("murong")+"/bao" : 1,
	]));
	set("item_desc", ([
		"zhou" : "这是金风庄和外界联系的小舟。舟上一个绿衫少女。岛上的客人只要\n登舟(enter)就可以离开了。\n",
	]));
	set("coor/x", 750);
	set("coor/y", -1550);
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
离岸，金风庄渐渐在视野里远去。\n", ob);
	ob ->move(__DIR__"taihu") ;
	tell_object(ob, HIG "你在湖上飘流，四周看不尽的江南美景。\n" NOR ) ;
	call_out("home", 10 , ob );
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "小舟终于恋恋不舍地靠岸了。你走下小舟来。少女挥手依依道别。\n" ) ;
	ob->move (__DIR__"muti") ;
}
