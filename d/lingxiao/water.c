// Room: /d/lingxiao/water.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
int do_dive(string arg);
void create()
{
	set("short", "雪山温泉");
	set("long", @LONG
这里是两个山道盆地之间，有一股喷泉正在嘶嘶喷水，灼热的水花
被风吹散，在月光下形成一团团白色的花环。在这雪山之上，居然还有
此等令人惬意之处，亦不由让人感叹造物之神奇。碧波绿水中，飘荡着
朵朵雪莲花瓣，片片雪花飘然而下，离水面有数寸，便即纷纷化为白雾
而散。在这生命绝迹的大雪山之上，惟有这里，才有绿树、红花、青草。
一个少女在温泉畔凝望落花，似有无限心事。
LONG );
	set("resource/water", 1);
	set("objects", ([
		__DIR__"npc/a-xiu" : 1,
	]) ); 
	set("resource/water", 1);
	set("exits", ([ 
		"east" :__DIR__"sroad6",
	]));
	set("coor/x", -31010);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup(); 
} 
void init()
{       
	add_action("do_dive","dive");
}
int do_dive(string arg)
{
	object me = this_player();

	if ((arg !="lake" || !arg))
		return notify_fail("你要潜什么？\n");
	if ((int)me->query_skill("force") < 100 )
	{ 
		message_vision("$N刚下水不久，就发现愈往下潜，水压愈大，忍了一会，\n终于再也忍受不住，猛地窜了上来。\n", me);
	} 
	else 
	{
		message_vision("$N鼓足勇气，往下潜去，只觉压力越来越大，$N强运内力，奋力支持，向下潜去，\n只听水中哗啦一声，就平静下来了。\n", me); 
		me->move(__DIR__"wave1"); 
	} 
	return 1;
}

