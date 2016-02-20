// Room: /yangzhou/shuixie.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","花界水榭");
	set("long",@LONG
玲珑花界水榭为面南一楹，方形，花脊，歇山板瓦顶，南设台阶，
北置平台，并设白石栏板。上悬著名书法家欧阳中石手书匾。两柱悬挂
宋之问卢照邻集句楹联(lian)。坐栏观景，熙春台、望春楼、二十四桥
诸胜尽收眼底。面南两柱悬挂王维李端集句楹联(lian1)。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIR"
        花        楼
        柳        台
        含        绕
        丹        曲
        日        池
\n"NOR,
		"lian1" : HIG"
        红        碧
        桃        石
        绿        青
        柳        苔
        垂        满
        檐        树
        向        荫
\n"NOR,
	]));
	set("exits", ([
		"northwest" : __DIR__"guanshaoting",
		"southeast" : __DIR__"lianxingsi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}