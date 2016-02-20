// Room: /d/fuzhou/yongquan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "涌泉寺");
	set("long", @LONG
涌泉寺为闽中第一丛林。构筑宏伟，气势磅礴，工艺精巧，冠绝一
时。寺东胜境灵源深处，悬崖峭壁，峥嵘奇巧，古树参天，宁静幽雅，
其中千载碑林，多朱熹、蔡襄遗墨。寺北绝顶峰，远望东海烟波，近瞰
闽江流带，福州平原一派田园风光尽收眼底。
LONG );
	set("exits", ([
		"south"    : __DIR__"gushan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng" : 1,
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1890);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
