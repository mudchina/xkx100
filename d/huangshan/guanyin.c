// Room: /d/huangshan/guanyin.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "观音石");
	set("long", @LONG
由半山寺上来，过云门到天都峰下，看到一个亭亭玉立的石人，活
象一尊古装仕女，人称观音石。正面一块小石，恰如跪拜之童子，这“
小甚侏儒大娉婷”的两块巧石，正好构成“童子拜观音”。从这里便开
始了“盘空千万仞，险若上丹梯。迥入天都里，回看鸟道低”的登顶过
程。
LONG
	);
	set("exits", ([ 
		"southdown"  : __DIR__"banshan",
		"northup"    : __DIR__"yingke",
		"east"       : __DIR__"jiyu",
	]));
	set("objects", ([
		__DIR__"obj/guanyin" : 1,
		__DIR__"obj/xiaotong" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
