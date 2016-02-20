// Room: /yangzhou/guanshaoting.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","观芍亭");
	set("long",@LONG
玲珑花娇为芍药牡丹园，取“洛阳牡丹，扬州芍药”之意。为瘦西
湖南岸，莲性寺与熙春台之间，由观芍亭经由曲廊连接水榭。相传为乾
隆观赏芍药处。观芍亭单檐方形，立于花坛之中，上悬郑板桥墨迹“观
芍亭”匾，两柱悬挂鲍照谢眺集句楹联(lian)。亭中顶棚为芍药彩绘。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIR"
        繁        红
        华        药
        及        当
        春        阶
        媚        翻
\n"NOR,
	]));
	set("exits", ([
		"northwest" : __DIR__"chongyanting",
		"southeast" : __DIR__"shuixie",
	]));
	set("objects", ([
		"/d/village/npc/kid" : 3,
	]));
	set("coor/x", -40);
	set("coor/y", 80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}