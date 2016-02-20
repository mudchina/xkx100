// Room: /yangzhou/pingyuanlou.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","平远楼");
	set("long",@LONG
平远楼共三层，取宋代画家郭熙《山水训》“自近山而望远山，谓
之平远”之意，命名平远楼。楼前庭院古木参天，花木繁多，湖石花台
正中植一株古琼花。楼内中堂为“琼花图”，两壁楹联(lian)。楼前东
南隅有“印心石屋”碑一座。后门向北庭院内，湖石花坛盛栽牡丹，东
角丛植芭蕉，西墙披挂木香，卵石铺地，庭院虽小，壶天自春。
LONG );
	set("item_desc", ([
		"lian" : "
        三级曩增高，两点金焦，助起杯中吟兴

        双峰今耸秀，万株松栝，涌来槛外涛声
\n",
	]));
	set("exits", ([
		"west"  : __DIR__"yongdao",
		"north" : __DIR__"qingkongge",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}