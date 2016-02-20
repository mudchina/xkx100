// Room: /yangzhou/wangchunlou.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","望春楼");
	set("long",@LONG
望春楼位于瘦西湖东岸，与熙春台隔湖相望。面西五楹，二层，七
架梁，歇山板瓦顶。楼上下皆为四面廊。下层南北两间作楼梯过道，分
别缀以水院、山庭，将山水景石引入室内。底层两侧山墙置木刻落地罩
门，雕刻松、竹、梅、兰纹饰。两柱悬挂韦庄和苏某人集句楹联(lian)。
楼四周为青砖铺砌露台，周以石栏。楼上栏板凿云月图案，云纹柱头，
楼头沿墙叠黄石山子。
LONG );
	set("item_desc", ([
		"lian" : HIM"
        才        更
        看        逢
        早        晴
        春        日
        莺        柳
        出        含
        谷        烟
\n"NOR,
	]));
	set("exits", ([
		"north" : __DIR__"changdi3",
		"east"  : __DIR__"baitaqingyun",
		"west"  : __DIR__"ershisiqiao",
		"up"    : __DIR__"wangchunlou2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}