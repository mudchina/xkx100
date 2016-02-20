// Room: /yangzhou/jicuixuan.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","积翠轩");
	set("long",@LONG
积翠轩，面南三楹，是一个曲廊、山石水池、花树翠竹组成精巧庭
院，上悬匾额，外柱悬挂集句楹联(lian)。东面是一道曲廊，曲廊南端
通半亭，亭名“半青”。过半亭达中院，南为“林香榭”，外柱悬挂楹
联(lian1) 。于榭前临水平台欣赏白塔丽姿，可得“白塔晴云”命意旨
趣。北为“花南水北之堂”，外柱悬挂李峤、许浑集诗楹联(lian2)。
两堂以廊相连。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        垒        当
        石        轩
        通        暗
        溪        绿
        水        筠
\n"NOR,
		"lian1" : HIG"
        名        仙
        园        塔
        依        俪
        绿        云
        水        庄
\n"NOR,
		"lian2" : HIG"
        别        前
        业        轩
        临        枕
        青        大
        甸        河
\n"NOR,
	]));
	set("exits", ([
		"northwest" : __DIR__"baitaqingyun",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}