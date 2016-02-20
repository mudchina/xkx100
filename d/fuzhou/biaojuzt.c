// Room: /d/fuzhou/biaojuzt.c
// Date: may.12 1998 Java

inherit ROOM;

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是福威镖局的正厅，几只太师椅一字排开，正中央坐着总镖头，
手持烟袋杆正在闭目沉思。墙上挂着几幅字画和一把宝剑。
LONG );
	set("exits", ([
		"north" : __DIR__"biaojuhy",
		"south" : __DIR__"biaojudy",
		"west"  : __DIR__"biaojunz",
		"east"  : __DIR__"biaojuzf",
	]));
	set("objects", ([
		__DIR__"npc/linzhennan" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6297);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
