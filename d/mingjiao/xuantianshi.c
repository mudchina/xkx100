// Room: /d/mingjiao/xuantianshi.c


inherit ROOM;

void create()
{
	set("short", "悬天石");
	set("long", @LONG
从石上远眺，只见云海苍茫处，险绝万峦生，昆仑一脉，逶迤千里，
真一派大好江山。关于悬天石，还有许多传说。相传明教第三十代教主
〖风舞柳影〗阿娜(Doll)为解明教之难，舍身于此，明教一代绝学“乾
坤大挪移”从此失传。许多后来之人于此凭吊，莫不泣泪，但更多的是
从此石跳下，想寻找“乾坤大挪移”秘籍，却从没有人能安然而归。
LONG );
	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));
	set("item_desc", ([
		"doll" : "一个来自波斯总教的教主。\n",
	]));
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 810);
	set("coor/z", 40);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
