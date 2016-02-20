// Room: /yangzhou/baitaqingyun.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","白塔晴云");
	set("long",@LONG
白塔晴云，位于莲花桥北岸西侧，与白塔隔湖相望。清乾隆按察使
衔程扬宗、扬州同知吴辅椿先后营构。白塔晴云面湖而筑，“别业临青
甸，前轩枕大河”。园门面东，上嵌“白塔晴云”石额。堂后庭院种植
琼花、广玉兰、春梅、山茶、枇杷等四季花木，西院栽竹千竿，开门通
望春楼。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northeast" : __DIR__"shuiyun",
		"southeast" : __DIR__"jicuixuan",
		"west"      : __DIR__"wangchunlou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}