//room: /d/yanziwu/cuixia.c
inherit ROOM;

void create()
{
	set("short","翠霞堂");
	set("long",@LONG
古朴庄严，气度非凡，你一进门就不由的惊叹。好大一座厅堂！西
边仿佛有一间小厅，东边则是一片竹林，南面有一道穿堂，不知通向什
么地方。
LONG );
	set("exits",([
		"west" : __DIR__"xiaoting",
		"east" : __DIR__"zhulin1",
		"south": __DIR__"chuantang",
	]));
	set("objects",([
		CLASS_D("murong")+"/azhu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1500);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}