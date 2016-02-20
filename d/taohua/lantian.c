// Room: /d/taohua/lantian.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
inherit ROOM;
 
void create()
{
	set("short", "蓝天");
	set("long",@LONG
四周是蓝蓝的天，洁白的云在飘；地上的行人看起来象蚂蚁。哇......
好爽啊。你心中有一种感觉：君临天下一览人间小！
LONG);   
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	set("coor/x", 9000);
	set("coor/y", -3000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
