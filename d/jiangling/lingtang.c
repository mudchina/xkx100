//Edited by fandog, 01/31/2000

inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short", "灵堂");
	set ("long", @LONG
这是一个灵堂，屋子里烛光耀眼。桌子上点燃着两根素烛，安放着
一块灵牌(Pai)。桌旁悬挂一匹素帏。
LONG);
	set("item_desc", ([
		"pai" : HIW"爱女凌霜华之灵位\n"NOR,
	]));
	set("exits", ([ 
		"south" : __DIR__"feiyuan",
		"west"  : __DIR__"zoulang",
		"east"  : __DIR__"yongdao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
