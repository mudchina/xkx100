// Room: /d/nanyang/zhengdian.c
// Last Modified by winder on Nov. 20 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",RED "正殿" NOR);
	set("long",@LONG
正殿面阔三间，青石为墙，黑瓦覆顶，显出一派简朴的风格，殿内
正中供着一尊诸葛武侯彩像，手握羽扇，微捻胡须，神态端然自如；两
侧墙壁上题着不少诗篇词赋，大都笔法刚劲，挥毫洒脱，显然是出自一
些胸怀大志的壮男儿之手。
LONG);
	set("exits",([
		"south" : __DIR__"wuhouci",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
