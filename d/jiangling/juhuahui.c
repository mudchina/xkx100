//Edited by fandog, 01/31/2000
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "菊花会");
	set ("long","正是菊花盛开时节，这里摆放了各处的名贵菊花。黄菊有"HIY"都胜、金
芍药、黄鹤翎、报君知、御袍黄、金孔雀、侧金盏、莺羽黄"NOR"。白菊有"HIW"月
下白、玉牡丹、玉宝相、玉玲珑、一团雪、貂蝉拜月、太液莲"NOR"。紫菊有
"MAG"碧江霞、双飞燕、翦霞绡、紫玉莲、紫霞杯、玛瑙盘、紫罗撒"NOR"。红菊有
"HIR"美人红、海云红、醉贵妃、绣芙蓉、胭脂香、锦荔枝、鹤顶红"NOR"。淡红色
的有"HIM"佛见笑、红粉团、桃花菊、西施粉、胜绯桃、玉楼春"NOR"。只可惜没有
"HIG"绿菊"NOR"。\n");
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
		__DIR__"npc/lingshuanghua" : 1,
                "/clone/medicine/vegetable/jugeng" : random(2),
	]));

	set("exits", ([ 
		"east" : __DIR__"hzjie3",
	]));
  
	set("coor/x", -1510);
	set("coor/y", -2120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
