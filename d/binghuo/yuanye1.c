// Room: /binghuo/yuanye1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "原野");
	set("long", @LONG
这里是一片空旷的原野。满地都是不知名的野草，平整如茵。草
丛之中常有小兽出没，见人不惊。西南是一片大树林，北面一片开阔
地，连往远处的火山口。
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"southwest"  : __DIR__"shulin3",
		"southeast"  : __DIR__"caodi2",
		"northeast"  : __DIR__"shulin4",
		"north"      : __DIR__"yuanye2",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
	]));
	setup();
	replace_program(ROOM);
}

