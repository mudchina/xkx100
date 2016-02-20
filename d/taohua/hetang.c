// Room: /d/taohua/hetang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_ride();

void create()
{
	set("short", "荷塘");
	set("long", @LONG
曲曲折折的转出竹林，眼前出现一大片荷塘。塘中白莲盛放，清香
阵阵，莲叶田田，一条小石堤穿过荷塘中央，北面穿过方厅通向后面一
座精舍，南面是一片竹林。塘边有一对白雕(diao)正自嬉戏，形体特是
雄壮。
LONG
	);
	set("exits",([
		"north" : __DIR__"dating",
		"south" : __DIR__"jicui",
	]) );
	set("item_desc", ([
		"diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，\n"
		"骑上(ride)就可以飞到中原。\n",
	]));
	set("no_clean_up",0);
	set("outdoors","taohua");
	set("coor/x", 9010);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_ride", "ride");
}
int do_ride()
{
	mapping myfam;
	object ob = this_player();
	myfam = (mapping)ob->query("family");
	if(!myfam || myfam["family_name"] != "桃花岛")
	{
		message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然猛然一颠......\n"HIR"结果$N摔了个鼻青脸肿！\n"NOR"看来白雕对$N并不感兴趣，它只认识桃花岛的弟子。\n",ob);
		ob->receive_damage("qi",50);
		ob->receive_wound("qi",50);
		return 1;
	}
	if( (int)query("sb_ride") ) 
		return notify_fail("现在白雕正忙着，请过一会再乘坐。\n" ) ;
	add("sb_ride",1) ;
	message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然展翅高飞。\n\n但看一雕一人身形渐渐缩小，终至不见。\n" , ob );
	ob->move("/d/taohua/lantian") ;
	tell_object(ob,CYN"\n你不断地飞呀飞，万水千山身下飘过 ......\n\n" NOR);
	call_out("taohua", 3 , ob );
	add("sb_ride",-1) ;
	return 1 ;
}
void taohua( object ob )
{
	tell_object(ob, "你终于飞到了中原，白雕落了下来。\n\n"  ) ;
	ob -> move ("/d/guiyun/dayuan");
}
