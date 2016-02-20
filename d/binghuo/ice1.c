// Room: /binghuo/ice1.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "冰山");
	set("long", @LONG
眼前银光闪烁，大冰山在月光下发出青紫色的光芒，显得又是奇
丽，又是可怖。你站在冰山之侧的一块棱角上，一眼望去，这座冰山
有陆地上一个小山丘大小，横广二十余丈，纵长八九丈，比原来的座
船宽敞得多了。远近都是大大小小的冰山(ice)。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("item_desc", ([
		"ice" : "那是又一座冰山，好象相距不远耶。何不跳过去看看？\n",
	]));
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"north" : __FILE__,
		"south" : __FILE__,
	]));
	set("objects", ([
		__DIR__"npc/haibao" : random(2),
	]));
	setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me = this_player();
	if ((!arg) || (arg != "east" && arg != "west" && arg != "south" && arg != "north"))
	{
		return notify_fail("东西南北都有冰山，你往哪跳？\n");
	}
	else
	{
		switch (random(5))
		{
			case 0:
tell_object(me , BLU"冰山向北飘浮了。白天银冰反射阳光，炙得人皮肤也焦了，眼
目更是红肿发痛。\n" NOR) ;
				break;
			case 1:
tell_object(me , BLU"冰山向北飘浮了。说也奇怪，越是北行，白天越长，到后来每
天几乎有十一个时辰是白日，黑夜却是一晃即过。\n" NOR) ;
				break;
			case 2:
tell_object(me , BLU
"便在此时，眼前一"WHT"亮"BLU"，北方映出一片奇异莫可名状的光彩，无
数奇丽绝伦的光色，在黑暗中忽伸忽缩，大片"YEL"橙黄"BLU"之中夹着丝
丝"MAG"淡紫"BLU"，忽而"MAG"紫色"BLU"愈深愈长，"MAG"紫色"BLU"之中，迸射出一条条"HIY"金光"BLU"、
"HIB"蓝光"BLU"、"HIG"绿光"BLU"、"HIR"红光"BLU"。\n" NOR) ;
				break;
			case 3:
tell_object(me , BLU"你眼望西天，血红的夕阳仍未落入海面。原来地近北极，天时
大变，这些地方半年中白日不尽，另外半年却是长夜漫漫，种
种怪异，宛若到了世界的尽头。\n" NOR) ;
				break;
			case 4:
tell_object(me , BLU"忽见到正北方一缕黑烟冲天而起，你登时吓得脸都白了，但黑
烟越来越高，到后来竟隐隐见烟中夹有火光。你颤声道：“这
……这是地狱门！”\n" NOR) ;
				break;
		}
		me->move(__DIR__"ice"+(random(9)+1));
	}
}
int valid_leave(object me, string dir)
{
	tell_object(me , 
"你在冰山上走来走去。\n" NOR) ;
	return ::valid_leave(me, dir);
}

