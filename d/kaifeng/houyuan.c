// /kaifeng/houyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
后院之中绿荫如云。许多树木下设有石凳，供人休息。正中的一个
大铁香炉中香烟袅袅，许愿的人们多有在此磕头。东面是藏经楼。西面
是千手千眼佛殿。北面是八宝琉璃殿。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"qianshou",
		"east" : __DIR__"cangjing1",
		"north" : __DIR__"8bao",
		"south" : __DIR__"daxiong",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
