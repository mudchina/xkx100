// Room: /d/nanshaolin/lhtang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"罗汉堂"NOR);
	set("long", @LONG
你面前是一座很大的院落，周围用高墙围住，院门匾额上写着『罗
汉堂』三个大字。这里是少林弟子练习本门基本武功的所在。有很多年
轻的僧人进进出出，院内传来阵阵呼喝练功的声音。
LONG );
	set("exits", ([
		"east" : __DIR__"stoneroad4",
		"west" : __DIR__"lwc1",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		CLASS_D("nanshaolin")+"/daji" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
}
void init()
{ 
	add_action("do_jump","zong");
}
int do_jump(string arg)
{ 
	object me = this_player();   
	if (arg!="bian") return 0;  
	if(me->query_skill("dodge",1)<130)  
		return notify_fail("你功力不够，跳不上匾额。\n");  
	message("vision",me->name()+"凝气守中，平空拔起数丈，轻轻落在匾额之后。\n",this_object());
	me->move(__DIR__"bianhou");
	me->set_temp("baitie",1);  return 1; 
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "南少林派") && dir == "west" &&
		objectp(present("xuanku dashi", environment(me))))
		return notify_fail("大疾大师喝道：罗汉堂乃本派弟子习武之处，你非本派弟子，不能入内。\n");
	return ::valid_leave(me, dir);
}
 
