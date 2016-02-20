// Room: /d/quanzhou/wangzhouting.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "望州亭");
	set("long", @LONG
这里的地势豁然开朗，有三块巨石如三条大蟒伸头出洞，故称「蟒
石」。蟒首向前探望，似乎也在鉴赏下界的美景。石上一亭突兀，如飞
来神笔，又称「飞来亭」。凭栏远望，泉州全景，尽收眼底。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu4",
		"northdown" : __DIR__"ruixiangyan",
	]));
	set("coor/x", 1850);
	set("coor/y", -6440);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
