// Room: /d/taiwan/danshui.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "淡水");
	set("long", @LONG
淡水，位于台湾岛西北隅，濒临台湾海峡，正居台湾第三大河之淡
水河出海口北岸，东南方耸立大屯山系，南面隔河对著观音山。淡水之
美深具水乡情调，有“东方那波里”之称，汉人的市街沿河而建，后转
筑于山坡，斜道起落，梯回阶转之间，极富曲巷幽思。居高眺望河港，
更为美妙，小镇灯火、下弦之月、飘摇风帆，加上粼粼波光，淡水风光，
其实何止于此！
LONG );
	set("exits", ([
		"east"      : __DIR__"jilonggang",
		"north"     : __DIR__"hongmaocheng",
		"southwest" : __DIR__"zhuqian",
	]));
	set("objects", ([
		__DIR__"npc/pingpu_kdgl": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2540);
	set("coor/y", -6970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

