// /kaifeng/paifang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "牌坊");
	set("long", @LONG
穿过一道照壁，走上一条青石小道，眼前不远就是一道牌坊。通用
红漆过了一边，看不出原来的底色，倒是跟关帝爷的脸色很像，北面闹
轰轰的是座戏楼，东面就是关帝庙。
LONG
	);
	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : __DIR__"xilou",
		"east" : __DIR__"guandi",
		"west" : __DIR__"huiguan",
	]));
	set("objects", ([
		__DIR__"npc/huizhang" : 1,
		__DIR__"npc/pihuoshang" : 1,
	]));

	setup();
	replace_program(ROOM);
}
