// Room: /d/chengdu/qianzhuang.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "川号钱庄");
	set("long", @LONG
这里是城里最有名的钱庄：川号钱庄，利息虽低但决不拖欠。听说
主人是青城俗家弟子，曾经在川中横行数世，流氓土匪一般都不来这找
麻烦。所以这里一向是生意很好。
LONG	);
	set("exits", ([ 
		"east" : __DIR__"chunxilu2",
	]) );
	set("objects", ([
		__DIR__"npc/boss3" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	tell_object(this_player(),WHT "你拍了拍口袋，叹了口气，走出了钱庄。\n"NOR,this_player());
	return 1;
}
