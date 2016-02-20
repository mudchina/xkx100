// Room: /yangzhou/kedian.c
// Last Modified by Winder on Jul. 15 2000
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", YEL"秦淮客寓"NOR);
	set("long", @LONG
这里是秦淮客寓，过往扬州的客商大多在此歇脚。客寓内摆设很简
单，边上一个柜台，柜台后有一个帐房先生正在拨着算盘珠子，一边还
拿枝笔记着什么。一个店小二看到你的到来，笑吟吟的迎上前来。边上
的楼梯前挂着个告示(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五十两白银。\n"+
"本店出售，投标：bid；预付金：deposit；定价：setprice;状态：status \n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/popo" : 1,
	]));
	set("exits", ([
		"up"    : __DIR__"kedian2",
		"east"  : __DIR__"majiu",
		"west"  : __DIR__"shilijie5",
		"north" : __DIR__"ganquanjie",
	]));

	set("coor/x", 20);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian_b"->foo();
	"clone/npc/xiang"->move(this_object());
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && ( dir == "west" || dir == "north"))
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
void init()
{
	object me=this_player();
	if (me->query("name")=="青云" && me->query("id")!="qingyun")
	  me->set("name","我是猪头");
}