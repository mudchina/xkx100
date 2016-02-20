// Room: /yangzhou/xiangfenpu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","戴记香粉铺");
	set("long",@LONG
「天下香料，莫如扬州」，这里便是扬州香粉铺子中最好的一家「
戴春林」香粉铺。一进入铺子，一种混杂的香气扑鼻而来。铺子边上摆
着几面镜子，中间是一红木柜台。几个年轻女子正在试用粉饼胭脂，另
有几个老妈子正在和伙计商量着什么。随着你进来，一个伙计缓缓的站
起身来。
LONG );
	set("exits", ([
		"north" : __DIR__"dashidongjie",
	]));
	set("objects", ([
		__DIR__"npc/daichunlin" : 1,
	]));
	set("coor/x", 60);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}