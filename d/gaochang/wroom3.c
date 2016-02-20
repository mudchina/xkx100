// Room: /d/gaochang/wroom3.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "西大殿");
	set("long", @LONG
每一间房中大都供有佛像。偶然在壁上见到几个汉文，写的是「高
昌国国王」，「文泰」，「大唐贞观十三年」等等字样。有一座殿堂中
供的都是汉人塑像，匾上写的是「大成至圣先师孔子位」，左右各有数
十人，写著「颜回」、「子路」、「子贡」、「子夏」、「子张」等名
字。
LONG
	);
	set("exits", ([
		"south" : __DIR__"wroom2",
		"northwest" : __DIR__"zoulangw",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36510);
	set("coor/y", 10070);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}