// Room: /yangzhou/zhuqidian.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","竹器店");
	set("long",@LONG
「竹不产于扬州，扬州制品最精」，这家竹器店出售扬州精工巧匠
精心雕刻编制的竹器、木器。左墙倚墙码着竹篮、竹篓、竹罩等平民百
姓的日常用品，中间的柜台摆着笔架、笔筒及小的竹木饰物。右墙挂着
几幅空白扇面。看到你的到来，一个年轻伙计笑嘻嘻的迎了上来。
LONG );
	set("exits", ([
		"north" : __DIR__"matou",
	]));
	set("objects", ([
		__DIR__"npc/liusanshun" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}