// Room: /yanziwu/ganquanjie.c
// Date: Jan.28 2000 by Winder

inherit ROOM;
void create()
{
	set("short","甘泉街");
	set("long",@LONG
甘泉街原本是扬州最繁华的街道之一，由于小秦淮河东岸的扬州新
城的扩建，商家多搬去新城了，甘泉街才冷清许多，也干净许多。在新
城未建之前，甘泉街南北两面尽是茶肆酒楼，各色店铺。店家纷纷侵街
搭设凉棚，摆设花木，装饰店面，造成街道拥挤不堪，河对面的漕运署
官员的车马无法通行，所以特建新城，把店铺挪至对岸。北面是扬州最
著名的酒楼，阵阵肉香酒香让你垂涎欲滴。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"kedian",
		"north" : __DIR__"zuixianlou",
		"east"  : __DIR__"ninghaiqiao",
		"west"  : __DIR__"shilijie4",
	]));
	set("objects", ([
		CLASS_D("baituo")+"/ouyangke" :1,
	]));
	set("coor/x", 20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}