// Room: /yangzhou/fengting.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "风亭");
	set("long", @LONG
风亭高处巅顶，为重檐四角亭，花岗岩石柱，板瓦顶，白石地坪，
井藻绘凤吹牡丹，四周画百鸟朝凤图案，檐间悬道光太傅阮元所题“风
亭”匾，两柱悬挂王茂如所撰楹联(lian)。上山沿岭脊两侧栽有百年古
柏数十株。登上此亭，南望市廛，北眺蜀冈，左右湖山尽收眼底。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"westdown"   : __DIR__"pingtai1",
		"southdown"  : __DIR__"yueguan",
	]));
	set("item_desc", ([
		"lian" : HIY"
        风        亭
        月        台
        无        依
        边        旧

        到        羡
        此        他
        胸        烟
        怀        水
        何        全
        似        收
\n"NOR,
	]));
	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 120);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}