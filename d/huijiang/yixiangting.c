// Room: /d/huijiang/yixiangting.c
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","忆香亭");
	set("long",@LONG
这是一个精巧别致的小亭，上书“忆香亭”三个字，清秀挺拔宛然
便是陈家洛的手笔。旁边几行小字写的是：“碧亦有时灭，血亦有时灭，
一缕香魂无断绝！是耶非耶？化为蝴蝶。”陈家洛心中想念香香公主的
时候，常一个人来此独坐。
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"east" : __DIR__"zoulang2",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/chen-jialuo" : 1,
		__DIR__"obj/xiangcha" : 2,
		__DIR__"obj/dianxin" : 1,
	]));
	set("coor/x", -50080);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	tell_object(me,	"                         ");
	tell_object(me,	YEL"┌───┐\n"NOR);
	tell_object(me,	"                         ");
	tell_object(me, YEL"│"NOR);
	tell_object(me, HIG"忆香亭"NOR);  
	tell_object(me, YEL"│\n"NOR);
	tell_object(me,	"                         ");
	tell_object(me,	YEL"└───┘\n"NOR);
}
