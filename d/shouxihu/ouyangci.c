// Room: /yangzhou/ouyangci.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","欧阳祠");
	set("long",@LONG
欧阳祠又名欧阳文忠公祠，位于谷林堂后，为纪念欧阳修知扬州之
政德而建。光绪间，两淮盐运使欧阳正墉集资重建，并题书“六一宗风”
匾，薛时雨撰楹联(lian)。欧阳修别号“六一居士”，因其自谓家藏书
一万卷，集录三代以来金石遗文一千卷，有琴一张，棋一局，常置酒一
壶，加上自己老于此五物之间一老翁，是为“六一”，故欧阳祠又称六
一祠。
    祠中后壁嵌有欧阳修画像刻石，画像传神，胡须部分刀法精巧，形
成光线折射，产生远看为白，近看为黑的视觉效果，常使游人称奇。
谊。
LONG );
	set("item_desc", ([
		"lian" : "
        遗构溯欧阳，公为文章道德之宗，侑客传花，也自徜徉诗酒
        名区冠淮海，我从丰乐醉翁而至，携云载鹤，更教旷览江山
\n",
	]));
	set("exits", ([
		"south" : __DIR__"gulintang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}