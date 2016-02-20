// Room: /d/nanshaolin/fzjs.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIG"方丈精舍"NOR);
	set("long", @LONG
这里的地上整整齐齐的排放着数十个黄布蒲团，北首有一个红木讲
坛，讲坛上放着个竹制的木鱼。东西边各放着一对美轮美奂的大花瓶，
上插檀香数枝，香烟缭绕，氤氲芬芳，室内一片祥和之气。看来这里是
方丈对僧众讲经说法的地方。
LONG );
	set("exits", ([
		"up"   : __DIR__"fzjs1",
		"east" : __DIR__"xiaolu7",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1780);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

