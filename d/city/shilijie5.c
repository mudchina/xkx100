// Room: /yangzhou/shiliji5.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里长街");
	set("long",@LONG
十里长街原本是扬州的中心，繁华之至。街边茶肆酒楼林立，店铺
面街开店，热闹非凡，每当夜市来临时，店家高挂灯笼，尽夜喧哗，灯
火不绝。杜牧曾描绘到：“每重城向夕，常有绛纱灯万数，辉煌罗列空
中。”现在街边的店铺多搬至新城，十里长街的繁荣教往昔已逊色许多，
但做为进出扬州的要道，依旧行人拥挤，车马如流。街西是一家钱庄，
可以听到叮叮当当的金银声音。东边连着秦淮客寓。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"qianzhuang",
		"east"  : __DIR__"kedian",
		"south" : __DIR__"shilijie6",
		"north" : __DIR__"shilijie4",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}