// Room: /d/nanshaolin/sengshe4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西僧舍");
	set("long", @LONG
这里是僧舍中待客的地方，靠墙左右两侧摆着一溜太师椅。墙角一
几，放着几个茶壶。有个茶壶壶身上题了“碧螺春”三个篆字，壶嘴热
气腾腾，似乎是刚沏的新茶。
LONG );
	set("exits", ([
		"east"  : __DIR__"celang1",
		"south" : __DIR__"sengshe6",
		"north" : __DIR__"sengshe5",
	]));
	set("resource/water",1);
	set("objects",([
		__DIR__"npc/xiao-tong" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

