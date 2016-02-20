// Room: /d/nanshaolin/sengshe1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "东僧舍");
	set("long", @LONG
这里是僧舍待客的地方，靠墙左右两侧摆着一溜太师椅。墙角一几，
放着几个茶壶。有个茶壶壶身上题了“碧螺春”三个篆字，壶嘴热气腾
腾，似乎是刚沏的新茶。一位小沙弥在一边垂手站立。
LONG );
	set("exits", ([
		"west"  : __DIR__"celang2",
		"south" : __DIR__"sengshe3",
		"north" : __DIR__"sengshe2",
	]));
	set("objects", ([
		__DIR__"npc/xiao-ku" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

