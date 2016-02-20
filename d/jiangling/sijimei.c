//Edited by fandog, 02/15/2000

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "四季美");
	set("long", @LONG
提起“四季美”江陵一带无人不知。这里各式菜肴均是武汉一绝。
南来北往的客人们都会来这里尝尝。整个大堂闹哄哄的，挤得满满登登。
店里的伙计跑来跑去，忙着招呼客人。墙上挂着价格牌子(paizi)。
LONG);
	set("exits", ([
		"west"  : __DIR__"hzjie1",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("item_desc", ([
		"paizi" : "
冬瓜鳖裙羹(Donggua)        ：五两白银
猴头芙蓉(Houtou)           ：五两白银
龙凤配(Longfeng)           ：五两白银
天麻银耳汤(Tianma soup)    ：五两白银
松子武昌鱼(Wuchang yu)     ：五两白银
香菇烧板栗(Xianggu banli)  ：五两白银
珍珠甲鱼汤(Zhenzhu soup)   ：五两白银\n",
        ]));

	set("coor/x", -1490);
	set("coor/y", -2100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}