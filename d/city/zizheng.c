// Room: /d/city/zizheng.c
// Last Modified by winder on Apr. 10 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "资政书院");
	set("long", @LONG
资政书院是扬州官办的书院，扬州人大多把小孩送此处读书识字。
进入书院，院内一大院子，中间湖石堆了一个假山，几个学童在假山爬
来穿去，边上搭一秋千，几个女学童在耍秋千玩，两边各有一小竹棚，
下摆几张木桌，一个学童躺在桌上，枕着书似乎在睡觉。北向石阶上有
间堂屋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"caohebeijie",
		"north" : __DIR__"tangwu2",
		"south" : __DIR__"zhonglieci",
	]));
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/lixiaoqi" : 1,
		__DIR__"npc/kongxiaotian" : 1,
		__DIR__"npc/guyueer" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
