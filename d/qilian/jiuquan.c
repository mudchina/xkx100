// Room: /d/qilian/jiuquan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "酒泉");
	set("long", @LONG
相传这里就是汉大将军霍去病大破楼兰后犒军之地，武帝赠御酒二
十瓶，霍不忍独享，尽倾于十泉内，与三军共饮。后闻以酒泉之水酿酒，
香馥可口。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"shalu2",
		"southwest" : __DIR__"loulan",
	]));
	set("coor/x", -20200);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}