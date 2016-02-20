// /d/meizhuang/keting.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "迎客亭"); 
	set("long", @LONG
通过四雅清风，你来到了梅庄的迎客亭，这里虽然只有一张石桌几
个石凳，但却是一尘不染，石凳和石桌之间的空隙很大，显是方便来客
与主人相互寒暄。一位汉子正站在亭前，冲你拱手微笑。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"dating",
		"north" : __DIR__"senlin1",
	]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shi" : 1,
	]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"table": "一张很平常的石桌，但是......自己猜吧。\n"
	]) );

	set("coor/x", 3500);
	set("coor/y", -1410);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{
	string dir;
	object me=this_player();

	if( !arg || arg=="" )
	{
		write("你要往哪儿钻？\n");return 1;
	}
	if( arg=="table" )
	{
		write("你蹑手蹑脚的绕到石桌的后面，钻进了下面的一个小洞。\n");
		if((int)me->query_skill("dodge",1)>=30)
		{
			write( "你费尽九牛二虎之力，发现自己到了一个很神秘的地道里。\n");
			me->move(__DIR__"didao1");
			return 1;
		}
		write(RED"你试着钻了一下后面的一个小洞，发现钻不进去。\n"NOR);
		me->add("jing",-10);
		me->add("qi",-10);

		return 1;
	}
}
