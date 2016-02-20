// Room: /d/lingxiao/yudong.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","玉洞");
	set("long",@LONG 
如果说外面的冰洞象梦幻的世界一样，那么，这里就是真正的天堂。
整个洞内，无论洞壁洞顶，全是墨绿的玉石。玉质温润细滑，竟是和田
之玉。就算在权贵之家，和田玉也是了不起的财富。一块手掌般大的和
田玉，就够一户中等人家过上一辈子。但是，这里最吸引人的，还是中
间的玉台(table)上天然所生的一块珠子，它散发出幽幽光泽，照的满
室皆绿。
LONG);
	set("had_yujing", 1);
	set("exits",([ /* sizeof() == 1 */
		"out" : __DIR__"wave", 
	])); 
	set("item_desc", ([
		"table" : "这是一整块玉天然行成的玉台，玉中呈现出奇怪的图形。
上面天然生出的一块珠子(zhuzi)。\n",
		"zhuzi": "这是一块玉珠，它散发出幽幽光泽，照的满室皆绿。\n",
	]));
	
	set("coor/x", -31040);
	set("coor/y", -8950);
	set("coor/z", 100);
	set("no_clean_up", 0);
	setup();
}

void init()
{	
	add_action("do_take", "take");
	add_action("do_take", "qu");
	add_action("do_take", "jian");
	add_action("do_take", "pick");
}

int do_take(string arg)
{
	object baoyu, me=this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="zhuzi" )
	{
		if (query("had_yujing"))
		{
			
			message_vision("$N轻轻的从石台上捡起块玉来。\n", me);
			baoyu = new(__DIR__"obj/yujing");
			baoyu->move(me);
message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"得了冰魄玉精啦。\n"NOR, users());
			set("had_yujing", 0);
			return 1;
		}		
		message_vision(
"$N伸手去取，才发现冰雕的玉石立刻化成一滩水，冰魄玉精早就被别人取走了...。\n", me);
		return 1;
	}
	return 0;
}
